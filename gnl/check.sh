#!/bin/bash

#Minus
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=-1 main.c get_next_line.c get_next_line_utils.c -o mytest 
./mytest text

#Big Buffer in Subject
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10000000 main.c get_next_line.c get_next_line_utils.c -o mytest 
./mytest text

#IntMax
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=2147483647 main.c get_next_line.c get_next_line_utils.c -o mytest 
./mytest text

