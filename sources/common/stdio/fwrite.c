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

#include <errno.h>

#include <internal/stdio.h>
#include <private/stdio/stream.h>

size_t
__fwrite (const void* buffer, size_t size, size_t number, FILE* stream)
{
    __FILE* file = (__FILE*) stream;
    ssize_t written;

    if (!__lolibc_stdio_is_valid_stream(file)) {
        errno = EBADF;
        return 0;
    }

    written = file->write(file, buffer, size * number);

    if (written <= 0) {
        return written;
    }

    return (written / size);
}

alias(__fwrite, fwrite, weak);
