#!/bin/bash

#Minus
echo "BUFFER_SIZE=-1"
read
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=-1 main.c get_next_line.c get_next_line_utils.c -o mytest 
./mytest text

echo "BUFFER_SIZE=10000000(in Subject)"
read
#Big Buffer in Subject
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10000000 main.c get_next_line.c get_next_line_utils.c -o mytest 
./mytest text

echo "BUFFER_SIZE=INT_MAX"
read
#IntMax
# gcc -Wall -Werror -Wextra -D BUFFER_SIZE=2147483647 main.c get_next_line.c get_next_line_utils.c -o mytest 
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=2147483647L main.c get_next_line.c get_next_line_utils.c -o mytest 
./mytest text

rm mytest
