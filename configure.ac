
dnl Initialize autoconf, automake, and libtool.
AC_PREREQ([2.71])
AC_INIT([libjournalpp], [0.0])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE([-Wall -Werror subdir-objects silent-rules foreign])
AM_PROG_AR
LT_INIT

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
