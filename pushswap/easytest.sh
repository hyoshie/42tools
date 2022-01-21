#!/bin/bash

EXEC_FILE=./push_swap
CHECKER=./checker_Mac
OPERATION_LOG=op.log

test_nonarg()
{
	echo "./push_swap"
	$EXEC_FILE
}

test_each()
{
	echo "./push_swap" $@
	$EXEC_FILE $@ | $CHECKER $@
	$EXEC_FILE $@ | tee $OPERATION_LOG | wc -l
	cat $OPERATION_LOG
}

remove_tmpfiles()
{
	rm $OPERATION_LOG
}

ARGS=(
		"0 1 2 3"
		"5 4 3 2 1"
	)

####Main Script#####
test_nonarg
for arg in "${ARGS[@]}"; do
	read
	test_each $arg
	# echo "./push_swap" $arg
	# $EXEC_FILE $arg | $CHECKER $arg
	# $EXEC_FILE $arg | wc -l
done
remove_tmpfiles
####Main Script#####