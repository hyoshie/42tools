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
	rm -f $VALIDATE_LOG
	rm -f $COUNT_LOG
}

do_test()
{
	for i in $(seq $2); do
		ARG=$(jot -r -s " " $1 $MIN $MAX)
		$EXEC_FILE $ARG | $CHECKER $ARG >> $VALIDATE_LOG
		$EXEC_FILE $ARG | wc -l >> $COUNT_LOG
	done
}

print_usage()
{
	echo "./test.sh [ARG_NUM] [LOOP_COUNT]"
}

print_result()
{
	echo -n "CHECHER: "
	grep -v OK $VALIDATE_LOG
	if [ $? == 1 ]; then
		echo "OK:)"
	else
		echo "NG:("
	fi

	echo -n "AVRAGE: "
	cat $COUNT_LOG | awk '{sum+=$1} END {print sum/NR}'
}

####Main Script#####
if [ $# != 2 ]; then
	print_usage
else
	reset_log
	do_test $1 $2
	print_result
fi
####Main Script#####
