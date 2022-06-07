#!/bin/bash

EXEC_FILE=./philo
STDOUT_LOG=stdout.log
STDERR_LOG=stderr.log
FAIL=0

store_output()
{
	$EXEC_FILE $@ > $STDOUT_LOG 2>  $STDERR_LOG
}

validate_stdout()
{
	if [ $(grep LEAK $STDERR_LOG | wc -l) != "0" ]; then
		echo "###LEAK###	:" $@
		FAIL=1
	fi
}

validate_stderr()
{
	if [ -s $STDERR_LOG ]; then
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
		# Invalid arg count
		""
		"4"
		"4 410"
		"4 410 200"
		# "4 410 200 200 4"
		"4 410 200 200 4 5"
		# Character
		"a 410 200 200 4"
		"4 a 200 200 4"
		"4 410 a 200 4"
		"4 410 200 a 4"
		"4 410 200 200 a"
		# Including Character
		"4a 410 200 200 4"
		"4 410a 200 200 4"
		"4 410 200a 200 4"
		"4 410 200 200a 4"
		"4 410 200 200 4a"
		# Empty String
		"'' 410 200 200 4"
		"4 '' 200 200 4"
		"4 410 '' 200 4"
		"4 410 200 '' 4"
		"4 410 200 200 ''"
		# 2Space String
		"'  ' 410 200 200 4"
		"4 '  ' 200 200 4"
		"4 410 '  ' 200 4"
		"4 410 200 '  ' 4"
		"4 410 200 200 '  '"
		# minus
		"-4 410 200 200 4"
		"4 -410 200 200 4"
		"4 410 -200 200 4"
		"4 410 200 -200 4"
		"4 410 200 200 -4"
		# + Sign
		"+ 410 200 200 4"
		"4 + 200 200 4"
		"4 410 + 200 4"
		"4 410 200 + 4"
		"4 410 200 200 +"
		# - Sign
		"- 410 200 200 4"
		"4 - 200 200 4"
		"4 410 - 200 4"
		"4 410 200 - 4"
		"4 410 200 200 -"
		# Over Int range
		# "2147483648 410 200 200 4"
		# "4 2147483648  200 200 4"
		# "4 410 2147483648 200 4"
		# "4 410 200 2147483648 4"
		# "4 410 200 200 2147483648"
		# "-2147483649 410 200 200 4"
		# "4 -2147483649  200 200 4"
		# "4 410 -2147483649 200 4"
		# "4 410 200 -2147483649 4"
		# "4 410 200 200 -2147483649"
	)

####Main Script#####
for arg in "${ARGS[@]}"; do
	store_output $arg
	echo $arg
	validate_stdout $arg
	# validate_stderr $arg
done

remove_tmpfiles
print_result
####Main Script#####
