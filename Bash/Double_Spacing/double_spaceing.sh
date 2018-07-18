#!/usr/bin/env bash

#check if the given file exists
if [[ -f "$1" ]] 
then 
	#count the number of lines in the file
	lines="$( wc -l < $1 )" 

	counter=1

	while [ $counter -le $lines ]
	#print a line back to the output file as well as print a blank line
	do  	
		sed "${counter}q;d" $1>>double_output.txt 
		echo " ">>double_output.txt
		((counter++))
	done
else
	echo The file doesn\'t exist.
fi




