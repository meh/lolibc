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

#ifndef _LOLIBC_PRIVATE_STDLIB_MALLOC_BLOCK_H
#define _LOLIBC_PRIVATE_STDLIB_MALLOC_BLOCK_H

#include <private/stdlib/malloc/malloc.h>

typedef struct __lolibc_malloc_block {
    long magic;

    char isAvailable;

    size_t size;
} __lolibc_malloc_block;

PRIVATE int __lolibc_malloc_block_initialize (__lolibc_malloc_block* block, size_t size);

PRIVATE int __lolibc_malloc_block_finalize (__lolibc_malloc_block* block);

PRIVATE inline int __lolibc_malloc_block_is_valid (__lolibc_malloc_block* block);

PRIVATE __lolibc_malloc_block* __lolibc_malloc_block_from_address (void* address);

PRIVATE void* __lolibc_malloc_block_to_address (__lolibc_malloc_block* block);

#define __LOLIBC_MALLOC_BLOCK_OK         1
#define __LOLIBC_MALLOC_BLOCK_NOT_VALID -1

#endif
