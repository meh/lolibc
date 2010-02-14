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

#ifndef _LOLIBC_PRIVATE_STDARG_H
#define _LOLIBC_PRIVATE_STDARG_H

enum __lolibc_stdarg_Type {
    Decimal, /* d, i */
    DecimalUnsigned, /* u */
    Octal, /* o */
    Hexadecimal, /* x */
    HexadecimalCAPS, /* X */
    DoubleExponent, /* e */
    DoubleExponentCAPS, /* E */
    Double, /* f */
    DoubleCAPS, /* F */
    DoubleShorter, /* g */
    DoubleShorterCAPS, /* G */
    Char, /* c */
    CharWide, /* lc (C deprecated) */
    String, /* s */
    StringWide, /* ls (S deprecated) */
    Pointer, /* p */
    Printed, /* n */
    Percent, /* % */

    Error, /* m (GNU extension) */
};

size_t __lolibc_stdarg_convert (const char* format, void* argument, char* buffer);

/**
 * Get the placeholder length.
 *
 * @param   format  The format string starting with %
 *
 * @return  The length of the placeholder.
 */
size_t __lolibc_stdarg_placeholder_length (const char* format);

size_t __lolibc_stdarg_length (const char* format, va_list arguments);

size_t __lolibc_stdarg_length_single (const char* format, void* argument);

size_t __lolibc_stdarg_length_Decimal (void);

size_t __lolibc_stdarg_length_DecimalUnsigned (void);

size_t __lolibc_stdarg_length_Octal (void);

size_t __lolibc_stdarg_length_Hexadecimal (void);

size_t __lolibc_stdarg_length_DoubleExponent (void);

size_t __lolibc_stdarg_length_Double (void);

size_t __lolibc_stdarg_length_DoubleShorter (void);

size_t __lolibc_stdarg_length_Char (void);

size_t __lolibc_stdarg_length_CharWide (void);

size_t __lolibc_stdarg_length_Pointer (void);

size_t __lolibc_stdarg_length_Printed (void);

size_t __lolibc_stdarg_max_length (const char* format);

size_t __lolibc_stdarg_max_length_single (const char* format);

inline size_t __lolibc_stdarg_max_length_Decimal (void);

inline size_t __lolibc_stdarg_max_length_DecimalUnsigned (void);

inline size_t __lolibc_stdarg_max_length_Octal (void);

inline size_t __lolibc_stdarg_max_length_Hexadecimal (void);

inline size_t __lolibc_stdarg_max_length_DoubleExponent (void);

inline size_t __lolibc_stdarg_max_length_Double (void);

inline size_t __lolibc_stdarg_max_length_DoubleShorter (void);

inline size_t __lolibc_stdarg_max_length_Char (void);

inline size_t __lolibc_stdarg_max_length_CharWide (void);

inline size_t __lolibc_stdarg_max_length_Pointer (void);

inline size_t __lolibc_stdarg_max_length_Printed (void);

#endif
