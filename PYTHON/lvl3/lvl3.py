import re

file = open("lvl3.in", "r")
str = file.read()
str = str.translate(None, "\n")

m = re.findall(r'[a-z]{1}[A-Z]{3}[a-z]{1}[A-Z]{3}[a-z]{1}', str)
print m