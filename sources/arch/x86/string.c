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

#include <arch/string.h>

size_t
__x86_strlen (const char* s)
{
    size_t i = 0;

    while (s[i] != '\0') {
        i++;
    }

    return i;
}

char*
__x86_strcat (char* dest, const char* src)
{
    size_t i = __x86_strlen(dest);
    size_t h = 0;

    do {
        dest[i] = src[h];
        i++; h++;
    } while (src[h] != '\0');

    return dest;
}

char*
__x86_strncat (char* dest, const char* src, size_t n)
{
    size_t i = __x86_strlen(dest);
    size_t h = 0;

    do {
        dest[i] = src[h];
        i++; h++;
    } while (src[h] != '\0' && h < n);

    return dest;
}

