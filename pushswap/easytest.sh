#!/bin/bash

EXEC_FILE=./push_swap
CHECKER=./checker_Mac
OPERATION_LOG=op.log

test_nonarg()
{
	echo "--Case(No argument)--"
	echo "./push_swap"
	$EXEC_FILE
}

test_each()
{
	echo "--Case--"
	echo "./push_swap" $@
	echo
	$EXEC_FILE $@ | $CHECKER $@
	echo
	echo "--Operation--"
	$EXEC_FILE $@
	echo
	echo "--Operation Num--"
	$EXEC_FILE $@ | wc -l
	echo
}

ARGS=(
		"42"
		"0 1 2 3"
		"0 1 2 3 4 5 6 7 8 9"
		"2 1 0"
		"1 5 2 4 3"
	)

####Main Script#####
test_nonarg
for arg in "${ARGS[@]}"; do
	read
	test_each $arg
done
####Main Script#####
