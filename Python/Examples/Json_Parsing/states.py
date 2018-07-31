#!/usr/bin/env python3

import json
from urllib.request import urlopen

with urlopen("https://finance.yahoo.com/webservice/v1/symbols/allcurrencies/quote?format=json") as response:
	source = response.read()

#print(source)

data = json.loads(source)

usd_rates = dict()

for item in data['list']['resources']:
	name1 = item['resource']['fields']['name']
	price = item['resource']['fields']['price']
#	print(name, price)
	usd_rates[name1] = price

print(usd_rates['USD/EUR'])
#print(len(data['list']['resources']))
#print(json.dumps(data, indent = 2))
#print(json.dumps(data, indent = 2))
#with open('states.json') as f:
#	data = json.load(f)
#	print(data)
#
#for program in data:
#	del program['Kernel']
#
#with open('new_states.json', 'w') as f:
#	json.dump(data, f, indent=2)	
