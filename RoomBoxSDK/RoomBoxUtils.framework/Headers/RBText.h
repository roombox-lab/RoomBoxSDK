//
//  RBText.h
//  RBText <https://github.com/ibireme/RBText>
//
//  Created by ibireme on 15/2/25.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

#if __has_include(<RBText/RBText.h>)
FOUNDATION_EXPORT double RBTextVersionNumber;
FOUNDATION_EXPORT const unsigned char RBTextVersionString[];
#import <RBText/YYLabel.h>
#import <RBText/RBTextView.h>
#import <RBText/RBTextAttribute.h>
#import <RBText/RBTextArchiver.h>
#import <RBText/RBTextParser.h>
#import <RBText/RBTextRunDelegate.h>
#import <RBText/RBTextRubyAnnotation.h>
#import <RBText/RBTextLayout.h>
#import <RBText/RBTextLine.h>
#import <RBText/RBTextInput.h>
#import <RBText/RBTextDebugOption.h>
#import <RBText/RBTextKeyboardManager.h>
#import <RBText/RBTextUtilities.h>
#import <RBText/NSAttributedString+RBText.h>
#import <RBText/NSParagraphStyle+RBText.h>
#else
#import "RBLabel.h"
#import "RBTextView.h"
#import "RBTextAttribute.h"
#import "RBTextArchiver.h"
#import "RBTextParser.h"
#import "RBTextRunDelegate.h"
#import "RBTextRubyAnnotation.h"
#import "RBTextLayout.h"
#import "RBTextLine.h"
#import "RBTextInput.h"
#import "RBTextDebugOption.h"
#import "RBTextKeyboardManager.h"
#import "RBTextUtilities.h"
#import "NSAttributedString+RBText.h"
#import "NSParagraphStyle+RBText.h"
#import "UIPasteboard+RBText.h"
#endif
