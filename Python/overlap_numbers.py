#!/usr/bin/env python3

num_lines = 0
with open('overlap1.txt', 'r') as i1, open('overlap2.txt', 'r') as i2, open('result.txt', 'a') as o:
	l1 = [int(x) for x in i1.read().split()]
	l2 = [int(x) for x in i2.read().split()]
	l = [num1 for num1 in l1 for num2 in l2 if num1 == num2]	
	o.write(str(set(l)))
print(l1)
print(l2)
