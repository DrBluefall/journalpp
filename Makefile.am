# Partially lifted from https://www.eyrie.org/~eagle/notes/style/build.html
MAINTAINERCLEANFILES = Makefile.in aclocal.m4 build-aux/compile \
	build-aux/config.guess build-aux/config.sub build-aux/depcomp \
	build-aux/install-sh build-aux/ltmain.sh build-aux/missing \
	config.h.in config.h.in~ configure m4/libtool.m4 m4/ltoptions.m4 \
	m4/ltsugar.m4 m4/ltversion.m4 m4/lt~obsolete.m4 configure~ ltmain.sh \
	build-aux/ar-lib build-aux/test-driver

ACLOCAL_AMFLAGS = -I m4

if DEBUG_INFO
	DEBUGFLAGS = -g3 -O0
endif

AM_CXXFLAGS = $(DEBUGFLAGS)

#====================#
# LIBRARY DEFINITION #
#====================#

lib_LTLIBRARIES = libjournalpp.la

pkginclude_HEADERS = $(srcdir)/include/journalpp/journalpp.h
libjournalpp_la_SOURCES = src/lib.cpp $(pkginclude_HEADERS)
libjournalpp_la_CXXFLAGS = -I $(srcdir)/include -std=c++17

#=========================#
# AUTOMAKE TEST FRAMEWORK #
#=========================#

TESTS = $(check_PROGRAMS)

check_PROGRAMS = test/sanity test/marshalling_fields

test_sanity_SOURCES = test/sanity.cpp
test_sanity_CXXFLAGS = -I $(srcdir)/include
test_sanity_LDADD = libjournalpp.la

test_marshalling_fields_SOURCES = test/marshalling_fields.cpp
test_marshalling_fields_CXXFLAGS = -I $(srcdir)/include
test_marshalling_fields_LDADD = libjournalpp.la
