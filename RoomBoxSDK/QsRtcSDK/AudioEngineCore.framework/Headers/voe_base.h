/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

// This sub-API supports the following functionalities:
//
//  - Enables full duplex VoIP sessions via RTP using G.711 (mu-Law or A-Law).
//  - Initialization and termination.
//  - Trace information on text files or via callbacks.
//  - Multi-channel support (mixing, sending to multiple destinations etc.).
//
// To support other codecs than G.711, the VoECodec sub-API must be utilized.
//
// Usage example, omitting error checking:
//
//  using namespace webrtc;
//  VoiceEngine* voe = VoiceEngine::Create();
//  VoEBase* base = VoEBase::GetInterface(voe);
//  base->Init();
//  int ch = base->CreateChannel();
//  base->StartPlayout(ch);
//  ...
//  base->DeleteChannel(ch);
//  base->Terminate();
//  base->Release();
//  VoiceEngine::Delete(voe);
//
#ifndef WEBRTC_VOICE_ENGINE_VOE_BASE_H
#define WEBRTC_VOICE_ENGINE_VOE_BASE_H

#include "common_types_refactor.h"
#pragma GCC visibility push(default)

#include "voice_engine_media_process.h"

namespace webrtc {

//// VoEMediaProcess
// class VoiceEngineMediaProcess {
// public:
//  // The VoiceEngine user should override the Process() method in a
//  // derived class. Process() will be called when audio is ready to
//  // be processed. The audio can be accessed in several different modes
//  // given by the |type| parameter. The function should modify the
//  // original data and ensure that it is copied back to the |audio10ms|
//  // array. The number of samples in the frame cannot be changed.
//  // The sampling frequency will depend upon the codec used.
//  // If |isStereo| is true, audio10ms will contain 16-bit PCM data
//  // samples in interleaved stereo format (L0,R0,L1,R1,...).
//  virtual void Process(const int channel,
//                       const ProcessingTypes type,
//                       int16_t audio10ms[],
//                       const int length,
//                       const int samplingFreq,
//                       const bool isStereo) = 0;
//
// protected:
//  virtual ~VoiceEngineMediaProcess() {}
//};

// VoiceEngineObserver
class WEBRTC_DLLEXPORT VoiceEngineObserver {
 public:
  // This method will be called after the occurrence of any runtime error
  // code, or warning notification, when the observer interface has been
  // installed using VoEBase::RegisterVoiceEngineObserver().
  virtual void CallbackOnError(int channel,
                               int errCode) = 0;  // AudioDevice channelId:1001
  virtual void CallbackOnVoiceStatus(bool voiceStatus){}  // true:��ʾ������״̬ false:��ʾ������״̬
 protected:
  virtual ~VoiceEngineObserver() {}
};

// VoiceEngine
class WEBRTC_DLLEXPORT VoiceEngine {
 public:
  // Creates a VoiceEngine object, which can then be used to acquire
  // sub-APIs. Returns NULL on failure.

  static VoiceEngine* Create();

  // Deletes a created VoiceEngine object and releases the utilized resources.
  // Note that if there are outstanding references held via other interfaces,
  // the voice engine instance will not actually be deleted until those
  // references have been released.
  static bool Delete(VoiceEngine*& voiceEngine);

  static int SetJavaClass(void* contextClass,
                          void* buildinfoClass,
                          void* managerClass,
                          void* recordClass,
                          void* trackClass);

  static int JvmInit(void* jvm, void* ctx);

  // static bool TestRelease();
  // Specifies the amount and type of trace information which will be
  // created by the VoiceEngine.
  static int SetTraceFilter(unsigned int filter);

  // Sets the name of the trace file and enables non-encrypted trace messages.
  static int SetTraceFile(const char* fileNameUTF8,
                          bool addFileCounter = false);

  // Installs the TraceCallback implementation to ensure that the user
  // receives callbacks for generated trace messages.
  static int SetTraceCallback(TraceCallback* callback);

  static std::string GetVersionString();

 protected:
  VoiceEngine() {}
  ~VoiceEngine() {}
};

// VoEBase
class WEBRTC_DLLEXPORT VoEBase {
 public:
  // Factory for the VoEBase sub-API. Increases an internal reference
  // counter if successful. Returns NULL if the API is not supported or if
  // construction fails.
  static VoEBase* GetInterface(VoiceEngine* voiceEngine);

