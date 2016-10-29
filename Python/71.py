smallest = 10

i = 1
while 7*i < 1000000:
    if 3.0/7-(3.0*i-1)/(7.0*i) < smallest:
        smallest = (3.0*i-1)/(7.0*i)
        print str(3*i-1) + " / " + str(7*i) + " = " + str((3.0*i-1)/(7.0*i))
    i += 1