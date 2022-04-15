/*
 * XDFIJKMediaFramework.h
 *
 * Copyright (c) 2013 Bilibili
 * Copyright (c) 2013 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#import <UIKit/UIKit.h>

//! Project version number for XDFIJKMediaFramework.
FOUNDATION_EXPORT double XDFIJKMediaFrameworkVersionNumber;

//! Project version string for XDFIJKMediaFramework.
FOUNDATION_EXPORT const unsigned char XDFIJKMediaFrameworkVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <XDFIJKMediaFrameworkWithSSL/PublicHeader.h>
#import <XDFIJKMediaFramework/XDFIJKMediaPlayback.h>
#import <XDFIJKMediaFramework/XDFIJKMPMoviePlayerController.h>
#import <XDFIJKMediaFramework/XDFIJKFFOptions.h>
#import <XDFIJKMediaFramework/XDFIJKFFMoviePlayerController.h>
#import <XDFIJKMediaFramework/XDFIJKAVMoviePlayerController.h>
#import <XDFIJKMediaFramework/XDFIJKMediaModule.h>
#import <XDFIJKMediaFramework/XDFIJKMediaPlayer.h>
#import <XDFIJKMediaFramework/XDFIJKNotificationManager.h>
#import <XDFIJKMediaFramework/XDFIJKKVOController.h>
#import <XDFIJKMediaFramework/XDFIJKSDLGLViewProtocol.h>

// backward compatible for old names
#define XDFIJKMediaPlaybackIsPreparedToPlayDidChangeNotification XDFIJKMPMediaPlaybackIsPreparedToPlayDidChangeNotification
#define XDFIJKMoviePlayerLoadStateDidChangeNotification XDFIJKMPMoviePlayerLoadStateDidChangeNotification
#define XDFIJKMoviePlayerPlaybackDidFinishNotification XDFIJKMPMoviePlayerPlaybackDidFinishNotification
#define XDFIJKMoviePlayerPlaybackDidFinishReasonUserInfoKey XDFIJKMPMoviePlayerPlaybackDidFinishReasonUserInfoKey
#define XDFIJKMoviePlayerPlaybackStateDidChangeNotification XDFIJKMPMoviePlayerPlaybackStateDidChangeNotification
#define XDFIJKMoviePlayerIsAirPlayVideoActiveDidChangeNotification XDFIJKMPMoviePlayerIsAirPlayVideoActiveDidChangeNotification
#define XDFIJKMoviePlayerVideoDecoderOpenNotification XDFIJKMPMoviePlayerVideoDecoderOpenNotification
#define XDFIJKMoviePlayerFirstVideoFrameRenderedNotification XDFIJKMPMoviePlayerFirstVideoFrameRenderedNotification
#define XDFIJKMoviePlayerFirstAudioFrameRenderedNotification XDFIJKMPMoviePlayerFirstAudioFrameRenderedNotification
#define XDFIJKMoviePlayerFirstAudioFrameDecodedNotification XDFIJKMPMoviePlayerFirstAudioFrameDecodedNotification
#define XDFIJKMoviePlayerFirstVideoFrameDecodedNotification XDFIJKMPMoviePlayerFirstVideoFrameDecodedNotification
#define XDFIJKMoviePlayerOpenInputNotification XDFIJKMPMoviePlayerOpenInputNotification
#define XDFIJKMoviePlayerFindStreamInfoNotification XDFIJKMPMoviePlayerFindStreamInfoNotification
#define XDFIJKMoviePlayerComponentOpenNotification XDFIJKMPMoviePlayerComponentOpenNotification

#define XDFIJKMPMoviePlayerAccurateSeekCompleteNotification XDFIJKMPMoviePlayerAccurateSeekCompleteNotification
#define XDFIJKMoviePlayerSeekAudioStartNotification XDFIJKMPMoviePlayerSeekAudioStartNotification
#define XDFIJKMoviePlayerSeekVideoStartNotification XDFIJKMPMoviePlayerSeekVideoStartNotification

#define XDFIJKMoviePlayerDidDecodeSEIInfoNotification XDFIJKMPMoviePlayerDidDecodeSEIInfoNotification
#define XDFIJKMoviePlayerOnFrameCropRectInvalidNotification XDFIJKMPMoviePlayerOnFrameCropRectInvalidNotification
