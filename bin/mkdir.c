/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#if	!defined(lint) && defined(DOSCCS)
char copyright[] =
"@(#) Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";

static char sccsid[] = "@(#)mkdir.c	5.7 (Berkeley) 5/31/90";
#endif /* not lint */

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int errno;

int pflag;
int vflag;
int mode;

int build();
int create();
int usage();

main(argc, argv)
	int argc;
	char **argv;
{
	extern int optind;
	mode_t *set;
	int ch, exitval;

	pflag = vflag = 0; mode = 0777;
	while ((ch = getopt(argc, argv, "pvm:")) != EOF)
		switch(ch) {
		case 'p':
			pflag = 1;
			break;
		case 'v':
			vflag = 1;
			break;
		case 'm':
			if (!(set = (mode_t *)setmode(optarg)))
				err("%s: invalid file mode", optarg);
			mode = getmode(set, 0);
			umask(0);
			break;
		case '?':
		default:
			usage();
		}

	if (!*(argv += optind))
		usage();

	for (exitval = 0; *argv; ++argv)
		if (pflag)
			exitval |= build(*argv, mode);
		else if (create(*argv))
			exitval = 1;

	exit(exitval);
}

build(path)
	char *path;
{
	register char *p;
	struct stat sb;
	int ch;

	for (p = path;; ++p)
		if (!*p || *p  == '/') {
			ch = *p;
			*p = '\0';
			if (stat(path, &sb)) {
				if (errno != ENOENT || create(path)) {
					return(1);
				}
			}
			if (!(*p = ch))
				break;
		}

	return(0);
}

create(path)
     char *path;
{
	if (mkdir(path, mode) < 0) {
		if (!pflag || errno != EEXIST) {
			(void)fprintf(stderr, "mkdir: %s: %s\n",
				      path, strerror(errno));
			return(1);
		}
	}
	if(vflag)
		(void)fprintf(stderr, "mkdir: created directory '%s'\n", path);
	return(0);
}

usage()
{
	(void)fprintf(stderr, "usage: mkdir [-pv] [-m mode] dirname ...\n");
	exit(1);
}
