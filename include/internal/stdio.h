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

#ifndef _LOLIBC_INTERNAL_STDIO_H
#define _LOLIBC_INTERNAL_STDIO_H

#include <stdio.h>


PRIVATE size_t __fwrite (const void* buffer, size_t size, size_t number, FILE* stream);

PRIVATE int __fprintf (FILE* stream, const char* format, ...);

PRIVATE int __printf (const char* format, ...);

PRIVATE int __sprintf (char* string, const char* format, ...);

#if defined(_BSD_SOURCE) || _XOPEN_SOURCE >= 500 || defined(_ISOC99_SOURCE)
PRIVATE int __snprintf (char* string, size_t limit, const char* format, ...);
#endif

#endif
