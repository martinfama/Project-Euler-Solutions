import math
abundants = []

total = 0

for i in range(1, 28124):
    current = []
    for x in range(1, int(math.sqrt(i))+1):
        if i % x == 0:
            current.append(x)
            if x != 1 and i/x != x:
                current.append(i/x)
    if sum(current) > i:
        abundants.append(i)
        print i,
        print current
    current[:] = []

print abundants

numbers = []

for i in range(len(abundants)):
    print i
    for x in range(i, len(abundants)):
        if abundants[i]+abundants[x] > 28123:
            break
        numbers.append(abundants[i]+abundants[x])

print numbers
raw_input("a")

for i in range(28124):
    print i
    if not (i in numbers):
        total += i
print total