#
# arcv makefile
#

SEPFLAG=-i
DEFS=	
CFLAGS=	-O ${DEFS}

SRCS=	arcv.c
OBJS=	arcv.o

all: ${OBJS}
	${CC} ${SEPFLAG} ${OBJS} -o arcv

install:
	install -s arcv ${DESTDIR}/usr/old/arcv

clean:
	rm -f arcv *.o core
