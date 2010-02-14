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

#ifndef _LOLIBC_ARCH_STDARG_H
#define _LOLIBC_ARCH_STDARG_H

inline int __vprintf (const char* format, va_list arguments);

inline int __vfprintf (FILE* stream, const char* format, va_list arguments);

inline int __vsprintf (char* string, const char* format, va_list arguments);

#if defined(_BSD_SOURCE) || _XOPEN_SOURCE >= 500 || defined(_ISOC99_SOURCE)
inline int __vsnprintf (char* string, size_t limit, const char* format, va_list arguments);
#endif

#endif
