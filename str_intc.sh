#!/usr/bin/env bash

si ()
{
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
