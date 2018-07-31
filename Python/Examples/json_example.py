#!/usr/bin/env python3

json_string = '{"first_name": "Ani", "last_name":"Alaverdyan"}'

import json
parsed_json = json.loads(json_string)

print(parsed_json['first_name'])

data = [{'name':'Ani', 'surname':'Alaverdyan', 'age':'22'}]
json_data = json.dumps(data)
print(json_data)
json_decoded = json.loads(json_data)
print(json_decoded)
