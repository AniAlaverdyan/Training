#!/usr/bin/env python3

def mainFunc():
	"""
	Args:
	i - index value
	l - list
	Returns:
 	New list
	Rises errors:
  	ValueError
	"""

	if l[i] < l[-i]:
		for num in range(1, len(l)+1):
			l[num-1] = l[i]	#set all the elements to the lowest value	
		print(l)
	else:
		for num in range(1, len(l)+1):
			l[num-1] = l[-i]
		print(l)


def initList():
	while True:
		try:
			length = int(input('Enter list length: '))	
			break
		except ValueError:
			print('Invalid input')
	while True:
		print('Type list values separated by space: ')
		l = [int(x) for x in input().split()]
		if length != len(l):
			print('Wrong input')
		else:
			return l
			break
	

def enterIndexForList(): #ask for index input
	while True:
		index = int(input('Type an index value: '))
		if index >= 0 and index <= len(l)-1:	
			return index
			break
		else:
			print('Index value is out of bounds')

l = initList()	
i = enterIndexForList()

mainFunc()
