#!/usr/bin/env python3

def initList():
	while True:
		try:
			length = int(input('Enter list length: '))	
			if length <= 0:
				raise ValueError("Cannot be <0")
			break
		except ValueError as err:
			print(err)
		except TypeError as err:
			print(err)
	while True:
		try:
			print('Type list values separated by space: ')
			list_of_ints = [int(x) for x in input().split()]
			if length != len(list_of_ints):
				print('Wrong input')
			else:	
				return list_of_ints
		except ValueError as err:
			print(err)
	

def enterIndexForList(list_of_ints):
	""" Get the index value from user.
	Args:
		list_of_ints - list of integers.
	Returns:
 		The index to compare.
	"""
	while True:
		try:
			index = int(input('Type an index value: '))
			if index >= 0 and index <= len(list_of_ints)-1:	
				return index
			else:
				print('Index value is out of bounds')
		except ValueError as err:
			print(err)
		except TypeError as err:
			print(err)		

def mainFunc():
	"""Main function"""

	list_of_ints = initList()	
	index = enterIndexForList(list_of_ints)

	if list_of_ints[index] < list_of_ints[-index]:
		i = index
	else:
		i = -index

	for num in range(1, len(list_of_ints)+1):
		list_of_ints[num-1] = list_of_ints[i]	#set all the elements to the lowest value	
	print(list_of_ints)


mainFunc()
