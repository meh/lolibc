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

inline void* __memccpy (void* dest, const void* src, int c, size_t n);

inline void* __memchr (const void *s, int c, size_t n);

#ifdef _GNU_SOURCE
inline void* __memrchr (const void *s, int c, size_t n);

inline void* __rawmemchr (const void *s, int c);
#endif

inline int __memcmp (const void *s1, const void *s2, size_t n);

inline void* __memcpy (void* dest, const void* src, size_t n);

inline void* __memmove (void *dest, const void *src, size_t n);

inline void* __memset (void* s, int c, size_t n);

inline char* __strcat (char* dest, const char* src);

inline char* __strncat (char* dest, const char* src, size_t n);

inline char* __strchr (const char *s, int c);

inline char* __strrchr (const char *s, int c);

#ifdef _GNU_SOURCE
inline char* __strchrnul (const char *s, int c);
#endif

inline size_t __strlen (const char* s);


#endif
