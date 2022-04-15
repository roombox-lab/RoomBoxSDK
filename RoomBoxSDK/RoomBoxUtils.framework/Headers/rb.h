/* RB.h -- Errors codes, zip flags and magic
   Version 2.9.2, February 12, 2020
   part of the MiniZip project

   Copyright (C) 2010-2020 Nathan Moinvaziri
     https://github.com/nmoinvaz/minizip

   This program is distributed under the terms of the same license as zlib.
   See the accompanying LICENSE file for the full text of the license.
*/

#ifndef RB_H
#define RB_H

/***************************************************************************/

/* RB_VERSION */
#define RB_VERSION                      ("2.9.2")

/* RB_ERROR */
#define RB_OK                           (0)  /* zlib */
#define RB_STREAM_ERROR                 (-1) /* zlib */
#define RB_DATA_ERROR                   (-3) /* zlib */
#define RB_MEM_ERROR                    (-4) /* zlib */
#define RB_BUF_ERROR                    (-5) /* zlib */
#define RB_VERSION_ERROR                (-6) /* zlib */

#define RB_END_OF_LIST                  (-100)
#define RB_END_OF_STREAM                (-101)

#define RB_PARAM_ERROR                  (-102)
#define RB_FORMAT_ERROR                 (-103)
#define RB_INTERNAL_ERROR               (-104)
#define RB_CRC_ERROR                    (-105)
#define RB_CRYPT_ERROR                  (-106)
#define RB_EXIST_ERROR                  (-107)
#define RB_PASSWORD_ERROR               (-108)
#define RB_SUPPORT_ERROR                (-109)
#define RB_HASH_ERROR                   (-110)
#define RB_OPEN_ERROR                   (-111)
#define RB_CLOSE_ERROR                  (-112)
#define RB_SEEK_ERROR                   (-113)
#define RB_TELL_ERROR                   (-114)
#define RB_READ_ERROR                   (-115)
#define RB_WRITE_ERROR                  (-116)
#define RB_SIGN_ERROR                   (-117)
#define RB_SYMLINK_ERROR                (-118)

/* RB_OPEN */
#define RB_OPEN_MODE_READ               (0x01)
#define RB_OPEN_MODE_WRITE              (0x02)
#define RB_OPEN_MODE_READWRITE          (RB_OPEN_MODE_READ | RB_OPEN_MODE_WRITE)
#define RB_OPEN_MODE_APPEND             (0x04)
#define RB_OPEN_MODE_CREATE             (0x08)
#define RB_OPEN_MODE_EXISTING           (0x10)

/* RB_SEEK */
#define RB_SEEK_SET                     (0)
#define RB_SEEK_CUR                     (1)
#define RB_SEEK_END                     (2)

/* RB_COMPRESS */
#define RB_COMPRESS_METHOD_STORE        (0)
#define RB_COMPRESS_METHOD_DEFLATE      (8)
#define RB_COMPRESS_METHOD_BZIP2        (12)
#define RB_COMPRESS_METHOD_LZMA         (14)
#define RB_COMPRESS_METHOD_AES          (99)

#define RB_COMPRESS_LEVEL_DEFAULT       (-1)
#define RB_COMPRESS_LEVEL_FAST          (2)
#define RB_COMPRESS_LEVEL_NORMAL        (6)
#define RB_COMPRESS_LEVEL_BEST          (9)

/* RB_ZIP_FLAG */
#define RB_ZIP_FLAG_ENCRYPTED           (1 << 0)
#define RB_ZIP_FLAG_LZMA_EOS_MARKER     (1 << 1)
#define RB_ZIP_FLAG_DEFLATE_MAX         (1 << 1)
#define RB_ZIP_FLAG_DEFLATE_NORMAL      (0)
#define RB_ZIP_FLAG_DEFLATE_FAST        (1 << 2)
#define RB_ZIP_FLAG_DEFLATE_SUPER_FAST  (RB_ZIP_FLAG_DEFLATE_FAST | \
                                         RB_ZIP_FLAG_DEFLATE_MAX)
#define RB_ZIP_FLAG_DATA_DESCRIPTOR     (1 << 3)
#define RB_ZIP_FLAG_UTF8                (1 << 11)
#define RB_ZIP_FLAG_MASK_LOCAL_INFO     (1 << 13)

/* RB_ZIP_EXTENSION */
#define RB_ZIP_EXTENSION_ZIP64          (0x0001)
#define RB_ZIP_EXTENSION_NTFS           (0x000a)
#define RB_ZIP_EXTENSION_AES            (0x9901)
#define RB_ZIP_EXTENSION_UNIX1          (0x000d)
#define RB_ZIP_EXTENSION_SIGN           (0x10c5)
#define RB_ZIP_EXTENSION_HASH           (0x1a51)
#define RB_ZIP_EXTENSION_CDCD           (0xcdcd)

/* RB_ZIP64 */
#define RB_ZIP64_AUTO                   (0)
#define RB_ZIP64_FORCE                  (1)
#define RB_ZIP64_DISABLE                (2)

