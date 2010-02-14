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

#ifndef _LOLIBC_STRING_H
#define _LOLIBC_STRING_H

#include <stddef.h>

PUBLIC void* memccpy (void* destination, const void* source, int compareTo, size_t bytes);

PUBLIC void* memchr (const void* memory, int compareTo, size_t bytes);

#if defined(_GNU_SOURCE)
PUBLIC void* memrchr (const void* memory, int compareTo, size_t bytes);

PUBLIC void* rawmemchr (const void* memory, int compareTo);
#endif

PUBLIC int memcmp (const void* first, const void* second, size_t bytes);

PUBLIC void* memcpy (void* destination, const void* source, size_t bytes);

PUBLIC void* memmove (void* destination, const void* source, size_t bytes);

PUBLIC void* memset (void* memory, int setTo, size_t bytes);

#if defined(_GNU_SOURCE)
PUBLIC char* strcasestr (const char* string, const char* find);
#endif

PUBLIC char* strcat (char* destination, const char* source);

PUBLIC char* strchr (const char* string, int compareTo);

#if defined(_GNU_SOURCE)
PUBLIC char* strchrnul (const char* string, int compareTo);
#endif

PUBLIC int strcmp (const char* first, const char* second);

PUBLIC char* strcpy (char* destination, const char* source);

PUBLIC size_t strcspn (const char* string, const char* reject);

PUBLIC char* strdup (const char* string);

#if defined(_GNU_SOURCE)
PUBLIC char* strndup (const char* string, size_t limit);

#if 0
I refuse to implement alloca, it's pure faggotry.

PUBLIC char* strdupa (const char* string);

PUBLIC char* strndupa (const char* string, size_t limit);
#endif
#endif

PUBLIC size_t strlen (const char* string);

PUBLIC char* strncat (char* destination, const char* source, size_t limit);

PUBLIC int strncmp(const char* first, const char* second, size_t limit);

PUBLIC char* strncpy (char* destination, const char* source, size_t limit);

PUBLIC char* strpbrk(const char* string, const char* accept);

PUBLIC char* strrchr (const char* string, int compareTo);

PUBLIC size_t strspn (const char* string, const char* accept);

PUBLIC char* strstr (const char* string, const char* find);

#endif
