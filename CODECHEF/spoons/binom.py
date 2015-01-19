from operator import mul    # or mul=lambda x,y:x*y
import sys

nCk = lambda n,k: int(round(
    reduce(mul, (float(n-i)/(i+1) for i in range(k)), 1)
))

s = ""
for n in range(65):
	sys.stdout.write(str(nCk(n, n / 2)) + ",")
	
print s