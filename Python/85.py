closest = 10000000

for i in range(1, 2000):
    for j in range(1, 2000):
        one = i/2.0*(i+1)
        two = j/2.0*(j+1)
        if abs(2000000-one*two) <= closest:
            closest = abs(2000000-one*two)
            print str(i) + " * " + str(j) + " = " + str(one) + " * " + str(two) + " = " + str(one*two) + " : " + str(closest)