#!/usr/bin/env bash

if [[ -f "$1" ]]
then
	lines="$( wc -l < $1 )"

	counter=1

	while [ $counter -le $lines ]
	do
		sed "${counter}q;d" $1>>triple_output.txt
		echo " ">>triple_output.txt
		echo " ">>triple_output.txt 	
		((counter++))
	done
else
	echo The file doesn\'t exist.
fi




