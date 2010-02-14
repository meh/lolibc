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

#ifndef _LOLIBC_PRIVATE_STDIO_H
#define _LOLIBC_PRIVATE_STDIO_H

typedef struct __FILE {
    int             level;  /* fill/empty level of buffer */
    unsigned        flags;  /* File status flags          */
    char            fd;     /* File descriptor            */
    unsigned char   hold;   /* Ungetc char if no buffer   */
    int             bsize;  /* Buffer size                */
    unsigned char*  buffer; /* Data transfer buffer       */
    unsigned char*  curp;   /* Current active pointer     */
    unsigned        istemp; /* Temporary file indicator   */
    short           token;  /* Used for validity checking */
} __FILE;   

#endif
