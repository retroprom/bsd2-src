# shell
unset noglob
set filec
set history=30
if ($?prompt) then
	set prompt="%n@%m:%c> "
endif

# environment
set path=(/bin /sbin /etc /usr/sbin /usr/ucb /usr/bin /usr/new /usr/local)
set mail=( 0 /usr/spool/mail/$USER )

# aliases
alias	mail /usr/ucb/Mail
alias	pwd	'echo $cwd'
alias	h	history
