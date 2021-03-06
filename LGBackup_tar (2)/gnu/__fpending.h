/* Declare __fpending.

   Copyright (C) 2000, 2003, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

   Written by Jim Meyering.  */

#include <linux/stddef.h>  /* kalen.lee@lge.com replace stddef.h with linux/stddef.h */
#include <stdio.h>

#if HAVE_STDIO_EXT_H
# include <stdio_ext.h>
#endif

#ifndef HAVE_DECL___FPENDING
"this configure-time declaration test was not run"
#endif
#if !HAVE_DECL___FPENDING
size_t __fpending (FILE *);
#endif
