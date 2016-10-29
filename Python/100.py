from decimal import *
import math

getcontext().prec = 100

def quadratic(a, b, c):
    return Decimal(((-b)+Decimal(b**2-4*a*c).sqrt())/(2*a))

t = 1070379110496
while 1:
    print t, Decimal(quadratic(1, -1, -((t**2-t)/2.0)))
    t += 1
    raw_input()