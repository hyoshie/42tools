#!/bin/bash

EXEC_FILE=./push_swap
STDOUT_LOG=stdout.log
STDERR_LOG=stderr.log
FAIL=0

store_output()
{
	$EXEC_FILE $@ > $STDOUT_LOG 2>  $STDERR_LOG
}

validate_stdout()
{
	if [ $(wc -l $STDOUT_LOG | awk '{print $1}') != "0" ]; then
		echo "EXISTS STDOUT		:" $@
		FAIL=1
	fi
}

validate_stderr()
{
	if [ $(grep Error $STDERR_LOG | wc -l) != "1" ]; then
		echo "INVALID ERROR MASSAGE	:" $@
		FAIL=1
	fi
}

remove_tmpfiles()
{
	rm $STDOUT_LOG
	rm $STDERR_LOG
}

print_result()
{
	if [ $FAIL == 0 ]; then
		printf "\033[32mNice Error Handling!!\033[m"
	else
		printf "\033[31mOops...Missing Error handle\033[m"
	fi
}


ARGS=(
		# Character
		"a 1 2 3"
		"4 a 2 3"
		"4 1 a 3"
		"4 1 2 a"
		# Including Character
		"4a 1 2 3"
		"4 1a 2 3"
		"4 1 2a 3"
		"4 1 2 3a"
		# Empty String
		"'' 1 2 3"
		"4 '' 2 3"
		"4 1 '' 3"
		"4 1 2 ''"
		# 2Space String
		"'  ' 1 2 3"
		"4 '  ' 2 3"
		"4 1 '  ' 3"
		"4 1 2 '  '"
		# Sign
		# "+ 1 2 3"
		# "4 + 2 3"
		# "4 1 + 3"
		# "4 1 2 +"
		# "- 1 2 3"
		# "4 - 2 3"
		# "4 1 - 3"
		# "4 1 2 -"
		# Over Int range
		"2147483648 1 2 3"
		"4 2147483648 2 3"
		"4 1 2147483648 3"
		"4 1 2 2147483648"
		"-2147483649 1 2 3"
		"4 -2147483649 2 3"
		"4 1 -2147483649 3"
		"4 1 2 -2147483649"
		# Duplicate
		"1 1 2 3"
		#  0+number
		"0004 1 2 3"
		# test
		# "4 1 2 2147483647"
	)

####Main Script#####
for arg in "${ARGS[@]}"; do
	# echo -n "Case: "
	# echo $arg
	store_output $arg
	validate_stdout $arg
	validate_stderr $arg
	# echo "OK:)"
done

remove_tmpfiles
print_result
####Main Script#####
