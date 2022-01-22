#!/bin/bash

function dupcat ()
{
	i=0
	while [ $i -le 1000 ]
	do
		echo -n "cat | "
		i=$((i+1))
	done
}

dupcat
