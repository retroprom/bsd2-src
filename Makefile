#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	4.16	(2.11BSD)	2020/1/4
#
# This makefile is designed to be run as:
#	make build
#	make installsrc
# The `make build' will compile and install the libraries
# before building the rest of the sources. The `make installsrc'
# will then install the remaining binaries.
#
# It can also be run in the more conventional way:
#	make
#	make install
# The `make' will compile everything without installing anything.
# The `make install' will then install everything. Note however
# that all the binaries will have been loaded with the old libraries.
#

# global flags
# SRC_MFLAGS are used on makes in command source directories,
# but not in library or compiler directories that will be installed
# for use in compiling everything else.
#
DESTDIR=
CFLAGS=-O
SRC_MFLAGS=

# Programs that live in subdirectories, and have makefiles of their own.
#
# 'share' has to be towards the front of the list because programs such as
# lint(1) need their data files, etc installed first.
#
LIBDIR=include lib usr.lib
SRCDIR=share bin sbin etc games libexec local new ucb usr.bin usr.sbin man
SYSDIR=sys/GENERIC sys/pdpstand

# all - Build everything without concern for bootstrap
#
all: ${LIBDIR} ${SRCDIR}

# build - Main build target
#
# This target performs a standard system build. The toolchain is built
# and installed first. After that the rest of the system is built.
#
build: buildlib buildsrc FRC

# buildlib - Toolchain bootstrap
#
# The following procedure builds and installs the toolchain. Everything is
# built two times so that the C compiler is linked against the new libc.
#
# The initial build order for the compiler is important for compatibility
# with host systems below patch #460 because this patch modernizes the
# compiler and requires a specific bootstrap procedure.
#
buildlib: FRC
	@echo installing includes
	cd include; make ${MFLAGS} DESTDIR=${DESTDIR} install
	@echo
	@echo compiling libc.a
	cd lib/libc; make ${MFLAGS}
	@echo installing /lib/libc.a
	cd lib/libc; make ${MFLAGS} DESTDIR=${DESTDIR} install
	@echo
	@echo compiling C compiler
	cd bin; make ${MFLAGS} cc
	cd lib; make ${MFLAGS} ccom c2
	@echo installing C compiler
	install -m 755 -o root -g wheel bin/cc ${DESTDIR}/bin/cc
	cd lib/ccom; make ${MFLAGS} DESTDIR=${DESTDIR} install
	cd lib/c2; make ${MFLAGS} DESTDIR=${DESTDIR} install
	@echo compiling C preprocessor
	cd lib; make ${MFLAGS} cpp
	@echo installing C preprocessor
	cd lib/cpp; make ${MFLAGS} DESTDIR=${DESTDIR} install
	@echo
	@echo cleaning up
	cd lib; make ${MFLAGS} clean
	@echo
	@echo re-compiling libc.a
	cd lib/libc; make ${MFLAGS}
	@echo re-installing /lib/libc.a
	cd lib/libc; make ${MFLAGS} DESTDIR=${DESTDIR} install
	@echo
	@echo re-compiling C compiler
	cd lib; make ${MFLAGS} ccom cpp c2
	@echo re-installing C compiler
	cd lib/ccom; make ${MFLAGS} DESTDIR=${DESTDIR} install
	cd lib/cpp; make ${MFLAGS} DESTDIR=${DESTDIR} install
	cd lib/c2; make ${MFLAGS} DESTDIR=${DESTDIR} install
	@echo
	@echo compiling usr.lib
	cd usr.lib; make ${MFLAGS}
	@echo installing /usr/lib
	cd usr.lib; make ${MFLAGS} DESTDIR=${DESTDIR} install

# buildsrc - Main system build
#
buildsrc: ${SRCDIR} FRC

# buildsrc - Kernel and loader build
#
buildsys: ${SYSDIR} FRC

# install - Install the entire world
#
install:
	-for i in ${LIBDIR} ${SRCDIR}; do \
		(cd $$i; \
		make ${MFLAGS} DESTDIR=${DESTDIR} install); \
	done

# installsrc - Install everything except for the toolchain
#
installsrc:
	-for i in ${SRCDIR}; do \
		(cd $$i; \
		make ${MFLAGS} DESTDIR=${DESTDIR} install); \
	done

# installsys - Install kernel and loaders
installsys:
	@echo Installing GENERIC kernel
	cd sys/GENERIC; make ${MFLAGS} DESTDIR=${DESTDIR} geninstall
	@echo
	@echo Installing standalone programs
	cd sys/pdpstand; make ${MFLAGS} DESTDIR=${DESTDIR} install

# distribution - Install a clean distribution
#
distribution:
	./makedirs "${DESTDIR}"
	-for i in ${LIBDIR} ${SRCDIR}; do \
		(cd $$i; \
		make ${MFLAGS} DESTDIR=${DESTDIR} install); \
	done

# tags - Update runtime tags file
#
tags:
	for i in ${LIBDIR}; do \
		(cd $$i; make ${MFLAGS} TAGSFILE=../tags tags); \
	done
	sort -u +0 -1 -o tags tags

# clean - Remove build output
#
clean:
	rm -f a.out core *.s *.o
	for i in ${LIBDIR} ${SRCDIR} ${SYSDIR}; do \
		(cd $$i; make -k ${MFLAGS} clean); \
	done

# Rule for building subdirectories
#
${LIBDIR} ${SRCDIR} ${SYSDIR}: FRC
	cd $@; make ${MFLAGS}

# Dummy rule
FRC:
