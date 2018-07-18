#!/usr/bin/env bash

for i in {60000..63000}
do 
	m=$(echo "sqrt($i)" | bc -l) #square root of i
	int=${m%.*} #integer part of m
	p=1
	for ((k=2; k<=$int; k++))
	do 
		if (( $i % $k != 0 ))
		then
			continue	
		else
			p=0
			break
		fi
	done
	if [ $p -eq 1 ]
	then
		printf "%d\t\t" $i>>cprime.txt #write the number to file
	fi
done
