#	@(#)Makefile	4.1	(Berkeley)	1/1/83
#
CFLAGS=-O

uudiff: lenrem locpart printable run1 trim

lenrem: lenrem.c
	${CC} $(CFLAGS) lenrem.c -o lenrem
locpart: locpart.c
	${CC} $(CFLAGS) locpart.c -o locpart
printable: printable.c
	${CC} $(CFLAGS) printable.c -o printable
run1: run1.c
	${CC} $(CFLAGS) run1.c -o run1
trim: trim.c
	${CC} $(CFLAGS) trim.c -o trim

install:
	: stuff lives here!

clean:
	rm -f *.o lenrem locpart printable run1 trim
