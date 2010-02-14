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

#include <ctype.h>

inline int __isalnum (int ch);

inline int __isalpha (int ch);

#if defined(_BSD_SOURCE) || defined(_SVID_SOURCE) || defined(_XOPEN_SOURCE)
inline int __isascii (int ch);
#endif

#if _XOPEN_SOURCE >= 600 || defined(_ISOC99_SOURCE)
inline int __isblank (int ch);
#endif

inline int __iscntrl (int ch);

inline int __isdigit (int ch);

inline int __isgraph (int ch);

inline int __islower (int ch);

inline int __isprint (int ch);

inline int __ispunct (int ch);

inline int __isspace (int ch);

inline int __isupper (int ch);

inline int __isxdigit (int ch);

inline int __toascii (int ch);

inline int __tolower (int ch);

inline int __toupper (int ch);

#endif
