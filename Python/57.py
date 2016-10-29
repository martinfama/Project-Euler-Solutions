from fractions import Fraction
steps = 1001
elements = [2]*steps

total = 0
value = 0
for x in range(1, 1001):
    print x
    steps = x+1
    if steps > 1:
        value = Fraction(1, elements[steps-1])
    for i in range(steps-2, 0, -1):
        value = Fraction(1, elements[i]+value)
    value += 1
    if len(str(value.numerator)) > len(str(value.denominator)):
        total += 1
print total