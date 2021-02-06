#
# Public domain - 1997/1/10 - sms
#
#	@(#)Makefile	1.0 (2.11BSD) 1997/1/10
#
# DESTDIR is defined here to be something which does *NOT* exist - it must be
#  specified on the command line when doing a "make DESTDIR=/mnt distribution".
#  This is aimed at avoiding overwriting the system disk's /etc files.
#
# Example:
#	mount /dev/ra1a /mnt
#	make DESTDIR=/mnt distribution

DESTDIR=/foobar
OWN=root
GRP=wheel

SUBDIR= root uucp
FILES= aliases crontab disktab dtab fstab ftpusers gettytab group hosts \
	hosts.allow hosts.deny inetd.conf inetd.conf.nowrappers \
	motd networks ntp.conf passwd phones printcap protocols \
	rc rc.cleanup rc.conf rc.daemons rc.default rc.filesys rc.local \
	rc.network remote services shells syslog.conf ttys

all install depend lint clean tags:

distribution:
# Device creation scripts
	install -c -o ${OWN} -g ${GRP} -m 555 MAKEDEV MAKEDEV.local \
		${DESTDIR}/dev
# Config files
	install -c -o ${OWN} -g ${GRP} -m 644 ${FILES} ${DESTDIR}/etc
# Security files
	install -c -o root -g wheel -m  600 master.passwd ${DESTDIR}/etc
	install -c -o ${OWN} -g ${GRP} -m 600 hosts.equiv ${DESTDIR}/etc
# Operator files
	install -c -o ${OWN} -g operator -m 664 /dev/null \
		${DESTDIR}/etc/dumpdates
	install -c -o ${OWN} -g operator -m 664 /dev/null \
		${DESTDIR}/etc/sendmail.cw
	install -c -o ${OWN} -g operator -m 664 /dev/null \
		${DESTDIR}/etc/sendmail.fc
# Log and state files
	install -c -o ${OWN} -g ${GRP} -m 644 /dev/null \
	    ${DESTDIR}/usr/adm/messages
	install -c -o ${OWN} -g ${GRP} -m 644 /dev/null \
	    ${DESTDIR}/usr/adm/daemonlog
	install -c -o ${OWN} -g ${GRP} -m 644 /dev/null \
	    ${DESTDIR}/usr/adm/debuglog
	install -c -o ${OWN} -g operator -m 664 /dev/null \
	    ${DESTDIR}/usr/adm/shutdownlog
	install -c -o ${OWN} -g ${GRP} -m 644 /dev/null \
	    ${DESTDIR}/usr/spool/mqueue/syslog
	install -c -o ${OWN} -g ${GRP} -m 644 /dev/null \
	    ${DESTDIR}/usr/adm/lpd-errs
	install -c -o ${OWN} -g ${GRP} -m 644 /dev/null \
	    ${DESTDIR}/var/run/utmp
	install -c -o nobody -g ${GRP} -m 644 /dev/null \
	    ${DESTDIR}/var/db/find.codes
	install -c -o ${OWN} -g ${GRP} -m 644 /dev/null \
	    ${DESTDIR}/usr/adm/lastlog
	install -c -o ${OWN} -g ${GRP} -m 644 /dev/null \
	    ${DESTDIR}/usr/adm/wtmp
	install -c -o ${OWN} -g ${GRP} -m 644 /dev/null \
	    ${DESTDIR}/usr/adm/acct
	install -c -o ${OWN} -g ${GRP} -m 644 /dev/null \
	    ${DESTDIR}/usr/adm/usracct
	install -c -o ${OWN} -g ${GRP} -m 644 /dev/null \
	    ${DESTDIR}/usr/adm/savacct
	install -c -o uucp -g daemon -m 600 /dev/null \
	    ${DESTDIR}/usr/adm/aculog
# Subdirectories
	-for i in ${SUBDIR}; do \
		(cd $$i; make DESTDIR=${DESTDIR} distribution); done
