import re

string = """
 1234-4567-7894
 4577-7894-8876

 Mr. Nirav
 Mrs. Jain
 Ms Angelina

 nirav@gmail.com
 dhaiwe765_@qweasd.com

 https://www.outlook.com
 www.google.com

"""

#Phone Number
regex = r'\d{4}[-*.]\d{4}[-*.]\d{4}'
print(re.findall(regex,string))

#Names
regex = r'M[rs][s]?[.]?\s[A-Z][a-z]*'
print(re.findall(regex,string))

#email_id
regex = r'\w+@[a-z]*[.]com'
print(re.findall(regex,string))

#website
regex = r'[https://]*www[.]\w*[.]com'
print(re.findall(regex,string))