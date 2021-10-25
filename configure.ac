
dnl Initialize autoconf, automake, and libtool.
AC_PREREQ([2.71])
AC_INIT([libjournalpp], [1.0])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE([-Wall -Werror subdir-objects silent-rules foreign])
AM_PROG_AR
LT_INIT

dnl Add copyright notice.
AC_COPYRIGHT([
Copyright (C) 2021 Alexander Bisono.

libjournalpp is free software: you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free
Software Foundation, either version 3 of the License, or (at your option) any
later version.

libjournalpp is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with libjournalpp. If not, see <https://www.gnu.org/licenses/>.
])

dnl Ask if we're doing a debug build.
AC_ARG_ENABLE([debug],
    [AS_HELP_STRING([--enable-debug],
    [Include debugging information within the library. Use with `--disable-shared` in order to build static
    test binaries that can more easily be run under a debugger. (default is no)])]
    [enable_debug=$withval],
    [: m4_divert_text([DEFAULTS], [enable_debug=no])])

AM_CONDITIONAL([DEBUG_INFO], [test "x$enable_debug" != xno])

dnl Check for a functional C++ compiler.
AC_PROG_CXX

dnl Configure and output all files.
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
