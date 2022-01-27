#!/bin/bash

git clone https://github.com/alelievr/libft-unit-test.git ../../libft-unit-test
##???
make -C ../
cp ../libft.a ../libft.h .
make -C ../ clean
