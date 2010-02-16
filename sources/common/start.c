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

#include <stddef.h>
#include <stdlib.h>

extern int main (int argc, char** argv, char** envp);

typedef void (*__cdtor) (void);

static __cdtor __lolibc_ctors[] __attribute__ ((section (".ctors"))) = { (void*) 0 };
static __cdtor __lolibc_dtors[] __attribute__ ((section (".dtors"))) = { (void*) 0 };

static
void
__execute_ctors (__cdtor list[])
{
    __cdtor* function = list;

    // execute backwards, because Linux does so.
    while (*function) {
        function++;
    }

    while (*function) {
        (*function)();
        function--;
    }
}

static
void
__execute_dtors (__cdtor list[])
{
    __cdtor* function = list;

    // execute backwards, because Linux does so.
    while (*function) {
        (*function)();
        function++;
    }
}

PUBLIC
void
_start (int argc, char** argv, char** envp)
{
    int code;

    __execute_ctors(__lolibc_ctors);

    code = main(argc, argv, envp);

    __execute_dtors(__lolibc_dtors);

    exit(code);
}

