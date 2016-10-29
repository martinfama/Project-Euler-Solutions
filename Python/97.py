#28433*2^7830457+1

e = 7830457
b = 2
m = 10**15
c = 1

for e_p in xrange(1, e+1):
	c = (b*c)%m

print str(c*28433+1)[-10:]
