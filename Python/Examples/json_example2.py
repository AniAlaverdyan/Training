#!/usr/bin/env python3

import json

program_string = '''
[
	{
		"Name": "Debian",
		"Version": "9",
		"Install": "apt",
		"Owner": "SPI",
		"Kernel": "4.9"
	},
	{
		"Name": "Gentoo",
		"Version": "Rolling Release",
		"Install": "emerge",
		"Owner": "Gentoo Foundation",
		"Kernel": "4.12"
	}
	
]
'''
data = json.loads(program_string)
for program in data:
	del program['Owner']

new_string = json.dumps(data, indent = 2, sort_keys = True)
print(new_string)

