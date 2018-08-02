#!/usr/bin/env python3

import time
start = time.time()

import argparse

def longest_match(D, S):
	""" Takes a list of words and a string.
	Args:
		list_of_words - list passed from command line
		matching_words_list - a list that contains all of the matched words
	Prints:
		the longest word of the given list which is a subsequence of the given string
	"""

	matching_words_list = []

	for word in D: #list_of_words
		a = finding_words(word, S)
		if finding_words(word, S) != '':
			matching_words_list.append(finding_words(word, S))
	
	
	if len(matching_words_list) !=0:
		print(matching_words_list)
		print(max(matching_words_list, key = len))
	else:
		print('No matches.')


def finding_words(word, S):
	""" Takes a word from list and a string.
	Args: 
		matching_word - word that is being checked to find out if it is a subsequence of the given string
		index - index of element of the given string
	Returns:
		matched word
	"""

	matching_word = ''
	index = 0
	#if index <= len(S)-1:
	for letter in word:
		if S.find(letter, index) != -1:
			matching_word += letter
			index = S.find(letter, index) + 1
		else:
			matching_word = ''
			break	
	return matching_word
        
def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('string')
	parser.add_argument('-l', '--list', nargs = '+', required = True)
	args = parser.parse_args()
	S = str(args.string)
	D = args.list
	longest_match(D, S)

if __name__=='__main__':	
	main()

end = time.time()
print(f'Total time = {end - start}')

