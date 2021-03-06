/ getw/getc -- get words/characters from input file
/ fopen -- open a file for use by get(c|w)

indir = 0

.globl	_getc, _getw, _fopen
.comm	_errno,2

_fopen:
	mov	r5,-(sp)
	mov	sp,r5
	clr	-(sp)
	mov	4(r5),-(sp)
	jsr	pc,_open
	cmp	(sp)+,(sp)+
	tst	r0
	bmi	badret
	mov	6(r5),r1
	mov	r0,(r1)+
	clr	(r1)+
	clr	r0
	mov	(sp)+,r5
	rts	pc

_getw:
	clr	_errno
	mov	r5,-(sp)
	mov	sp,r5
	mov	4(r5),r1
	sub	$2,2(r1)
	bge	1f
	cmp	2(r1),$-1
	blt	2f
	movb	*4(r1),-(sp)
	jsr	pc,fill
	mov	4(r1),r0
	br	3f
2:
	jsr	pc,fill
	dec	2(r1)
1:
	mov	4(r1),r0
	movb	(r0)+,-(sp)
3:
	movb	(r0)+,1(sp)
	mov	r0,4(r1)
	mov	(sp)+,r0
	mov	(sp)+,r5
	rts	pc

_getc:
	mov	r5,-(sp)
	mov	sp,r5
	mov	4(r5),r1
	dec	2(r1)
	bge	1f
	jsr	pc,fill
1:
	clr	r0
	bisb	*4(r1),r0
	inc	4(r1)
	mov	(sp)+,r5
	rts	pc

fill:
	mov	r1,r0
	add	$6,r0
	mov	r0,4(r1)
	mov	$512.,-(sp)
	mov	r0,-(sp)
	mov	(r1),-(sp)
	jsr	pc,_read
	add	$6,sp
	tst	r0
	bmi	badret
	dec	r0
	bmi	badret
	mov	r0,2(r1)
	rts	pc

badret:
	mov	r5,sp
	mov	(sp)+,r5
	rts	pc
