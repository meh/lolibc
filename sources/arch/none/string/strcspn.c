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

#include <arch/string.h>

size_t
__strcspn (const char* string, const char* reject)
{
    size_t charsetLength = strlen(reject);
    size_t h;
    size_t i   = 0;
    char   out = 1;

    while (string[i] != '\0') {
        for (h = 0; h < charsetLength; h++) {
            if (string[i] == reject[h]) {
                out = 0;
                break;
            }
        }

        if (!out) {
            break;
        }

        out = 1;
        i++;
    }

    return i;
}

