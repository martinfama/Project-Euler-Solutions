total = 0
for i in range(10, 10000000):
    number = str(i)
    current = 0
    for x in range(len(number)):
        current += int(number[x])**5
    if current == i:
        total += current
        print current

print total