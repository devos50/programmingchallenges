file = open("lvl2.in", "r")
str = file.read()

# remove characters
str = str.translate(None, "\n{]%}*#^!$[)&@(+_")

print(str)