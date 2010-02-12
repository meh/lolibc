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

#include <string.h>
#include <lolibc/arch/string.h>

size_t
__none_strlen (const char* s)
{
    if (!s) {
        return 0;
    }

    size_t length = 0;

    while (s[length] != '\0') {
        length++;
    }

    return length;
}

char*
__none_strcat (char* dest, const char* src)
{
    if (!dest || !src) {
        return NULL;
    }

    size_t i = __none_strlen(dest);
    size_t h = 0;

    while (src[h] != '\0') {
        dest[i] = src[h];
        i++; h++;
    }

    return dest;
}

char*
__none_strncat (char* dest, const char* src, size_t n)
{
    if (!dest || !src || !n) {
        return NULL;
    }

    size_t i = __none_strlen(dest);
    size_t h = 0;

    while (src[h] != '\0' && h < n) {
        dest[i] = src[h];
        i++; h++;
    }

    return dest;
}

