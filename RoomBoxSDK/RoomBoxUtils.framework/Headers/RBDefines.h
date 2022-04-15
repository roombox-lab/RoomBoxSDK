/**
 * Created by RBBeeHive.
 * Copyright (c) 2016, Alibaba, Inc. All rights reserved.
 *
 * This source code is licensed under the GNU GENERAL PUBLIC LICENSE.
 * For the full copyright and license information,please view the LICENSE file in the root directory of this source tree.
 */

#ifndef RBDefines_h
#define RBDefines_h


#if defined(__cplusplus)
#define RB_EXTERN extern "C" __attribute__((visibility("default")))
#else
#define RB_EXTERN extern __attribute__((visibility("default")))
#endif

#endif /* RBDefines_h */
