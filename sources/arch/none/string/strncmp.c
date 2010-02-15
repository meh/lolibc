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

int
__strncmp (const char *first, const char *second, size_t limit)
{
    size_t i;

    for (i = 0; i < limit && (first[i] != '\0' && second[i] != '\0'); i++) {
        if (first[i] > second[i]) {
            return 1;
        }
        else if (first[i] < second[i]) {
            return -1;
        }
    }

    if (first[i] == '\0' && second[i] != '\0') {
        return -1;
    }
    else if (second[i] == '\0' && first[i] != '\0') {
        return 1;
    }

    return 0;
}

alias(__strncmp, strncmp);
