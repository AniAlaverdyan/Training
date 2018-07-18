#!/usr/bin/env bash

who | awk '{print $1,$3,$4}'>>user.txt #print username, date and time info
a=$(finger | sed '1d' | awk '{print $2}') #take real names of logged in users
sed -i "s/$/\t$a/" user.txt #print real names in a separate column





