#!/bin/bash

rm intmax.out
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=2147483647 main.c get_next_line.c get_next_line_utils.c -o intmax.out
./intmax.out text
