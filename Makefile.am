# Copyright (C) 2021 Alexander Bisono.
#
# This file is part of libjournalpp.
#
# libjournalpp is free software: you can redistribute it and/or modify it under
# the terms of the GNU Lesser General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option) any
# later version.
#
# libjournalpp is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License along
# with libjournalpp. If not, see <https://www.gnu.org/licenses/>.


# Partially lifted from https://www.eyrie.org/~eagle/notes/style/build.html
MAINTAINERCLEANFILES = Makefile.in aclocal.m4 build-aux/compile \
	build-aux/config.guess build-aux/config.sub build-aux/depcomp \
	build-aux/install-sh build-aux/ltmain.sh build-aux/missing \
	config.h.in config.h.in~ configure m4/libtool.m4 m4/ltoptions.m4 \
	m4/ltsugar.m4 m4/ltversion.m4 m4/lt~obsolete.m4 configure~ ltmain.sh \
	build-aux/ar-lib build-aux/test-driver build-aux/mdate-sh \
	build-aux/texinfo.tex

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

info_TEXINFOS = doc/journalpp.texi
doc_journalpp_index_TEXINFOS = doc/fdl.texi

#=========================#
# AUTOMAKE TEST FRAMEWORK #
#=========================#

TESTS = $(check_PROGRAMS)

check_PROGRAMS = test/sanity test/marshalling_fields test/high_level_log

test_sanity_SOURCES = test/sanity.cpp
test_sanity_CXXFLAGS = -I $(srcdir)/include
test_sanity_LDADD = libjournalpp.la

test_marshalling_fields_SOURCES = test/marshalling_fields.cpp
test_marshalling_fields_CXXFLAGS = -I $(srcdir)/include
test_marshalling_fields_LDADD = libjournalpp.la

test_high_level_log_SOURCES = test/high_level_log.cpp
test_high_level_log_CXXFLAGS = -I $(srcdir)/include
test_high_level_log_LDADD = libjournalpp.la
