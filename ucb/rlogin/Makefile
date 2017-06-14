#
# Public Domain.  1996/11/16 - Steven Schultz
#
#	@(#)Makefile	1.0 (2.11BSD) 2000/5/17
#
CFLAGS=	 -O
SEPFLAG= -i
SRCS=	rlogin.c
OBJS=	rlogin.o
MAN=	rlogin.0
MANSRC=	rlogin.1

all: rlogin rlogin.0

rlogin: ${OBJS}
	${CC} ${CFLAGS} ${SEPFLAG} -o $@ ${OBJS}

rlogin.0: ${MANSRC}
	/usr/man/manroff ${MANSRC} > ${MAN}

clean:
	rm -f ${OBJS} ${MAN} rlogin tags 

depend: ${SRCS}
	mkdep ${CFLAGS} ${SRCS}

install: rlogin
	install -c -o bin -g bin -m 444 ${MAN} ${DESTDIR}/usr/man/cat1
	install -s -o root -g bin -m 4755 rlogin ${DESTDIR}/usr/ucb/rlogin

lint: ${SRCS}
	lint -hax ${SRCS}

tags: ${SRCS}
	ctags ${SRCS}
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
