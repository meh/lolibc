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

#include <stdlib.h>
#include <unistd.h>

#include <internal/start.h>

void
__lolibc_main_init (void)
{
    write(1, "lol\n", 4);
}

void
__lolibc_main_fini (void)
{
    write(1, "omg\n", 4);
}

alias(__lolibc_main_init, _init, weak);
alias(__lolibc_main_fini, _fini, weak);

void
__lolibc_main_start (int argc, char** argv, char** envp)
{
    int result;

    _init();

    result = main(argc, argv, envp);

    _fini();

    exit(result);
}

alias(__lolibc_main_start, _start, weak);
