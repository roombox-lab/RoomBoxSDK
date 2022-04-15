/**
 * Created by RBBeeHive.
 * Copyright (c) 2016, Alibaba, Inc. All rights reserved.
 *
 * This source code is licensed under the GNU GENERAL PUBLIC LICENSE.
 * For the full copyright and license information,please view the LICENSE file in the root directory of this source tree.
 */

#ifndef RBCommon_h
#define RBCommon_h

// Debug Logging
#ifdef DEBUG
#define RBLog(x, ...) NSLog(x, ## __VA_ARGS__);
#else
#define RBLog(x, ...)
#endif

#endif /* RBCommon_h */
