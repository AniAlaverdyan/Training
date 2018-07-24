#!/usr/bin/env python3

import re
def wordsWithCapLettersR():
	with open('words.txt', 'r') as input_file, open('words_with_capital.txt', 'w') as output_file:
		list_of_matches = re.findall(r'\b[A-Z]+[a-z]*[A-Z]*\b', input_file.read())
		print(list_of_matches)

wordsWithCapLettersR()
