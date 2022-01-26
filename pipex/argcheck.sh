#!/bin/bash

ARGLIST=(
	"infille"
	"infile cat"
	"infile cat cat"
	"infile cat cat pipe.log"
	"infile cat cat pipe.log hoge"
)

argcheck() {
	echo "ARG:" $@
	IFS=" "
	./pipex $@
	IFS=
}

#### Main script ####
# No argument
argcheck

# 1~5 argument
PRE_IFS=$IFS
IFS=
for arg in ${ARGLIST[@]}; do
	argcheck "$arg"
done
IFS=$PRE_IFS
#### Main script ####



##Previous scripts

# echo "arg 0"
# ./pipex 
# echo "arg 1"
# ./pipex infile
# echo "arg 2"
# ./pipex infile cat 
# echo "arg 3"
# ./pipex infile cat cat
# echo "arg 4"
# ./pipex infile cat cat pipe.log
# echo "arg 5"
# ./pipex infile cat cat pipe.log pipe.log

# argcheck infile
# argcheck infile cat
# argcheck infile cat cat
# argcheck infile cat cat pipe.log
# argcheck infile cat cat pipe.log something
