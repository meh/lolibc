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

#include <internal/string.h>

size_t
__strspn (const char* string, const char* accept)
{
    size_t charsetLength = strlen(accept);
    size_t h;
    size_t i  = 0;
    char   in = 1;

    while (string[i] != '\0') {
        for (h = 0; h < charsetLength; h++) {
            if (string[i] != accept[h]) {
                in = 0;
                break;
            }
        }

        if (!in) {
            break;
        }

        in = 1;
        i++;
    }

    return i;
}

alias(__strspn, strspn, weak);
