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

#include <stdlib.h>

#include <private/stdio/stream.h>

__FILE*
__lolibc_FILE_create (void* data, const char* type,
    __lolibc_FILE_read read, __lolibc_FILE_write write,
    __lolibc_FILE_seek seek, __lolibc_FILE_tell tell,
    __lolibc_FILE_flush flush, __lolibc_FILE_close close)
{
    __FILE* file = malloc(sizeof(__FILE));

    return __lolibc_FILE_initialize(file, data, type, read, write, seek, tell, flush, close);
}

