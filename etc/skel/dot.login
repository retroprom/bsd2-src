# set umask
umask 26

# set control keys
stty dec erase ^H kill ^U eof ^D

# ask for terminal type if needed
if ( "$TERM" == dialup || "$TERM" == network) then
  setenv TERM vt100
  echo -n "Terminal ($TERM)? "
  set argv = "$<"
  if ( "$argv" != '' ) setenv TERM "$argv"
endif

# mail notification
biff y
