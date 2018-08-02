#!/usr/bin/env python3

import unittest
import longest_subsequence2

class TestFindingWords(unittest.TestCase):
	
	def test_finding_words(self):
		self.assertEqual(longest_subsequence2.finding_words('ell', 'hello'), 'ell')
		self.assertNotEqual(longest_subsequence2.finding_words('lel', 'hello'), 'lel')
		self.assertNotEqual(longest_subsequence2.finding_words('helloo', 'hello'), 'helloo')
	
	def test_longest_match(self):
		self.assertEqual(longest_subsequence2.longest_match(['a', 'ab'], 'abc'), 'a')

if __name__ == '__main__':
	unittest.main()

