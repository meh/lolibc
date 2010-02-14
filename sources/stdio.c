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

#define _BSD_SOURCE
#define _GNU_SOURCE
#define _LOL_SOURCE

#include <stdio.h>
#include <arch/stdio.h>

__FILE __stdin  = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
__FILE __stdout = { 0, 0, 1, 0, 0, 0, 0, 0, 0 };
__FILE __stderr = { 0, 0, 2, 0, 0, 0, 0, 0, 0 };

int
printf (const char* format, ...)
{
    return __printf(format, arguments);
}

int
fprintf (FILE* stream, const char* format, ...)
{
    return __fprintf(stream, format, arguments);
}

int
sprintf (char* string, const char* format, ...)
{
    return __sprintf(string, format, arguments);
}

int
snprintf (char* string, size_t limit, const char* format, ...)
{
    return __snprintf(string, limit, format, arguments);
}

