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

#include <private/stdio/iofile.h>

__FILE* __stdin  = NULL;
__FILE* __stdout = NULL;
__FILE* __stderr = NULL;

#define GET_FILE(name) ___## name
#define GET_FILE_FD(name) ___## name ##_fd

#define NEW_FILE(name, fd) \
    static __FILE ___## name ; \
    NEW_FILE_FD(name, fd)

#define NEW_FILE_FD(name, fd) \
    static __IO_FILE_data ___## name ##_fd = { fd }

#define INITIALIZE_FILE(name) \
    __lolibc_FILE_initialize(&GET_FILE(name), &GET_FILE_FD(name), __IO_FILE_name, \
        __lolibc_IO_FILE_read, __lolibc_IO_FILE_write, \
        __lolibc_IO_FILE_seek, __lolibc_IO_FILE_tell, \
        __lolibc_IO_FILE_flush, __lolibc_IO_FILE_close \
    )

NEW_FILE(stdin, 0);
NEW_FILE(stdout, 1);
NEW_FILE(stderr, 2);

static void initialize (void) __attribute__ ((constructor));

static
void
initialize (void)
{
    INITIALIZE_FILE(stdin);
    INITIALIZE_FILE(stdout);
    INITIALIZE_FILE(stderr);
}

