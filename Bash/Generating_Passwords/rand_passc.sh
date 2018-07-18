#!/usr/bin/env bash

for (( ; ; ))
do
	int=0; #number of integers existing in the generated password
	pass=$(< /dev/urandom tr -dc _[:alnum:] | head -c8) #random 8-b string
	for (( i=1; i<=8; i++ )) #check all characters of the string 
	do
		#check if the character is an integer
		if [[ "$(echo $pass | cut -b $i)" =~ ^[0-9]+$ ]] 
		then 
			((int++))
		fi
	done

	if [ $int -ge 2 ]
	then
		echo Your random password is $pass
		break
	fi	
done
