#!/bin/bash
MAPDIR=map/invalid/
MAPS=$(ls $MAPDIR)

#make
# make bonus
for testmap in $MAPS
do
	# printf "\e[36m[$testmap]\n\e[m"
	# ./solong ${MAPDIR}${testmap} 
	valgrind --leak-check=full ./so_long ${MAPDIR}${testmap} 2> log/invalid/$testmap
	NOLEAK=$(grep "All heap blocks were freed" log/invalid/$testmap | wc -l)
	if [ $NOLEAK -eq 1 ]; then
		echo No leaks
	else
		echo " [$testmap]	Leaks detected!"
	fi
done

