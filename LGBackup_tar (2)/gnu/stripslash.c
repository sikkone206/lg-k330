/* stripslash.c -- remove redundant trailing slashes from a file name

   Copyright (C) 1990, 2001, 2003-2006 Free Software Foundation, Inc.

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
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

#include <config.h>

#include <sys/types.h>      /* kalen.lee@lge.com add it for size_t */
#include "dirname.h"

/* Remove trailing slashes from FILE.  Return true if a trailing slash
   was removed.  This is useful when using file name completion from a
   shell that adds a "/" after directory names (such as tcsh and
   bash), because on symlinks to directories, several system calls
   have different semantics according to whether a trailing slash is
   present.  */

bool
strip_trailing_slashes (char *file)
{
  char *base = last_component (file);
  char *base_lim;
  bool had_slash;

  /* last_component returns "" for file system roots, but we need to turn
     `///' into `/'.  */
  if (! *base)
    base = file;
  base_lim = base + base_len (base);
  had_slash = (*base_lim != '\0');
  *base_lim = '\0';
  return had_slash;
}
