counter = 0
for i in range(100):
    x = 1
    while 1:
        number = x**i
        length = len(str(number))
        if length > i:
            break
        elif length == i:
            print str(number) + " = " + str(x) + "^" + str(i)
            counter += 1
        x += 1
print counter