import math

max = 0

for D in range(2, 1001):
    if math.sqrt(D).is_integer():
        continue
    else:
        y = 1
        while 1:
            number = math.sqrt(1.0+D*y*y*1.0)
            if number.is_integer():
                if number > max:
                    max = number
                    print "<--------> ",
                print str(int(number)) + "^2 - " + str(D) + "*" + str(y) + "^2 = 1"
                break
            y += 1