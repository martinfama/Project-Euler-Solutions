import math

max = 2
what_d = 0

for d in range(2, 1000):
    is_it = False
    x = 2
    if math.sqrt(d).is_integer():
        continue
    else:
        while not is_it:
            if math.sqrt((x**2-1)/1.0/d).is_integer():
                if x > max:
                    max = x
                    what_d = d
                is_it = True
                print str(d) + " ==== " + str(x) + "^2 - " + str(d) + "*" + str(int(math.sqrt((x**2-1)/1.0/d))) + "^2 = 1"
            x += 1

print what_d