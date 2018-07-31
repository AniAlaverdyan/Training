#!/usr/bin/env python3

import unittest
import unitt

class TestCalc(unittest.TestCase):

	def test_add(self):
		self.assertEqual(unitt.add(10, 5), 15)
		self.assertEqual(unitt.add(-1, 1), 0)
		self.assertEqual(unitt.add(-1, -1), -2)

	def test_subtract(self):
		self.assertEqual(unitt.subtract(10, 5), 5)
		self.assertEqual(unitt.subtract(-1, 1), -2)
		self.assertEqual(unitt.subtract(-1, -1), 0)

	def test_multiply(self):
		self.assertEqual(unitt.multiply(10, 5), 50)
		self.assertEqual(unitt.multiply(-1, 1), -1)
		self.assertEqual(unitt.multiply(-1, -1), 1)

	def test_divide(self):
		self.assertEqual(unitt.divide(10, 5), 2)
		self.assertEqual(unitt.divide(-1, 1), -1)
		self.assertEqual(unitt.divide(-1, -1), 1)
		self.assertEqual(unitt.divide(5, 2), 2.5)
		
		#self.assertRaises(ValueError, unitt.divide, 10, 2)
		with self.assertRaises(ValueError):
			calc.divide(10, 0)
if __name__ == '__main__':
	unittest.main()
