curnothing = "90052"
counter = 0
while True:
	curfile = open(curnothing + ".txt", "r")
	str = curfile.read()
	print str
	curnothing = str[16:]