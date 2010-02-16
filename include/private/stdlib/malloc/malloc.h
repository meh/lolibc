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

#ifndef _LOLIBC_PRIVATE_STDLIB_MALLOC_H
#define _LOLIBC_PRIVATE_STDLIB_MALLOC_H

#include <stddef.h>

#define __LOLIBC_MALLOC_MAGIC 23421337L

extern void* __lolibc_malloc_memory_start;
extern void* __lolibc_malloc_memory_end;

#include <private/stdlib/malloc/block.h>

PRIVATE void __lolibc_malloc_initialize (void) __attribute__((constructor(0)));

PRIVATE int __lolibc_malloc_increase_heap (ssize_t increment);

#endif
