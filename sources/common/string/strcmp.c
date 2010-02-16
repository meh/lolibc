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

int
__strcmp (const char *first, const char *second)
{
    size_t i = 0;

    while (first[i] != '\0' && second[i] != '\0') {
        if (first[i] > second[i]) {
            return 1;
        }
        else if (first[i] < second[i]) {
            return -1;
        }

        i++;
    }

    if (first[i] == '\0' && second[i] != '\0') {
        return -1;
    }
    else if (second[i] == '\0' && first[i] != '\0') {
        return 1;
    }

    return 0;
}

alias(__strcmp, strcmp, weak);
