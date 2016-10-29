import math
numbers_file = open("99.txt")

max = 0
line_n = 0
i = 1

for line in numbers_file:
    x = 0
    new_string = ""
    while line[x] != ',':
        new_string += line[x]
        x += 1
    base = int(new_string)
    x += 1
    new_string = ""
    while x < len(line):
        new_string += line[x]
        x += 1
    exponents = int(new_string)
    if exponents*math.log10(base) > max:
        max = exponents*math.log10(base)
        line_n = i

    i += 1

print line_n