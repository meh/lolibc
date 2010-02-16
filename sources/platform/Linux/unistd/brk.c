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

#include <errno.h>
#include <linux/unistd.h>

#include <internal/unistd.h>

void* __lolibc_current_brk = NULL;

int
__brk (void* address)
{
    void* tmp = __lolibc_current_brk;

    asm volatile (
        "int $0x80"
        : "=a" (__lolibc_current_brk)
        : "a" (__NR_brk), "b" (address)
    );

    if (tmp == __lolibc_current_brk) {
        errno = ENOMEM;
        return -1;
    }

    return 0;
}

alias(__brk, brk, weak);
