#!/bin/zsh

RED="\033[31m"
GREEN="\033[32m"
RESET="\033[0m"

i=0
for arg in $@; do
	echo -n $i ":" $arg " "
	i=$((i+1))
done
echo 

bash -c "< $1 $2 | $3 > bash.log"
echo -n "EXIT_STATUS"= >> bash.log
echo $? >> bash.log

./pipex $1 $2 $3 pipe.log
echo -n "EXIT_STATUS"= >> pipe.log
echo $? >> pipe.log

diff -s bash.log pipe.log > diff.log
if [ $? -eq 0 ]; then
	printf $GREEN"[OK]\n"$RESET
else
	printf $RED"[NG]\n"$RESET
	cat diff.log
fi


