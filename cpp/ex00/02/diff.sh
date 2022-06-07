#!/bin/bash

intra_log=19920104_091532.log

if [ -f "$intra_log" ]; then
	echo exist
else
	curl -O https://projects.intra.42.fr/uploads/document/document/4666/19920104_091532.log
fi

make
./bank > myprog.log

cut -d ' ' -f 2- myprog.log > myprog_no_timestamp.log
cut -d ' ' -f 2- 19920104_091532.log > intra_no_timestamp.log

diff myprog_no_timestamp.log intra_no_timestamp.log

rm myprog.log myprog_no_timestamp.log intra_no_timestamp.log
