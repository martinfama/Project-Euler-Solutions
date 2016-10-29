from decimal import *
import math
getcontext().prec = 102
sum = 0
for i in range(2, 100):
    if math.sqrt(i).is_integer():
        continue
    else:
        string = str(Decimal(i).sqrt()*10**99)
        for x in range(len(string)):
            if string[x] == '.':
                break
            sum += int(string[x])
            x += 1

print sum