#!/bin/bash

# make inputfile
cat << EOF > infile
aaaaa
bbbbb
ccccc

aaaaa
bbbbb 
ccccc 
EOF

# make not_readable file
echo "NOT READ" > non_read
chmod -r non_read

# make not_writable file
echo "NOT WRITE" > non_write
chmod -w non_write

# make bigfile
python -c "print('a' * 800000)" > bigfile
