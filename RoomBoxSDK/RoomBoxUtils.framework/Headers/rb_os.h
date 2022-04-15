/* rb_os.h -- System functions
   Version 2.9.2, February 12, 2020
   part of the MiniZip project

   Copyright (C) 2010-2020 Nathan Moinvaziri
     https://github.com/nmoinvaz/minizip

   This program is distributed under the terms of the same license as zlib.
   See the accompanying LICENSE file for the full text of the license.
*/

#ifndef RB_OS_H
#define RB_OS_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************/

#if defined(__APPLE__)
#  define RB_VERSION_MADEBY_HOST_SYSTEM (RB_HOST_SYSTEM_OSX_DARWIN)
#elif defined(__riscos__)
#  define RB_VERSION_MADEBY_HOST_SYSTEM (RB_HOST_SYSTEM_RISCOS)
#elif defined(__unix__)
#  define RB_VERSION_MADEBY_HOST_SYSTEM (RB_HOST_SYSTEM_UNIX)
#elif defined(_WIN32)
#  define RB_VERSION_MADEBY_HOST_SYSTEM (RB_HOST_SYSTEM_WINDOWS_NTFS)
#endif

#if defined(HAVE_LZMA)
#  define RB_VERSION_MADEBY_ZIP_VERSION (63)
#elif defined(HAVE_WZAES)
#  define RB_VERSION_MADEBY_ZIP_VERSION (51)
#elif defined(HAVE_BZIP2)
#  define RB_VERSION_MADEBY_ZIP_VERSION (46)
#else
#  define RB_VERSION_MADEBY_ZIP_VERSION (45)
#endif

#define RB_VERSION_MADEBY               ((RB_VERSION_MADEBY_HOST_SYSTEM << 8) | \
                                         (RB_VERSION_MADEBY_ZIP_VERSION))

#define RB_PATH_SLASH_UNIX              ('/')
#if defined(_WIN32)
#  define RB_PATH_SLASH_PLATFORM        ('\\')
#else
#  define RB_PATH_SLASH_PLATFORM        (RB_PATH_SLASH_UNIX)
#endif

/***************************************************************************/

#if defined(_WIN32)
struct dirent {
    char d_name[256];
};
typedef void* DIR;
#else
#include <dirent.h>
#endif

/***************************************************************************/
/* Shared functions */

int32_t rb_path_combine(char *path, const char *join, int32_t max_path);
/* Combines two paths */

int32_t rb_path_append_slash(char *path, int32_t max_path, char slash);
/* Appends a path slash on to the end of the path */

int32_t rb_path_remove_slash(char *path);
/* Removes a path slash from the end of the path */

int32_t rb_path_has_slash(const char *path);
/* Returns whether or not the path ends with slash */

int32_t rb_path_convert_slashes(char *path, char slash);
/* Converts the slashes in a path */

int32_t rb_path_compare_wc(const char *path, const char *wildcard, uint8_t ignore_case);
/* Compare two paths with wildcard */

int32_t rb_path_resolve(const char *path, char *target, int32_t max_target);
/* Resolves path */

int32_t rb_path_remove_filename(char *path);
/* Remove the filename from a path */

int32_t rb_path_remove_extension(char *path);
/* Remove the extension from a path */

int32_t rb_path_get_filename(const char *path, const char **filename);
/* Get the filename from a path */

int32_t rb_dir_make(const char *path);
/* Creates a directory recursively */

int32_t rb_file_get_crc(const char *path, uint32_t *result_crc);
/* Gets the crc32 hash of a file */

/***************************************************************************/
/* Platform specific functions */

wchar_t *rb_os_unicode_string_create(const char *string, int32_t encoding);
/* Create unicode string from a utf8 string */

void     rb_os_unicode_string_delete(wchar_t **string);
/* Delete a unicode string that was created */

uint8_t *rb_os_utf8_string_create(const char *string, int32_t encoding);
/* Create a utf8 string from a string with another encoding */

void     rb_os_utf8_string_delete(uint8_t **string);
/* Delete a utf8 string that was created */

int32_t  rb_os_rand(uint8_t *buf, int32_t size);
/* Random number generator (not cryptographically secure) */

int32_t  rb_os_rename(const char *source_path, const char *target_path);
/* Rename a file */

int32_t  rb_os_unlink(const char *path);
/* Delete an existing file  */

int32_t  rb_os_file_exists(const char *path);
/* Check to see if a file exists */

int64_t  rb_os_get_file_size(const char *path);
/* Gets the length of a file */

int32_t  rb_os_get_file_date(const char *path, time_t *modified_date, time_t *accessed_date, time_t *creation_date);
/* Gets a file's modified, access, and creation dates if supported */

int32_t  rb_os_set_file_date(const char *path, time_t modified_date, time_t accessed_date, time_t creation_date);
/* Sets a file's modified, access, and creation dates if supported */

int32_t  rb_os_get_file_attribs(const char *path, uint32_t *attributes);
/* Gets a file's attributes */

int32_t  rb_os_set_file_attribs(const char *path, uint32_t attributes);
/* Sets a file's attributes */

int32_t  rb_os_make_dir(const char *path);
/* Recursively creates a directory */

DIR*     rb_os_open_dir(const char *path);
/* Opens a directory for listing */
struct
dirent*  rb_os_read_dir(DIR *dir);
/* Reads a directory listing entry */

int32_t  rb_os_close_dir(DIR *dir);
/* Closes a directory that has been opened for listing */

int32_t  rb_os_is_dir(const char *path);
/* Checks to see if path is a directory */

int32_t  rb_os_is_symlink(const char *path);
/* Checks to see if path is a symbolic link */

int32_t  rb_os_make_symlink(const char *path, const char *target_path);
/* Creates a symbolic link pointing to a target */

int32_t  rb_os_read_symlink(const char *path, char *target_path, int32_t max_target_path);
/* Gets the target path for a symbolic link */

uint64_t rb_os_ms_time(void);
/* Gets the time in milliseconds */

/***************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
