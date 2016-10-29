for p in range(4, 101):
    ranger = (2, p)
    terms = [0]*((ranger[1]-ranger[0])**2)
    total = 0

    for a in range(ranger[0], ranger[1]):
        for b in range(ranger[0], ranger[1]):
            pos_1 = (ranger[1]-ranger[0])*(a-ranger[0])
            pos_2 = b-ranger[0]
            terms[pos_1+pos_2] = a**b

    for i in range(len(terms)):
        is_it = True
        for x in range(i):
            if terms[x] == terms[i]:
                is_it = False
                break
        if is_it == True:
            total += 1
    print str(p) + " = " + str(total)

#xor anwser: len(set(a**b for a in range(2, 101) for b in range(2, 101)))
#SETS ARE USEFUL!!!!!