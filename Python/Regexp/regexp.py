#!/usr/bin/env python3

def wordsWithCapLetters():
	"""
	Args: 
		list_of_input_words - list of input file strings
		list_of_output_words - list of strings for output file
	"""
	with open('words.txt', 'r') as input_file, open('words_with_capital.txt', 'w') as output_file:
		list_of_input_words = [str(x) for x in input_file.read().split()]		
		print(list_of_input_words)
		
		list_of_output_words = []
		for word in list_of_input_words:
			if word[0].isupper():
				list_of_output_words.append(word)
		for element in list_of_output_words:
			print(element, file = output_file)

wordsWithCapLetters()
