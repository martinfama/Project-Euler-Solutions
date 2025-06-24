i = 1
found = False
while 1:
    sets = []
    sets.append(str(i))
    sets.append(str(i*2))
    sets.append(str(i*3))
    sets.append(str(i*4))
    sets.append(str(i*5))
    sets.append(str(i*6))
    if set(sets[0]) == set(sets[1]) == set(sets[2]) == set(sets[3]) == set(sets[4]) == set(sets[5]):
        print sets[0] + " = " + sets[1] + " = " + sets[2] + " = " + sets[3] + " = " + sets[4] + " = " + sets[5]
        break
    i += 1