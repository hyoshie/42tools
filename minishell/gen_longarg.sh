#!/bin/bash

#check near ARG_MAX(262144)

if [ $# != 1 ]; then
	echo "usage: $0 <arg_len>"
	echo "check near ARG_MAX(262144)"
else
	echo -n "cat "
	python -c "print('a' * $1)"
fi
