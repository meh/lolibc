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

#ifndef _LOLIBC_ARCH_STRING_H
#define _LOLIBC_ARCH_STRING_H

#include <string.h>

inline void* __memccpy (void* destination, const void* source, int compareTo, size_t bytes);

inline void* __memchr (const void* memory, int compareTo, size_t bytes);

#ifdef _GNU_SOURCE
inline void* __memrchr (const void* memory, int compareTo, size_t bytes);

inline void* __rawmemchr (const void* memory, int compareTo);
#endif

inline int __memcmp (const void* first, const void* second, size_t bytes);

inline void* __memcpy (void* destination, const void* source, size_t bytes);

inline void* __memmove (void* destination, const void* source, size_t bytes);

inline void* __memset (void* memory, int setTo, size_t bytes);

inline char* __strcat (char* destination, const char* source);

inline char* __strncat (char* destination, const char* source, size_t limit);

inline char* __strchr (const char* string, int compareTo);

inline char* __strrchr (const char* string, int compareTo);

#ifdef _GNU_SOURCE
inline char* __strchrnul (const char* string, int compareTo);
#endif

inline int __strcmp (const char* first, const char* second);

inline int __strncmp(const char* first, const char* second, size_t limit);

inline char* __strcpy (char* destination, const char* source);

inline char* __strncpy (char* destination, const char* source, size_t limit);

inline size_t __strspn (const char* string, const char* accept);

inline size_t __strcspn (const char* string, const char* reject);

inline char* __strdup (const char* string);

#ifdef _GNU_SOURCE
inline char* __strndup (const char* string, size_t limit);

/* I refuse to implement alloca, it's pure faggotry.

inline char* __strdupa (const char* string);

inline char* __strndupa (const char* string, size_t limit);

*/
#endif

inline size_t __strlen (const char* string);

#endif
