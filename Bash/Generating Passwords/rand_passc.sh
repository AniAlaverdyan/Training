#!/usr/bin/env bash

for (( ; ; ))
do
	int=0; #number of integers
	pass=$(< /dev/urandom tr -dc _[:alnum:] | head -c8) #random string
	for (( i=1; i<=8; i++ ))
	do
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
