#!/usr/bin/env python3

import xml.etree.ElementTree as ET

#data = '''
#<person>
#	<name>Ani</name>
#	<phone type="intl">
#		+98 04 14 38
#	</phone>
#	<email hide="yes"/>
#</person>'''

#tree = ET.fromstring(data)
#print('name:', tree.find('name').text)
#print('Attr:', tree.find('email').get('hide'))

tree = ET.parse('country_data.xml')
root = tree.getroot()

for country in root.findall('country'):
	rank = int(country.find('rank').text)
	if rank > 50:
		root.remove(country)

tree.write('output.xml')

for child in root:
	print(child.attrib)

print(root[0][1].text)

for neighbor in root.iter('neighbor'):
	print(neighbor.attrib)

for country in root.findall('country'):
	rank = country.find('rank').text
	name = country.get('name')
	print(name, rank) 

for country in root.findall('country'):
	rank = int(country.find('rank').text)
	if rank > 50:
		root.remove(country)

	

