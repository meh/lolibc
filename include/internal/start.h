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

#ifndef _LOLIBC_INTERNAL_START_H
#define _LOLIBC_INTERNAL_START_H

extern int main (int argc, char** argv, char** envp);

PRIVATE static void __nop (void) {};

#define __LOLIBC_CONSTRUCTOR 1
#define __LOLIBC_DESTRUCTOR  2

typedef void (*__hook) (void);

PRIVATE inline void __call_constructors (__hook* list);

PRIVATE inline void __call_destructors (__hook* list);

PRIVATE void ___start (int argc, char** argv, char** envp);

#endif

