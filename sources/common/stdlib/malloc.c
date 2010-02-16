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

#include <internal/stdlib.h>
#include <private/stdlib/malloc/malloc.h>

void*
__malloc (size_t size)
{
    void*                  current = __lolibc_malloc_memory_start;
    __lolibc_malloc_block* currentBlock;
    __lolibc_malloc_block* tmp;

    while (current != __lolibc_malloc_memory_end) {
        currentBlock = (__lolibc_malloc_block*) current;

        // if the memory block is available and big enough
        if (currentBlock->isAvailable && currentBlock->size >= size) {
            // if there's memory left, let's create an available block on the unused memory
            if (currentBlock->size < size && currentBlock->size > sizeof(__lolibc_malloc_block)) {
                tmp = (__lolibc_malloc_block*) (current + size + sizeof(__lolibc_malloc_block));
                __lolibc_malloc_block_initialize(tmp, currentBlock->size - size - sizeof(__lolibc_malloc_block));
                currentBlock->size = size;
            }
            else {
                currentBlock->isAvailable = 0;
            }
        }

        current += currentBlock->size + sizeof(__lolibc_malloc_block);
    }

    if (current == __lolibc_malloc_memory_end) {
        if (__lolibc_malloc_increase_heap(size + sizeof(__lolibc_malloc_block)) < 0) {
            abort();
        }

        currentBlock                = __lolibc_malloc_memory_end;
        __lolibc_malloc_memory_end += size + sizeof(__lolibc_malloc_block);

        __lolibc_malloc_block_initialize(currentBlock, size);
    }

    return __lolibc_malloc_block_to_address(currentBlock);
}

alias(__malloc, malloc, weak);
