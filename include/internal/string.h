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

#ifndef _LOLIBC_ARCH_STRING_H
#define _LOLIBC_ARCH_STRING_H

#include <string.h>

PRIVATE void* __memccpy (void* destination, const void* source, int compareTo, size_t bytes);

PRIVATE void* __memchr (const void* memory, int compareTo, size_t bytes);

#if defined(_GNU_SOURCE)
PRIVATE void* __memrchr (const void* memory, int compareTo, size_t bytes);

PRIVATE void* __rawmemchr (const void* memory, int compareTo);
#endif

PRIVATE int __memcmp (const void* first, const void* second, size_t bytes);

PRIVATE void* __memcpy (void* destination, const void* source, size_t bytes);

PRIVATE void* __memmove (void* destination, const void* source, size_t bytes);

PRIVATE void* __memset (void* memory, int setTo, size_t bytes);

#if defined(_GNU_SOURCE) && 0
PRIVATE char* __strcasestr (const char* string, const char* find);
#endif

PRIVATE char* __strcat (char* destination, const char* source);

PRIVATE char* __strchr (const char* string, int compareTo);

#if defined(_GNU_SOURCE)
PRIVATE char* __strchrnul (const char* string, int compareTo);
#endif

PRIVATE int __strcmp (const char* first, const char* second);

PRIVATE char* __strcpy (char* destination, const char* source);

PRIVATE size_t __strcspn (const char* string, const char* reject);

PRIVATE char* __strdup (const char* string);

#if defined(_GNU_SOURCE)
PRIVATE char* __strndup (const char* string, size_t limit);

/*
I refuse to implement alloca, it's pure faggotry.

PRIVATE char* __strdupa (const char* string);

PRIVATE char* __strndupa (const char* string, size_t limit);
*/
#endif

PRIVATE size_t __strlen (const char* string);

PRIVATE char* __strncat (char* destination, const char* source, size_t limit);

PRIVATE int __strncmp(const char* first, const char* second, size_t limit);

PRIVATE char* __strncpy (char* destination, const char* source, size_t limit);

PRIVATE char* __strpbrk(const char* string, const char* accept);

PRIVATE char* __strrchr (const char* string, int compareTo);

PRIVATE size_t __strspn (const char* string, const char* accept);

PRIVATE char* __strstr (const char* string, const char* find);

#endif
