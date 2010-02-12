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
#include <arch/string.h>

size_t
__strlen (const char* s)
{
    if (!s) {
        return 0;
    }

    size_t length;

    asm volatile (
        "movl $0, %%ecx \n"
        "cld \n"
        "repne scasb \n"
        "notl %%ecx \n"
        "decl %%ecx \n"
        "movl %%ecx, %0"
        : "=a" (length)
    );

    return length;
}

char*
__strcat (char* dest, const char* src)
{
    if (!dest || !src) {
        return NULL;
    }

    size_t i = __strlen(dest);
    size_t h = 0;

    while (src[h] != '\0') {
        dest[i] = src[h];
        i++; h++;
    }

    return dest;
}

char*
__strncat (char* dest, const char* src, size_t n)
{
    if (!dest || !src || !n) {
        return NULL;
    }

    size_t i = __strlen(dest);
    size_t h = 0;

    while (src[h] != '\0' && h < n) {
        dest[i] = src[h];
        i++; h++;
    }

    return dest;
}

void*
__memcpy (void* dest, const void* src, size_t n)
{
    size_t i;
    
    for (i = 0; i < n; i++) {
        ((char*) dest)[i] = ((char*) src)[i];
    }

    return dest;
}

void*
__memset (void* s, int c, size_t n)
{
    size_t i;

    for (i = 0; i < n; i++) {
        ((char*) dest)[i] = (char) c;
    }

    return s;
}

