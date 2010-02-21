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

#ifndef _LOLIBC_PRIVATE_STDIO_MEMSTREAM_H
#define _LOLIBC_PRIVATE_STDIO_MEMSTREAM_H

#include "stream.h"

PRIVATE ssize_t (*__lolibc_MEMSTREAM_read) (void* data, char* buffer, size_t size);

PRIVATE ssize_t (*__lolibc_MEMSTREAM_write) (void* data, const char* buffer, size_t size);

PRIVATE int (*__lolibc_MEMSTREAM_seek) (void* data, unsigned long position, int whence);

PRIVATE unsigned long (*__lolibc_MEMSTREAM_tell) (void* data);

PRIVATE int (*__lolibc_MEMSTREAM_flush) (void* data);

PRIVATE int (*__lolibc_MEMSTREAM_close) (void* data);

extern const char* __MEMSTREAM_name;

typedef struct __MEMSTREAM_data {
    char*  buffer;
    size_t length;
} __MEMSTREAM_data;

#endif
