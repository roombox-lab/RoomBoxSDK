#ifndef TANG_MEDIA_ENGINE_H
#define TANG_MEDIA_ENGINE_H
#if defined _WIN32 || defined __CYGWIN__
typedef unsigned __int8 uint8_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
#else
#include <stdint.h>
#endif

namespace tang {
namespace media {

class IAudioFrameObserver {
 public:
  enum AUDIO_FRAME_TYPE {
    FRAME_TYPE_PCM16 = 0,  // PCM 16bit little endian
  };
  /** Definition of AudioFrame */
  struct AudioFrame {
    AUDIO_FRAME_TYPE type;
    /** Number of samples in the audio frame: samples = (int)samplesPerCall = (int)(sampleRate &times; sampleInterval)
     */
    int samples;  //number of samples in this frame
    /** Number of bytes per audio sample. For example, each PCM audio sample usually takes up 16 bits (2 bytes).
     */
    int bytesPerSample;  //number of bytes per sample: 2 for PCM16
    /** Number of audio channels.
     - 1: Mono
     - 2: Stereo (the data is interleaved)
     */
    int channels;  //number of channels (data are interleaved if stereo)
    /** Audio frame sample rate: 8000, 16000, 32000, 44100, or 48000 Hz.
     * samplesPerCall = (int)(samplesPerSec &times; sampleInterval &times; numChannels), where sampleInterval &ge; 0.01 in seconds.
     */
    int samplesPerSec;  //sampling rate
    /** Audio frame data buffer. The valid data length is: samples &times; channels &times; bytesPerSample
     */
    void* buffer;  //data buffer
      /** The timestamp of the external audio frame. It is mandatory. You can use this parameter for the following purposes:
       - Restore the order of the captured audio frame.
       - Synchronize audio and video frames in video-related scenarios, including scenarios where external video sources are used.
       */
    int64_t renderTimeMs;
    int avsync_type;
  };

 public:
  /** Retrieves the recorded audio frame.

  The SDK triggers this callback once every 10 ms.

   @param audioFrame Pointer to AudioFrame.
   @return
   - true: Valid buffer in AudioFrame, and the recorded audio frame is sent out.
   - false: Invalid buffer in AudioFrame, and the recorded audio frame is discarded.
   */
  virtual bool onRecordAudioFrame(AudioFrame& audioFrame) = 0;
  /** Retrieves the audio playback frame every 10 ms for getting the audio.

   @param audioFrame Pointer to AudioFrame.
   @return
   - true: Valid buffer in AudioFrame, and the audio playback frame is sent out.
   - false: Invalid buffer in AudioFrame, and the audio playback frame is discarded.
   */
  virtual bool onPlaybackAudioFrame(AudioFrame& audioFrame) = 0;

  virtual bool onMixedAudioFrame(AudioFrame& audioFrame) { (void)audioFrame; return true; }
  virtual bool onPlaybackAudioFrameBeforeMixing(unsigned int uid, AudioFrame& audioFrame) {
	  (void)uid; (void)audioFrame; return true;
  }
};

class IVideoFrameObserver {
 public:
  enum VIDEO_FRAME_TYPE {
    FRAME_TYPE_YUV420 = 0,  // YUV 420 format
    FRAME_TYPE_RGBA = 2,    // RGBA format
  };
  /** Video frame information. The video data format is YUV420. The buffer provides a pointer to a pointer. The interface cannot modify the pointer of the buffer, but can modify the content of the buffer only.
   */
  struct VideoFrame {
    VIDEO_FRAME_TYPE type;
    /** Video pixel width.
     */
    int width;  //width of video frame
    /** Video pixel height.
     */
    int height;  //height of video frame
    /** Line span of the Y buffer within the YUV data.
     */
    int yStride;  //stride of Y data buffer
    /** Line span of the U buffer within the YUV data.
     */
    int uStride;  //stride of U data buffer
    /** Line span of the V buffer within the YUV data.
     */
    int vStride;  //stride of V data buffer
    /** Pointer to the Y buffer pointer within the YUV data.
     */
    void* yBuffer;  //Y data buffer
    /** Pointer to the U buffer pointer within the YUV data.
     */
    void* uBuffer;  //U data buffer
    /** Pointer to the V buffer pointer within the YUV data.
     */
    void* vBuffer;  //V data buffer
    /** Set the rotation of this frame before rendering the video. Supports 0, 90, 180, 270 degrees clockwise.
     */
    int rotation; // rotation of this frame (0, 90, 180, 270)
      /** The timestamp of the external audio frame. It is mandatory. You can use this parameter for the following purposes:
       - Restore the order of the captured audio frame.
       - Synchronize audio and video frames in video-related scenarios, including scenarios where external video sources are used.
     @note This timestamp is for rendering the video stream, and not for capturing the video stream.
     */
    int64_t renderTimeMs;
    int avsync_type;
  };

 public:
  /** Retrieves the camera captured image.

   @param videoFrame VideoFrame
   */
  virtual bool onCaptureVideoFrame(VideoFrame& videoFrame) = 0;
 
