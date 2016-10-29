count = 0
for i in range(10000):
    iteration = 0
    found = False
    x1 = i
    while not found and iteration < 50:
        x2 = 0
        for x in range(len(str(x1))):
            x2 += x1/pow(10,x)%10*pow(10, len(str(x1))-x-1)
        palindrome = x1 + x2
        print str(x1) + " + " + str(x2) + " = " + str(palindrome)
        is_not = True
        for x in range(len(str(palindrome))/2):
            if str(palindrome)[x] != str(palindrome)[len(str(palindrome))-x-1]:
                is_not = False
                break
        if is_not == True:
            found = True
            break
        iteration += 1
        x1 = palindrome
    if iteration == 50:
        #print i
        count += 1

print count