  // Releases the VoEBase sub-API and decreases an internal reference
  // counter. Returns the new reference count. This value should be zero
  // for all sub-APIs before the VoiceEngine object can be safely deleted.
  virtual int Release() = 0;

  // Installs the observer class to enable runtime error control and
  // warning notifications. Returns -1 in case of an error, 0 otherwise.
  virtual int RegisterVoiceEngineObserver(VoiceEngineObserver& observer) = 0;

  // Removes and disables the observer class for runtime error control
  // and warning notifications. Returns 0.
  virtual int DeRegisterVoiceEngineObserver() = 0;

  // Initializes all common parts of the VoiceEngine; e.g. all
  // encoders/decoders, the sound card and core receiving components.
  // This method also makes it possible to install some user-defined external
  // modules:
  // - The Audio Device Module (ADM) which implements all the audio layer
  // functionality in a separate (reference counted) module.
  // - The AudioProcessing module handles capture-side processing.
  // - An AudioDecoderFactory - used to create audio decoders.
  // If NULL is passed for either of ADM or AudioDecoderFactory, VoiceEngine
  // will create its own. Returns -1 in case of an error, 0 otherwise.
  // TODO(ajm): Remove default NULLs.
  virtual int Init_Refactor() = 0;

  // Terminates all VoiceEngine functions and releases allocated resources.
  // Returns 0.
  virtual int Terminate() = 0;

  // Creates a new channel and allocates the required resources for it.
  // The second version accepts a |config| struct which includes an Audio Coding
  // Module config and an option to enable voice pacing. Note that the
  // decoder_factory member of the ACM config will be ignored (the decoder
  // factory set through Init() will always be used).
  // Returns channel ID or -1 in case of an error.
  virtual int CreateChannel() = 0;

  // Deletes an existing channel and releases the utilized resources.
  // Returns -1 in case of an error, 0 otherwise.
  virtual int DeleteChannel(int channel) = 0;

  // Prepares and initiates the VoiceEngine for reception of
  // incoming RTP/RTCP packets on the specified |channel|.
  virtual int StartReceive(int channel) = 0;

  // Stops receiving incoming RTP/RTCP packets on the specified |channel|.
  virtual int StopReceive(int channel) { return 0; }

  // Starts forwarding the packets to the mixer/soundcard for a
  // specified |channel|.
  virtual int StartPlayout(int channel) = 0;

  // Stops forwarding the packets to the mixer/soundcard for a
  // specified |channel|.
  virtual int StopPlayout(int channel) = 0;

  // Starts sending packets to an already specified IP address and
  // port number for a specified |channel|.
  virtual int StartSendVOIP(int channel) = 0;
  //virtual int StartSendRef(bool enable) = 0; //grace test
  // Stops sending packets from a specified |channel|.
  virtual int StopSendVOIP(int channel) = 0;

  //20210531 Split Share Audio interface
  //begin
  virtual int StartSendShareAudio(int channel) = 0;

  virtual int StopSendShareAudio(int channel) = 0;
  //end

  // Gets the version information for VoiceEngine and its components.
  virtual int GetVersion(char version[1024]) = 0;

  // Gets the last VoiceEngine error code.
  virtual int LastError() = 0;

  // Associate a send channel to a receive channel.
  // Used for obtaining RTT for a receive-only channel.
  // One should be careful not to crate a circular association, e.g.,
  // 1 <- 2 <- 1.
  virtual int AssociateSendChannel(int channel, int accociate_send_channel) = 0;

  // AudioDeviceModule Interface
  virtual int SetLoudspeakerStatus(bool enable) = 0;

  virtual int GetLoudspeakerStatus(bool& enabled) = 0;

  virtual int IncomingPhoneCallStatusChanged(bool state) = 0;

  virtual int CheckAudioDeviceUsable() = 0;

  // Mutes the microphone input signal completely without affecting
  // the audio device volume.
  virtual int SetInputMute(int channel, bool enable) = 0;

  // Sets a volume |scaling| applied to the outgoing signal of a specific
  // channel. Valid scale range is [0.0, 10.0].
  virtual int SetChannelOutputVolumeScaling(int channel, float scaling) = 0;

  // AudioProcessing Interface
  // Sets Noise Suppression (NS) status and mode.
  // The NS reduces noise in the microphone signal.
  virtual int SetNsStatus(bool enable, webrtc::NoiseSuppressionLevel level) = 0;

