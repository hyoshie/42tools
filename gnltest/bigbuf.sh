#!/bin/bash

rm big.out
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$1 main.c get_next_line.c get_next_line_utils.c -o big.out
./big.out text
