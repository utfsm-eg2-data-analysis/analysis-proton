#
# ~/.bashrc: executed by bash(1) for non-login shells.
#see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
#for examples
#
#If not running interactively, don't do anything
#se $- in
#  *i*) ;;
#    *) return;;
#ac
#
#don't put duplicate lines or lines starting with space in the history.
#See bash(1) for more options
#STCONTROL=ignoreboth
#
#append to the history file, don't overwrite it
#opt -s histappend
#
#for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
#STSIZE=1000
#STFILESIZE=2000
#
#check the window size after each command and, if necessary,
#update the values of LINES and COLUMNS.
#opt -s checkwinsize
#
#If set, the pattern "**" used in a pathname expansion context will
#match all files and zero or more directories and subdirectories.
#hopt -s globstar
#
#make less more friendly for non-text input files, see lesspipe(1)
#-x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"
#
#set variable identifying the chroot you work in (used in the prompt below)
# [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
#  debian_chroot=$(cat /etc/debian_chroot)
#
#
#set a fancy prompt (non-color, unless we know we "want" color)
#se "$TERM" in
#  xterm-color|*-256color) color_prompt=yes;;
#ac
#
#uncomment for a colored prompt, if the terminal has the capability; turned
#off by default to not distract the user: the focus in a terminal window
#should be on the output of commands, not on the prompt
#orce_color_prompt=yes
#
# [ -n "$force_color_prompt" ]; then
#  if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
#	# We have color support; assume it's compliant with Ecma-48
#	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
#	# a case would tend to support setf rather than setaf.)
#	color_prompt=yes
#  else
#	color_prompt=
#  fi
#
#
# [ "$color_prompt" = yes ]; then
#  PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
#se
#  PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
#
#set color_prompt force_color_prompt
#
#If this is an xterm set the title to user@host:dir
#se "$TERM" in
#erm*|rxvt*)
#  PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
#  ;;
#
#  ;;
#ac
#
#enable color support of ls and also add handy aliases
# [ -x /usr/bin/dircolors ]; then
#  test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
#  alias ls='ls --color=auto'
#  #alias dir='dir --color=auto'
#  #alias vdir='vdir --color=auto'
#
#  alias grep='grep --color=auto'
#  alias fgrep='fgrep --color=auto'
#  alias egrep='egrep --color=auto'
#
#
#colored GCC warnings and errors
#xport GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'
#
#some more ls aliases
#ias ll='ls -alF'
#ias la='ls -A'
#ias l='ls -CF'
#
#Add an "alert" alias for long running commands.  Use like so:
#  sleep 10; alert
#ias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'
#
#Alias definitions.
#You may want to put all your additions into a separate file like
#~/.bash_aliases, instead of adding them here directly.
#See /usr/share/doc/bash-doc/examples in the bash-doc package.
#
# [ -f ~/.bash_aliases ]; then
#  . ~/.bash_aliases
#
#
#enable programmable completion features (you don't need to enable
#this, if it's already enabled in /etc/bash.bashrc and /etc/profile
#sources /etc/bash.bashrc).
# ! shopt -oq posix; then
#if [ -f /usr/share/bash-completion/bash_completion ]; then
#  . /usr/share/bash-completion/bash_completion
#elif [ -f /etc/bash_completion ]; then
#  . /etc/bash_completion
#fi
#


alias reload='source ~/.bashrc'
alias clean='rm *~'

export PATH=/site/bin:$PATH

source /u/apps/root/6.22.06/setroot_CUE.bash
alias root='root -l'

export OS_NAME=`uname`
export OSNAME=${OS_NAME}

export CLASTOOL=${HOME}/volatile/ClasTool
export CLAS_LIB=${HOME}/volatile/clas_lib
export CLAS_PACK=${HOME}/volatile/clas_pack

export PATH=${CLASTOOL}/bin/${OSNAME}:${PATH}
export ROOT_INCLUDE_PATH=${CLASTOOL}/include:${ROOT_INCLUDE_PATH}
export LD_LIBRARY_PATH=${CLASTOOL}/slib/${OS_NAME}:${LD_LIBRARY_PATH}
