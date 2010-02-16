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

#ifndef _LOLIBC_STDINT_H
#define _LOLIBC_STDINT_H

#if defined(__x86_64)
    typedef signed char int8_t;
    typedef short int   int16_t;
    typedef int         int32_t;
    typedef long int    int64_t;
#else
    typedef signed char     int8_t;
    typedef short int       int16_t;
    typedef int             int32_t;
    typedef long long int   int64_t;

    typedef long int intptr_t;

    #define INT8_MAX    (127)
#endif

#endif
