#!/usr/bin/env python3

with open('overlap1.txt', 'r') as input_file1, open('overlap2.txt', 'r') as input_file2, open('result.txt', 'a') as output_file:
	list_of_input1 = [int(x) for x in input_file1.read().split()]
	list_of_input2 = [int(x) for x in input_file2.read().split()]
	list_for_output = [num1 for num1 in list_of_input1 for num2 in list_of_input2 if num1 == num2]	
	res = set(list_for_output)
	
	for element in res:
		print(element, file=output_file)
