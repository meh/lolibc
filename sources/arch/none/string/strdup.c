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

#include <errno.h>

#include <arch/string.h>

char*
__strdup (const char* string)
{
    size_t length = strlen(string);
    size_t i;

    char* dupe = malloc((length + 1) * sizeof(char));

    if (dupe == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    for (i = 0; i < length; i++) {
        dupe[i] = string[i];
    }

    dupe[i] = '\0';

    return dupe;
}

