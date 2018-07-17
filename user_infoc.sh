#!/usr/bin/env bash

who | awk '{print $1,$3,$4}'>>user.txt
a=$(finger | sed '1d' | awk '{print $2}')
sed -i "s/$/\t$a/" user.txt





