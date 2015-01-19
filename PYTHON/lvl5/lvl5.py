import pickle

list = pickle.load(open("lvl5.p", "r"))
for line in list:
	str = ""
	for tupel in line:
		str += tupel[0] * tupel[1]
	print str