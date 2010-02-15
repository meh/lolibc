/****************************************************************************
* lolibc, a C library.                                                      *
*                                                                           *
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
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

#include <private/stdio/iofile.h>

#define STREAM(name) __## name

#define NEW_STD_STREAM(name, fd) \
__IO_FILE_data __## name ##_fd = { fd }; \
__FILE STREAM(name); \
STREAM(name).data  = &__## name ##_fd; \
STREAM(name).type  = __IO_FILE_name; \
STREAM(name).read  = __lolibc_IO_FILE_read; \
STREAM(name).write =__lolibc_IO_FILE_write; \
STREAM(name).seek  = __lolibc_IO_FILE_seek; \
STREAM(name).tell  = __lolibc_IO_FILE_tell; \
STREAM(name).flush = __lolibc_IO_FILE_flush; \
STREAM(name).close = __lolibc_IO_FILE_close; \
STREAM(name).magic = 1337

NEW_STD_STREAM(stdin, 0);

NEW_STD_STREAM(stdout, 1);

NEW_STD_STREAM(stderr, 2);

