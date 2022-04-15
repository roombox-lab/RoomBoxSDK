/* rb_strm_buf.h -- Stream for buffering reads/writes
   Version 2.9.2, February 12, 2020
   part of the MiniZip project

   This version of ioapi is designed to buffer IO.

   Copyright (C) 2010-2020 Nathan Moinvaziri
      https://github.com/nmoinvaz/minizip

   This program is distributed under the terms of the same license as zlib.
   See the accompanying LICENSE file for the full text of the license.
*/

#ifndef RB_STREAM_BUFFERED_H
#define RB_STREAM_BUFFERED_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************/

int32_t rb_stream_buffered_open(void *stream, const char *path, int32_t mode);
int32_t rb_stream_buffered_is_open(void *stream);
int32_t rb_stream_buffered_read(void *stream, void *buf, int32_t size);
int32_t rb_stream_buffered_write(void *stream, const void *buf, int32_t size);
int64_t rb_stream_buffered_tell(void *stream);
int32_t rb_stream_buffered_seek(void *stream, int64_t offset, int32_t origin);
int32_t rb_stream_buffered_close(void *stream);
int32_t rb_stream_buffered_error(void *stream);

void*   rb_stream_buffered_create(void **stream);
void    rb_stream_buffered_delete(void **stream);

void*   rb_stream_buffered_get_interface(void);

/***************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
