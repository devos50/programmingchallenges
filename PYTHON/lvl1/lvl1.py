import sys

str = "g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj."

for a in str:
	if a == " " or a == ".":
		sys.stdout.write(a)
	else:
		c = (ord(a) - 97 + 2) % 26 + 97
		sys.stdout.write(chr(c)),