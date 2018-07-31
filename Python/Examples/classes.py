#!/usr/bin/env python3

class Employee:
	
	raise_amt = 1.04

	def __init__(self, first, last, salary):
		self.first = first
		self.last = last
		self.salary = salary
		self.email = first + '.' + last + '@nsda.am'


	def fullname(self):
		return '{} {}'.format(self.first, self.last)
	
	def apply_raise(self):
		self.salary = int(self.salary * self.raise_amt)


class Coordinator(Employee):	
	raise_amt = 1.10
	def __init__(self, first, last, salary, lang):
		super().__init__(first, last, salary)
		self.lang = lang


class Manager(Employee):
	def __init__(self, first, last, salary, employees = None):
		super().__init__(first, last, salary)
		if employees is None:
			self.employees = []
		else:
			self.employees = employees
	
	def add_emp(self, emp):
		if emp not in self.employees:
			self.employees.append(emp)

	def remove_emp(self, emp):
		if emp in self.employees:
			self.employees.remove(emp)
	
	def print_emps(self):
		for emp in self.employees:
			print('-->', emp.fullname())

emp_1 = Employee('Hasmik', 'Kyureghyan', 200000)
emp_2 = Employee('Narek', 'Manukyan', 650000)
print(emp_1.email)
print(emp_2.email)

cor_1 = Coordinator('Ani', 'Ginosyan', 100000, 'Armenian')
cor_2 = Coordinator('Anna', 'Galstyan', 256000, 'Russian')

mgr_1 = Manager('Gagik', 'Ginosyan', 600000, [cor_1])


print(issubclass(Manager, Coordinator)) #check if Manager is a subclass of Coordinator
print(isinstance(mgr_1, Coordinator)) #check if mgr_1 is an instance of Coordinator

#Some additional coding

#	@classmethod
#	def set_raise_amt(cls, amount):
#		cls.raise_amt = amount

#	@classmethod
#	def from_string(cls, emp_string):
#		first, last, salary = emp_string.split('-')
#		return cls(first, last, salary)

#	@staticmethod
#	def is_workday(day):
#		if day.weekday() == 5:
#			return False
#		else:
#			return True


#emp_str_1 = 'Davit-Sahakyan-10'
#emp_str_2 = 'Petros-n-20'
#emp_str_1 = 'Poghos-Poghosyan-30'

#new_emp_1 = Employee.from_string(emp_str_1)

#first, last, salary = emp_str_1.split('-')
#new_emp_1 = Employee(first, last, salary)

#print(new_emp_1.email)
#print(new_emp_1.salary)

#Employee.set_raise_amt(1.05)

#print(Employee.raise_amt)
#print(emp_1.raise_amt)
#print(emp_2.raise_amt)

#import datetime
#my_date = datetime.date(2018, 8, 18)
#print(Employee.is_workday(my_date))