  // Sets the Automatic Gain Control (AGC) status and mode.
  // The AGC adjusts the microphone signal to an appropriate level.
  virtual int SetAgcStatus(bool enable, webrtc::GainControlMode mode) = 0;

  // Sets the Echo Control (EC) status and mode.
  // The EC mitigates acoustic echo where a user can hear their own
  // speech repeated back due to an acoustic coupling between the
  // speaker and the microphone at the remote end.
  virtual int SetEcStatus(bool enable, webrtc::ECSuppressionLevel level) = 0;

  virtual int SetDelayOffsetMs(int offset) = 0;

  virtual int EnableDriftCompensation(bool enable) = 0;

  virtual int RegisterExternalMediaProcessing(
      int channel,
      VoiceEngineMediaProcessingTypes type,
      VoiceEngineMediaProcess& processObject) = 0;
  virtual int DeRegisterExternalMediaProcessing(
      int channel,
      VoiceEngineMediaProcessingTypes type) = 0;
  // Gets the number of audio devices available for recording.
  virtual int GetNumOfRecordingDevices(int& devices) = 0;

  // Gets the number of audio devices available for playout.
  virtual int GetNumOfPlayoutDevices(int& devices) = 0;

  // Gets the name of a specific recording device given by an |index|.
  // On Windows Vista/7, it also retrieves an additional unique ID
  // (GUID) for the recording device.
  virtual int GetRecordingDeviceName(int index,
                                     char strNameUTF8[128],
                                     char strGuidUTF8[128]) = 0;

  // Gets the name of a specific playout device given by an |index|.
  // On Windows Vista/7, it also retrieves an additional unique ID
  // (GUID) for the playout device.
  virtual int GetPlayoutDeviceName(int index,
                                   char strNameUTF8[128],
                                   char strGuidUTF8[128]) = 0;

  // Sets the audio device used for recording.
  virtual int SetRecordingDevice(int index) = 0;

  // Sets the audio device used for playout.
  virtual int SetPlayoutDevice(int index) = 0;

  // Mutes the speaker device completely in the operating system.
  virtual int SetSystemOutputMute(bool enable) = 0;

  // Gets the output device mute state in the operating system.
  virtual int GetSystemOutputMute(bool& enabled) = 0;

  virtual int GetSpeechInputLevelFullRange(unsigned int& level) = 0;

  // Gets the speaker speech |level|, mapped linearly to the range [0,32768].
  virtual int GetSpeechOutputLevelFullRange(int channel,
                                            unsigned int& level) = 0;
  // Mutes the microphone device completely in the operating system.
  virtual int SetSystemInputMute(bool enable) = 0;

  // Gets the mute state of the input device in the operating system.
  virtual int GetSystemInputMute(bool& enabled) = 0;

  virtual int SetMicVolume(unsigned int volume) = 0;
  virtual int GetMicVolume(unsigned int& volume) = 0;
  virtual int SetSpeakerVolume(unsigned int volume) = 0;
  virtual int GetSpeakerVolume(unsigned int& volume) = 0;

  virtual int SetAgcTargetLevelDbfs(int level) = 0;
  virtual int EnableAecExtraFeature() = 0;

  // set Mirophone gain compensation
  virtual int SetMirophoneGainCompensation(int gain) = 0;  // gain[0:32]
  // set speaker gian compensation
  virtual int SetSpeakerGainCompensation(float gain) = 0;  // gain[0.00:1.00]
  // set audio configuration parameters
  virtual int SetAudioConfigParameters(char* paramaters) = 0;
  // Get volume db value
  virtual int GetAudioVolumeDB(int& local_vol_db, int& remote_vol_db) = 0;
  // Get Caton time
  virtual int GetAudioCatonTime(int channel, int& caton_time) = 0;

  virtual int SetPlayoutShareAudio(bool playout = false) = 0;
  virtual int GetPlayoutShareAudio(bool& playout) = 0;
  virtual int IsGetVoiceStatus(bool is_get_voice_status) = 0;
 protected:
  VoEBase() {}
  virtual ~VoEBase() {}
};

}  // namespace webrtc
#pragma GCC visibility pop
#endif  //  WEBRTC_VOICE_ENGINE_VOE_BASE_H
