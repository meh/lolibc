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

#ifndef _LOLIBC_CTYPE_H
#define _LOLIBC_CTYPE_H

#include <stddef.h>

PUBLIC int isalnum (int ch);

PUBLIC int isalpha (int ch);

#if defined(_BSD_SOURCE) || defined(_SVID_SOURCE) || defined(_XOPEN_SOURCE)
PUBLIC int isascii (int ch);
#endif

#if _XOPEN_SOURCE >= 600 || defined(_ISOC99_SOURCE)
PUBLIC int isblank (int ch);
#endif

PUBLIC int iscntrl (int ch);

PUBLIC int isdigit (int ch);

PUBLIC int isgraph (int ch);

PUBLIC int islower (int ch);

PUBLIC int isprint (int ch);

PUBLIC int ispunct (int ch);

PUBLIC int isspace (int ch);

PUBLIC int isupper (int ch);

PUBLIC int isxdigit (int ch);

PUBLIC int toascii (int ch);

PUBLIC int tolower (int ch);

PUBLIC int toupper (int ch);

#endif
