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

#include <arch/stdarg.h>
#include <stdio.h>
#include <private/stdarg.h>
#include <private/stdio.h>

int
__vfprintf (FILE* stream, const char* format, va_list arguments)
{
    size_t      printed   = 0;
    size_t      length    = 0;
    size_t      i         = 0;
    size_t      tmpLength = 0;
    const char* tmp       = format;
    void*       argument;

    while (format[i] != '\0') {
        if (format[i] == '%') {
            fwrite(tmp, sizeof(char), tmpLength, stream);

            argument = va_arg(arguments, void*);
            length   = __lolibc_stdarg_length_single(&format[i], argument);

            char buffer[length+1];
            printed += __lolibc_stdarg_convert(&format[i], argument, buffer);

            i += __lolibc_stdarg_placeholder_length(&format[i]);

            tmpLength = 0;
            tmp       = &format[i];
        }
        else {
            tmpLength++;
            i++;
        }
    }

    return printed;
}

alias(__vfprintf, vfprintf, weak);
