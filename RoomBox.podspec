Pod::Spec.new do |s|
  s.name         = 'RoomBox'
  s.version      = '0.0.3.0' 
  s.summary      = 'RoomBox SDK'
  s.homepage     = "git@github.com:roombox-lab/RoomBoxSDK.git"
  s.license      = "MIT"
  s.author       = { "LYongLiang" => "liangyl0515@163.com" }
  s.social_media_url   = ""
  s.source = {:git => 'git@github.com:roombox-lab/RoomBoxSDK.git'}
  
  s.platform = :ios,'10.0'
  s.swift_version = '5.2'
  s.static_framework = true
  s.default_subspec = 'All'
  s.ios.deployment_target = '10.0'
  s.requires_arc = true

  s.subspec 'All' do |s|
    s.dependency 'RoomBox/Live'
    s.dependency 'RoomBox/RoomBoxPlayback'
    s.dependency 'RoomBox/XDFRoomBoxResource'
  end

  s.subspec 'RoomBoxCommerceLive' do |spec|
    spec.frameworks = 'UIKit', 'CoreFoundation', 'CFNetwork','QuartzCore'
    spec.pod_target_xcconfig = {
     'ENABLE_BITCODE' => 'NO',
     'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES',
     'GCC_PREPROCESSOR_DEFINITIONS' => 'GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS=1'
    }
    spec.resource = "RoomBoxSDK/RoomBoxLiveCommerce.framework/RoomBoxLiveCommerce.bundle"
    spec.vendored_frameworks = 'RoomBoxSDK/RoomBoxLiveCommerce.framework'
    
    spec.dependency 'RoomBox/RoomBoxUtils'
    spec.dependency 'RoomBox/RoomBoxConfigManager'
    spec.dependency 'RoomBox/RoomBoxIM'

    spec.dependency 'Queen','1.5.0-official-ultimate'
    spec.dependency 'AlivcLivePusher','4.3.2'
    spec.dependency 'AliPlayerSDK_iOS','5.4.4.0'
    spec.dependency 'AliPlayerSDK_iOS_ARTC','5.4.4.0'
    spec.dependency 'RtsSDK','1.9.0'
  end

  s.subspec 'Live' do |spec|
    spec.requires_arc = true
    spec.platform = :ios,'10.0'
    spec.frameworks = 'UIKit', 'CoreFoundation', 'CFNetwork','QuartzCore'
    spec.pod_target_xcconfig = {
     'ENABLE_BITCODE' => 'NO',
     'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES',
     'GCC_PREPROCESSOR_DEFINITIONS' => 'GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS=1'
    }
    spec.resource = "RoomBoxSDK/RoomBoxLive.framework/RoomBoxLive.bundle"
    spec.vendored_frameworks = 'RoomBoxSDK/RoomBoxLive.framework'
    
    spec.dependency 'AgoraRtcEngine_Special_iOS', '2.9.107.191.5168'
    spec.dependency 'RoomBox/RoomBoxUtils'
    spec.dependency 'RoomBox/RoomBoxConfigManager'
    spec.dependency 'RoomBox/XDFIJKMediaFramework'
    spec.dependency 'RoomBox/XDFRoomCommonBussiness'
    spec.dependency 'RoomBox/XDFRoomBoxResource'
    spec.dependency 'RoomBox/XdfRtcSDK'
    spec.dependency 'RoomBox/RoomBoxIM'
    spec.dependency 'RoomBox/RoomBoxPlayback'
    spec.dependency 'RoomBox/QsRtcSDK'
    spec.dependency 'RoomBox/RoomBoxLogger'
    
  end
  s.subspec 'LiveNoResource' do |spec|
    spec.requires_arc = true
    spec.platform = :ios,'10.0'
    spec.frameworks = 'UIKit', 'CoreFoundation', 'CFNetwork','QuartzCore'
    spec.pod_target_xcconfig = {
     'ENABLE_BITCODE' => 'NO',
     'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES',
     'GCC_PREPROCESSOR_DEFINITIONS' => 'GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS=1'
    }
    spec.resource = "RoomBoxSDK/RoomBoxLive.framework/RoomBoxLive.bundle"
    spec.vendored_frameworks = 'RoomBoxSDK/RoomBoxLive.framework'
    
    spec.dependency 'AgoraRtcEngine_Special_iOS', '2.9.107.191.5168'
    spec.dependency 'RoomBox/RoomBoxUtils'
    spec.dependency 'RoomBox/RoomBoxConfigManager'
    spec.dependency 'RoomBox/XDFIJKMediaFramework'
    spec.dependency 'RoomBox/XDFRoomCommonBussiness'
    spec.dependency 'RoomBox/XdfRtcSDK'
    spec.dependency 'RoomBox/RoomBoxIM'
    spec.dependency 'RoomBox/RoomBoxPlayback'
    spec.dependency 'RoomBox/QsRtcSDK'
    spec.dependency 'RoomBox/RoomBoxLogger'

  end
  
  s.subspec 'RoomBoxUtils' do |spec|
    spec.requires_arc = true
    spec.platform = :ios,'10.0'
    spec.frameworks = 'UIKit', 'CoreFoundation'
    spec.pod_target_xcconfig = {
      'ENABLE_BITCODE' => 'NO',
      'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES',
      'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS=1'
    }
    spec.dependency 'RxSwift'  , '6.0.0-rc.1'
    spec.dependency 'RxCocoa'  , '6.0.0-rc.1'
    spec.dependency 'RxRelay'  , '6.0.0-rc.1'
    spec.dependency 'Protobuf' , '3.6.1'
    spec.dependency 'SwiftProtobuf'  , '1.5.0'
    spec.vendored_frameworks = 'RoomBoxSDK/RoomBoxUtils.framework'
  end
  s.subspec 'XDFIJKMediaFramework' do |spec|
    spec.requires_arc = true
    spec.platform = :ios,'10.0'
    spec.vendored_frameworks = 'RoomBoxSDK/XDFIJKMediaFramework.framework'
    spec.frameworks  = "AudioToolbox", "AVFoundation", "CoreGraphics", "CoreMedia", "CoreVideo", "MobileCoreServices", "OpenGLES", "QuartzCore", "VideoToolbox", "Foundation", "UIKit", "MediaPlayer"
    spec.libraries   = "bz2", "z", "c++"
  end
 
  s.subspec 'RoomBoxConfigManager' do |spec|
    spec.requires_arc = true
    spec.platform = :ios,'10.0'
    spec.frameworks = 'UIKit', 'CoreFoundation', 'CFNetwork','QuartzCore'
    spec.vendored_frameworks = 'RoomBoxSDK/RoomBoxConfigManager.framework'
  end
  s.subspec 'XDFRoomCommonBussiness' do |spec|
    spec.requires_arc = true
    spec.platform = :ios,'10.0'
    spec.frameworks = 'QuartzCore','UIKit'
    spec.vendored_frameworks = 'RoomBoxSDK/XDFRoomCommonBussiness.framework'
    spec.dependency 'RoomBox/RoomBoxUtils'
    spec.dependency 'RoomBox/RoomBoxConfigManager'
  end
  
 s.subspec 'RoomBoxPlayback' do |spec|
    spec.requires_arc = true
    spec.platform = :ios,'10.0'
    spec.frameworks = 'QuartzCore','UIKit'
    spec.resource = "RoomBoxSDK/RoomBoxPlayback.framework/RoomBoxPlayback.bundle"
    spec.vendored_frameworks = 'RoomBoxSDK/RoomBoxPlayback.framework'
    spec.dependency 'RoomBox/XDFIJKMediaFramework'
    spec.dependency 'RoomBox/RoomBoxUtils'
    spec.dependency 'RoomBox/XDFRoomCommonBussiness'
    spec.dependency 'RoomBox/RoomBoxConfigManager'
    spec.dependency 'AliPlayerSDK_iOS','5.4.4.0'
    spec.dependency 'AliyunOSSiOS','2.10.10'
    spec.dependency 'AliyunLogProducer', '2.2.8'
    spec.dependency 'RoomBox/libABFramework'
    spec.pod_target_xcconfig = {
      'ENABLE_BITCODE' => 'NO',
      'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES',
      'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS=1'
    }
  end
  s.subspec 'XdfRtcSDK' do |spec|
   spec.vendored_frameworks = 'RoomBoxSDK/XdfRTC.framework'
   spec.libraries = 'c++','resolv'
   spec.frameworks = 'CoreML','Accelerate','SystemConfiguration','CoreTelephony','CoreMedia','CoreMotion','AudioToolbox','VideoToolbox','AVFoundation','UIKit'
  end

  s.subspec 'XDFRoomBoxResource' do |spec|
    spec.resources = ["RoomBoxSDK/XDFRoomBoxResources.bundle","RoomBoxSDK/XDFRoomBoxResources_l.bundle","RoomBoxSDK/XDFRoomBoxResources_d.bundle"]
  end
  
  s.subspec 'RoomBoxIM' do |spec|
    spec.vendored_frameworks = 'RoomBoxSDK/RoomBoxIM.framework'
    spec.platform = :ios,'10.0'
    spec.dependency 'Protobuf', '3.6.1'
    spec.dependency 'AliyunLogProducer', '2.2.8'
    spec.pod_target_xcconfig = {
      'ENABLE_BITCODE' => 'NO',
      'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES',
      'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS=1'
    }
  end
 
  s.subspec 'QsRtcSDK' do |spec|
    spec.vendored_frameworks = 'RoomBoxSDK/QsRtcSDK/*.framework'
    spec.libraries = 'c++','resolv'
    spec.frameworks = 'CoreML','Accelerate','SystemConfiguration','CoreTelephony','CoreMedia','CoreMotion','AudioToolbox','VideoToolbox','AVFoundation','UIKit'
  end
  
  s.subspec 'libABFramework' do |spec|
     spec.vendored_frameworks = 'RoomBoxSDK/libABFramework.framework'
     spec.library = 'c++'
  end

  s.subspec 'RoomBoxLogger' do |spec|
  	spec.requires_arc = true
    spec.vendored_frameworks = 'RoomBoxSDK/RoomBoxLogger.framework'
    spec.dependency 'RoomBox/RoomBoxUtils'
    spec.dependency 'RoomBox/RoomBoxConfigManager'
    spec.dependency 'AliyunLogProducer', '2.2.8'
  end
  
end
