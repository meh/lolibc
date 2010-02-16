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

#ifndef _LOLIBC_PRIVATE_STDIO_IO_FILE_H
#define _LOLIBC_PRIVATE_STDIO_IO_FILE_H

#include "stream.h"

PRIVATE ssize_t (*__lolibc_IO_FILE_read) (void* data, char* buffer, size_t size);

PRIVATE ssize_t (*__lolibc_IO_FILE_write) (void* data, const char* buffer, size_t size);

PRIVATE int (*__lolibc_IO_FILE_seek) (void* data, unsigned long position, int whence);

PRIVATE unsigned long (*__lolibc_IO_FILE_tell) (void* data);

PRIVATE int (*__lolibc_IO_FILE_flush) (void* data);

PRIVATE int (*__lolibc_IO_FILE_close) (void* data);

extern const char* __IO_FILE_name;

typedef struct __IO_FILE_data {
    int fd;
} __IO_FILE_data;

#endif
