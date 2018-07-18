#!/usr/bin/env bash

si ()
{
	#check if the argument is an integer
	if [[ "$1" =~ ^[0-9]+$ ]]
	then 
		echo integer
		true
	else
		echo string
		false
	fi	
}
si $1
