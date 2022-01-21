#!/bin/bash

EXEC_FILE=./push_swap
CHECKER=./checker_Mac
MIN=-2147483648
MAX=2147483647
VALIDATE_LOG=validate.log
COUNT_LOG=count.log
FAIL=0

reset_log()
{
	rm $VALIDATE_LOG
	rm $COUNT_LOG
}


validate_operation()
{
	for i in $(seq $2); do
		ARG=$(jot -r -s " " $1 $MIN $MAX)
		# echo $ARG
		$EXEC_FILE $ARG | $CHECKER $ARG >> $VALIDATE_LOG
	done
	grep -v OK $VALIDATE_LOG
}

count_operation()
{
	for i in $(seq $2); do
		ARG=$(jot -r -s " " $1 $MIN $MAX)
		$EXEC_FILE $ARG | wc -l >> $COUNT_LOG
	done
}

print_usage()
{
	echo "./test.sh [ARG_NUM] [LOOP_COUNT]"
}

print_result()
{
	echo -n "AVRAGE: "
	cat $COUNT_LOG | awk '{sum+=$1} END {print sum/NR}'
}

####Main Script#####
if [ $# != 2 ]; then
	print_usage
else
	reset_log
	validate_operation $1 $2
	count_operation $1 $2
	print_result
fi
####Main Script#####
