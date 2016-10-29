from fractions import Fraction
steps = 10
elements = [0]*steps

for i in range(2, steps+1):
    if i%3 == 0:
        elements[i-1] = Fraction(i*2, 3)
    else:
        elements[i-1] = 1

value = 0
for x in range(10):
    steps = x+1
    if steps > 1:
        value = Fraction(1, elements[steps-1])
    for i in range(steps-2, 0, -1):
        value = Fraction(1, elements[i]+value)
    value += 2
    print Fraction(value)


#print sum(map(int,str(value.numerator)))