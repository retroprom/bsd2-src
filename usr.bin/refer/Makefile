#	@(#)Makefile	4.5.1	(2.11BSD)	1996/10/23
#
DESTDIR=
CFLAGS = -O
SEPFLAG= -i

all:	mkey inv hunt refer addbib lookbib sortbib

mkey: mkey1.o mkey2.o mkey3.o deliv2.o
	${CC} ${SEPFLAG} mkey?.o deliv2.o -o mkey
inv: inv1.o inv2.o inv3.o inv5.o inv6.o deliv2.o
	${CC} ${SEPFLAG} inv?.o deliv2.o -o inv
hunt: hunt1.o hunt2.o hunt3.o hunt5.o hunt6.o hunt7.o glue5.o
hunt: refer3.o hunt9.o shell.o deliv2.o hunt8.o glue4.o tick.o
	${CC} ${SEPFLAG} hunt?.o refer3.o glue5.o glue4.o shell.o deliv2.o tick.o -o hunt

glue3.o: refer..c
hunt2.o: refer..c
hunt3.o: refer..c
refer0.o: refer..c
refer1.o: refer..c
refer2.o: refer..c
refer3.o: refer..c
refer4.o: refer..c
refer6.o: refer..c
refer5.o: refer..c
refer: glue1.o refer1.o refer2.o refer4.o refer5.o refer6.o mkey3.o
refer: refer7.o refer8.o hunt2.o hunt3.o deliv2.o hunt5.o hunt6.o hunt8.o
refer: glue3.o hunt7.o hunt9.o glue2.o glue4.o glue5.o refer0.o shell.o
	${CC} ${SEPFLAG} glue?.o refer[01245678].o hunt[2356789].o mkey3.o \
		shell.o deliv2.o -o refer

addbib: addbib.o
	${CC} ${SEPFLAG} addbib.o -o addbib
lookbib: lookbib.o
	${CC} ${SEPFLAG} lookbib.o -o lookbib
sortbib: sortbib.o
	${CC} ${SEPFLAG} sortbib.o -o sortbib

install: all /usr/dict/papers
	-mkdir -p ${DESTDIR}/usr/libexec/refer
	chmod 755 ${DESTDIR}/usr/libexec/refer
	install -s -m 755 mkey $(DESTDIR)/usr/libexec/refer
	install -s -m 755 inv  $(DESTDIR)/usr/libexec/refer
	install -s -m 755 hunt $(DESTDIR)/usr/libexec/refer
	install -s -m 755 refer $(DESTDIR)/usr/bin
	install -s -m 755 addbib $(DESTDIR)/usr/bin
	install -s -m 755 sortbib $(DESTDIR)/usr/bin
	install -c -m 755 roffbib.sh $(DESTDIR)/usr/bin/roffbib
	install -c -m 755 indxbib.sh $(DESTDIR)/usr/bin/indxbib
	install -s -m 755 lookbib $(DESTDIR)/usr/bin
	install -c -m 444 tmac.bib $(DESTDIR)/usr/share/tmac
	(cd /usr/dict/papers; /bin/sh runinv)

clean:
	rm -f refer inv hunt mkey addbib lookbib sortbib *.o

whatabout: what1.o what2.o what3.o what4.o shell.o mkey3.o
	${CC} ${SEPFLAG} what?.o shell.o mkey3.o  -o whatabout
deliv: deliv1.o deliv2.o
	${CC} ${SEPFLAG} deliv?.o  -o deliv
refpart: refer0.o refer1.o refer2.o refer3.o refer4.o refer5.o
refpart: refer6.o refer7.o refer8.o deliv2.o glue4.o
	${CC} ${SEPFLAG} refer?.o deliv2.o glue4.o  -o refpart
