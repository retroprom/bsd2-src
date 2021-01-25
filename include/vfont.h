/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)vfont.h	5.1 (Berkeley) 5/30/85
 */

/*
 * Font data structures for Benson-Varian and Versatec plotters.
 *
 * See vfont(5) for details.
 */

struct header {
	short magic;
	unsigned short size;
	short maxx;
	short maxy;
	short xtend;
};

struct dispatch {
	unsigned short addr;
	short nbytes;
	char up,down,left,right;
	short width;
};
