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

#include <string.h>
#include <arch/string.h>

size_t
strlen (const char* s)
{
    return __strlen(s);
}

char*
strcat (char* dest, const char* src)
{
    return __strcat(dest, src);
}

char*
strncat (char* dest, const char* src, size_t n)
{
    return __strncat(dest, src, n);
}

void*
memcpy (void* dest, const void* src, size_t n)
{
    return __memcpy(dest, src, n);
}
