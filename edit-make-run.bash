#!/bin/bash
#    ______               __  __            __             
#   / ____/_  ____  __   / / / /_  ______ _/ /_  ___  _____
#  / / __/ / / / / / /  / /_/ / / / / __ `/ __ \/ _ \/ ___/
# / /_/ / /_/ / /_/ /  / __  / /_/ / /_/ / / / /  __(__  ) 
# \____/\__,_/\__, /  /_/ /_/\__,_/\__, /_/ /_/\___/____/  
#            /____/               /____/                   

A="$1"
quick_sexy_date () {
  echo "$(date +%H:%M:%S)"
}
quick_sexy_line () {
  echo "--------------------------------------------------------------------------------"
  
}
files="$(find . -type f -regextype posix-extended -regex .\*$1.\*\.c | tr '\n' ' ')"
binaries="$(echo "$files" | sed -e 's/\.c\s/ /g')"
quick_sexy_line
printf "$(quick_sexy_date): $0 operating on the target set\n\t{ $files }\n"
while true; do
  quick_sexy_line
  vim $files 
  echo "$(quick_sexy_date): making target set"
  make $binaries &&\
    for binary in "$binaries"; do
      quick_sexy_line
      echo "$(quick_sexy_date): executing $binary"
      $binary
      quick_sexy_line
    done;
  printf "Continue [Y/n]?\t"
  read pause_here_nicely_please
  if [ "$pause_here_nicely_please" = "n" ]; then
    break
  fi
done
