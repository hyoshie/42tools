#!/bin/bash

#Minus
echo "BUFFER_SIZE=$1"
read
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$1 main.c get_next_line.c get_next_line_utils.c -o mytest 
./mytest text
