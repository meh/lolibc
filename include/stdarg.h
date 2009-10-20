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

#ifndef _LOLIBC_STDARG_H
#define _LOLIBC_STDARG_H

#include <common.h>

typedef struct va_list {
    int* address;
} va_list;

#define va_start(arg, first) (arg.address = (int*) (&first + 1))

#define va_copy(src, dest) (dest.address = src.address)

#define va_end(arg) (arg.address = NULL)

#define va_arg(arg, type) (* (((type*) (arg.address = (int*) ((type*) arg.address) + 1)) - 1))

#endif