  /** Processes the received image of the specified user (post-processing).

   @param uid User ID of the specified user sending the image.
   @param videoFrame VideoFrame
   */
  virtual bool onRenderVideoFrame(unsigned int uid, VideoFrame& videoFrame) = 0;
};

enum VideoSourceFormat
{
	VideoPixelFormatI420 = 1,
	VideoPixelFormatBGRA = 2,
	VideoPixelFormatNV12 = 8,
	VideoPixelFormatNV21 = 16
};

class IVideoFrameConsumer
{
public:
	virtual void consumeVideoFrame(uint8_t* buffer, VideoSourceFormat format, int32_t width, int32_t height, int32_t rotation, uint64_t timestamp) = 0;
};

class IVideoSource
{
public:
	virtual bool onInitialize(IVideoFrameConsumer *consumer) = 0;
	virtual bool onStart() = 0;
	virtual void onStop() = 0;
	virtual void onDispose() = 0;
	virtual int  getBufferType() = 0;
};

/** The external video frame.
 */
struct ExternalVideoFrame
{
    /** The video buffer type.
     */
    enum VIDEO_BUFFER_TYPE
    {
        /** 1: The video buffer in the format of raw data.
         */
        VIDEO_BUFFER_RAW_DATA = 1,
    };

    /** The video pixel format.
     */
    enum VIDEO_PIXEL_FORMAT
    {
        /** 0: The video pixel format is unknown.
         */
        VIDEO_PIXEL_UNKNOWN = 0,
        /** 1: The video pixel format is I420.
         */
        VIDEO_PIXEL_I420 = 1,
        /** 2: The video pixel format is BGRA.
         */
        VIDEO_PIXEL_BGRA = 2,
        /** 8: The video pixel format is NV12.
         */
        VIDEO_PIXEL_NV12 = 8,
    };

    /** The buffer type. See #VIDEO_BUFFER_TYPE
     */
    VIDEO_BUFFER_TYPE type;
    /** The pixel format. See #VIDEO_PIXEL_FORMAT
     */
    VIDEO_PIXEL_FORMAT format;
    /** The video buffer.
     */
    void* buffer;
    /** Line spacing of the incoming video frame, which must be in pixels instead of bytes. For textures, it is the width of the texture.
     */
    int stride;
    /** Height of the incoming video frame.
     */
    int height;
    /** [Raw data related parameter] The number of pixels trimmed from the left. The default value is 0.
     */
    int cropLeft;
    /** [Raw data related parameter] The number of pixels trimmed from the top. The default value is 0.
     */
    int cropTop;
    /** [Raw data related parameter] The number of pixels trimmed from the right. The default value is 0.
     */
    int cropRight;
    /** [Raw data related parameter] The number of pixels trimmed from the bottom. The default value is 0.
     */
    int cropBottom;
    /** [Raw data related parameter] The clockwise rotation of the video frame. You can set the rotation angle as 0, 90, 180, or 270. The default value is 0.
     */
    int rotation;
    /** Timestamp of the incoming video frame (ms). An incorrect timestamp results in frame loss or unsynchronized audio and video.
     */
    long long timestamp;
};


class IMediaEngine {
 public:
  virtual void release() = 0;
  /** Registers an audio frame observer object.

   This method is used to register an audio frame observer object (register a callback). This method is required to register callbacks when the engine is required to provide an \ref IAudioFrameObserver::onRecordAudioFrame "onRecordAudioFrame" or \ref IAudioFrameObserver::onPlaybackAudioFrame "onPlaybackAudioFrame" callback.

   @param observer Audio frame observer object instance. If NULL is passed in, the registration is canceled.
   @return
   - 0: Success.
   - < 0: Failure.
   */
  virtual int registerAudioFrameObserver(IAudioFrameObserver* observer) = 0;
  /** Registers a video frame observer object.

   This method is required to register callbacks when the engine is required to provide an \ref IVideoFrameObserver::onCaptureVideoFrame "onCaptureVideoFrame" or \ref IVideoFrameObserver::onRenderVideoFrame "onRenderVideoFrame" callback.

   @param observer Video frame observer object instance. If NULL is passed in, the registration is canceled.
   @return
   - 0: Success.
   - < 0: Failure.
   */
  virtual int registerVideoFrameObserver(IVideoFrameObserver* observer) = 0;
  
  /** Pushes the external audio frame.

   @param frame Pointer to the audio frame: \ref IAudioFrameObserver::AudioFrame "AudioFrame".

   @return
   - 0: Success.
   - < 0: Failure.
   */
  virtual int pushAudioFrame(IAudioFrameObserver::AudioFrame* frame) = 0;

    /** Pushes the video frame using the \ref ExternalVideoFrame "ExternalVideoFrame" and passes the video frame to the Tang SDK.

     @param frame Video frame to be pushed. See \ref ExternalVideoFrame "ExternalVideoFrame".

     @note In the Communication profile, this method does not support video frames in the Texture format.

     @return
     - 0: Success.
     - < 0: Failure.
     */
    virtual int pushVideoFrame(ExternalVideoFrame *frame) = 0;

	//设置外部视频源
	virtual int setVideoSource(IVideoSource *source) = 0;

	/* cut the input frame to output width and height ratio, eg:output width:640, height:480, so ratio is 4:3 

	@param input video frame to be cutted

	@param output frame, buffer is supported by sdk, app should set the width and height need to be cutted

	@return
	- 0: Success.
	- < 0: Failure.
	*/
	virtual int ConvertToI420(IVideoFrameObserver::VideoFrame *input, IVideoFrameObserver::VideoFrame *output) = 0;
};

}  // namespace media

}  // namespace tang

#endif  // TANG_MEDIA_ENGINE_H
