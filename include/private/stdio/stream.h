/****************************************************************************
* lolibc, a C library.                                                      *
*                                                                           *
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lolibc.                                              *
*                                                                           *
* lolibc is free software: you can redistribute it and/or modify            *
* it under the terms of the GNU Affero General Public License as published  *
* by the Free Software Foundation, either version 3 of the License, or      *
* (at your option) any later version.                                       *
*                                                                           *
* lolibc is distributed in the hope that it will be useful,                 *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU Affero General Public License for more details.                       *
*                                                                           *
* You should have received a copy of the GNU Affero General Public License  *
* along with lolibc.  If not, see <http://www.gnu.org/licenses/>.           *
****************************************************************************/

#ifndef _LOLIBC_PRIVATE_STDIO_STREAM_H
#define _LOLIBC_PRIVATE_STDIO_STREAM_H

#include <stddef.h>

typedef ssize_t (*__lolibc_FILE_read) (void* data, char* buffer, size_t size);

typedef ssize_t (*__lolibc_FILE_write) (void* data, const char* buffer, size_t size);

typedef int (*__lolibc_FILE_seek) (void* data, unsigned long position, int whence);

typedef unsigned long (*__lolibc_FILE_tell) (void* data);

typedef int (*__lolibc_FILE_flush) (void* data);

typedef int (*__lolibc_FILE_close) (void* data);

typedef struct __FILE {
    void*       data;  /* the GNU "cookie" */
    const char* type;  /* name of the stream, passed when registering a stream */

    __lolibc_FILE_read  read;
    __lolibc_FILE_write write;
    __lolibc_FILE_seek  seek;
    __lolibc_FILE_tell  tell;
    __lolibc_FILE_flush flush;
    __lolibc_FILE_close close;

    long magic; /* used for validity checking */
} __FILE;

PRIVATE __FILE* __lolibc_FILE_create (void* data, const char* type,
    __lolibc_FILE_read read, __lolibc_FILE_write write,
    __lolibc_FILE_seek seek, __lolibc_FILE_tell tell,
    __lolibc_FILE_flush flush, __lolibc_FILE_close close
);

PRIVATE __FILE* __lolibc_FILE_initialize (__FILE* file, void* data, const char* type,
    __lolibc_FILE_read read, __lolibc_FILE_write write,
    __lolibc_FILE_seek seek, __lolibc_FILE_tell tell,
    __lolibc_FILE_flush flush, __lolibc_FILE_close close
);


PRIVATE int __lolibc_FILE_is_valid_stream (__FILE* stream);

#endif
