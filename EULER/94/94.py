def area(a, b, c):
	if a == 0 or b == 0 or c == 0:
		return 0.0;
		
	return (b * b - (c / 2.0) * (c / 2.0))**0.5
		
ans = 0
for i in xrange(1, 340000000):
	# if i % 1000000 == 0:
	#	print i
		
	ar = area(i, i, i + 1)
	if ar.is_integer() and i + i + i + 1 <= 1000000000:
		print "FOUND ONE: ", i, " ans so far: ", ans
		ans += i + i + i + 1;
	
	ar = area(i, i, i - 1)
	if ar.is_integer() and i + i + i - 1 <= 1000000000:
		print "FOUND ONE: ", i, " ans so far: ", ans
		ans += i + i + i - 1;
		