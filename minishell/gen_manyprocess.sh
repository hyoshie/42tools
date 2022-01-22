#!/bin/bash

PROCESS_NUM=$1

if [ $# != 1 ]; then
	echo "usage: $0 <process_num>"
	echo "check near process limit(709)"
else
	echo -n "echo a | "
	i=2
	while [ "$i" -lt $PROCESS_NUM ] ; do
		echo -n "cat | "
		i=$((i+1))
	done
	echo -n "cat"
fi