/* RB_HOST_SYSTEM */
#define RB_HOST_SYSTEM(VERSION_MADEBY)  ((uint8_t)(VERSION_MADEBY >> 8))
#define RB_HOST_SYSTEM_MSDOS            (0)
#define RB_HOST_SYSTEM_UNIX             (3)
#define RB_HOST_SYSTEM_WINDOWS_NTFS     (10)
#define RB_HOST_SYSTEM_RISCOS           (13)
#define RB_HOST_SYSTEM_OSX_DARWIN       (19)

/* RB_PKCRYPT */
#define RB_PKCRYPT_HEADER_SIZE          (12)

/* RB_AES */
#define RB_AES_VERSION                  (1)
#define RB_AES_ENCRYPTION_MODE_128      (0x01)
#define RB_AES_ENCRYPTION_MODE_192      (0x02)
#define RB_AES_ENCRYPTION_MODE_256      (0x03)
#define RB_AES_KEY_LENGTH(MODE)         (8 * (MODE & 3) + 8)
#define RB_AES_KEY_LENGTH_MAX           (32)
#define RB_AES_BLOCK_SIZE               (16)
#define RB_AES_HEADER_SIZE(MODE)        ((4 * (MODE & 3) + 4) + 2)
#define RB_AES_FOOTER_SIZE              (10)

/* RB_HASH */
#define RB_HASH_MD5                     (10)
#define RB_HASH_MD5_SIZE                (16)
#define RB_HASH_SHA1                    (20)
#define RB_HASH_SHA1_SIZE               (20)
#define RB_HASH_SHA256                  (23)
#define RB_HASH_SHA256_SIZE             (32)
#define RB_HASH_MAX_SIZE                (256)

/* RB_ENCODING */
#define RB_ENCODING_CODEPAGE_437        (437)
#define RB_ENCODING_CODEPAGE_932        (932)
#define RB_ENCODING_CODEPAGE_936        (936)
#define RB_ENCODING_CODEPAGE_950        (950)
#define RB_ENCODING_UTF8                (65001)

/* RB_UTILITY */
#define RB_UNUSED(SYMBOL)               ((void)SYMBOL)

#ifndef RB_CUSTOM_ALLOC
#define RB_ALLOC(SIZE)                  (malloc(SIZE))
#endif
#ifndef RB_CUSTOM_FREE
#define RB_FREE(PTR)                    (free(PTR))
#endif

#if defined(_WINDOWS) && defined(RB_EXPORTS)
#define RB_EXPORT __declspec(dllexport)
#else
#define RB_EXPORT
#endif

/***************************************************************************/

#include <stdlib.h> /* size_t, NULL, malloc */
#include <time.h>   /* time_t, time() */
#include <string.h> /* memset, strncpy, strlen */
#include <limits.h>

#ifdef HAVE_STDINT_H
#  include <stdint.h>
#endif

#ifndef __INT8_TYPE__
typedef signed char        int8_t;
#endif
#ifndef __INT16_TYPE__
typedef short              int16_t;
#endif
#ifndef __INT32_TYPE__
typedef int                int32_t;
#endif
#ifndef __INT64_TYPE__
typedef long long          int64_t;
#endif
#ifndef __UINT8_TYPE__
typedef unsigned char      uint8_t;
#endif
#ifndef __UINT16_TYPE__
typedef unsigned short     uint16_t;
#endif
#ifndef __UINT32_TYPE__
typedef unsigned int       uint32_t;
#endif
#ifndef __UINT64_TYPE__
typedef unsigned long long uint64_t;
#endif

#ifdef HAVE_INTTYPES_H
//#  include <RoomBoxUtils/inttypes.h>
#endif

#ifndef PRId8
#  define PRId8  "hhd"
#endif
#ifndef PRId16
#  define PRId16 "hd"
#endif
#ifndef PRId32
#  define PRId32 "d"
#endif
#ifndef PRIu32
#  define PRIu32 "u"
#endif
#ifndef PRIx32
#  define PRIx32 "x"
#endif
#if ULONG_MAX == 4294967295UL
#  ifndef PRId64
#    define PRId64 "lld"
#  endif
#  ifndef PRIu64
#    define PRIu64 "llu"
#  endif
#  ifndef PRIx64
#    define PRIx64 "llx"
#  endif
#else
#  ifndef PRId64
#    define PRId64 "ld"
#  endif
#  ifndef PRIu64
#    define PRIu64 "lu"
#  endif
#  ifndef PRIx64
#    define PRIx64 "lx"
#  endif
#endif

#ifndef INT16_MAX
#  define INT16_MAX   32767
#endif
#ifndef INT32_MAX
#  define INT32_MAX   2147483647L
#endif
#ifndef INT64_MAX
#  define INT64_MAX   9223372036854775807LL
#endif
#ifndef UINT16_MAX
#  define UINT16_MAX  65535U
#endif
#ifndef UINT32_MAX
#  define UINT32_MAX  4294967295UL
#endif
#ifndef UINT64_MAX
#  define UINT64_MAX  18446744073709551615ULL
#endif

/***************************************************************************/

#endif
