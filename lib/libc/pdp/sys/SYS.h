/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)SYS.h	1.6 (2.11BSD) 2020/1/7
 */

#include <syscall.h>

.comm	_errno,2

#ifdef __STDC__
#define __CONC(x,y)		x ## y
#else
#define __CONC(x,y)		x/**/y
#endif
 
#define ENTRY(x)	.globl __CONC(_,x); \
		__CONC(_,x): \
			PROFCODE(__CONC(_,x));
#define ASENTRY(x)	.globl x; \
		x: \
			PROFCODE(x);

#ifdef PROF
#define	PROFCODE(x)	.data; \
		1:	x+1; \
			.text; \
			.globl	mcount; \
			mov	$1b, r0; \
			jsr	pc,mcount;
#else /* !PROF */
#define	PROFCODE(x)	;
#endif /* PROF */

#define	SYS(s)		sys	__CONC(SYS_,s).

#define	SYSCALL(s, r)	ENTRY(s); \
			SYS(s); \
			__CONC(EXIT_,r)

		.globl	x_norm, x_error

#define	EXIT_norm		jmp	x_norm

#define	EXIT_long		bcc	1f; \
				mov	r0,_errno; \
				mov	$-1,r1; \
				sxt	r0; \
				1: rts	pc;

#define	EXIT_error		jmp	x_error

#define	EXIT_noerror		rts	pc;
