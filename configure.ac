
dnl Initialize autoconf, automake, and libtool.
AC_PREREQ([2.71])
AC_INIT([libjournalpp], [0.0])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE([-Wall -Werror subdir-objects silent-rules foreign])
AM_PROG_AR
LT_INIT

dnl Check for a functional C++ compiler.
AC_PROG_CXX

dnl Configure and output all files.
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
