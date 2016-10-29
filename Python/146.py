import time
start = time.time()
import math
primes = []
primes.append(2)
primes.append(3)
primes.append(5)

def generate_primes(number = 0, how = ''):
    last_prime = primes[len(primes)-1]
    i = primes[len(primes)-1] + 2
    if how == 'plus':
        number += primes[len(primes)-1]
    while primes[len(primes)-1] < number:
        x = 0
        it_isnt = False
        if str(i)[len(str(i))-1] != '5':
            while primes[x] <= math.sqrt(i):
                if i % primes[x] == 0:
                    it_isnt = True
                    break
                x += 1
        if it_isnt == False:
            primes.append(i)
        i += 1

def factorize(n):
    if n < 2 or float(n).is_integer() == False:
        print str(n) + " is not an integer larger than 1"
        return
    new_n = n
    x = 0
    factors = []
    print str(n) + ":",
    while new_n > 1:
        if x > len(primes)-1:
            generate_primes(x, 'plus')
        elif new_n % primes[x] == 0:
            new_n /= primes[x]
            factors.append(primes[x])
        else:
            x += 1
    i = 0
    while i < len(factors):
        how_many = 0
        if i < len(factors)-1:
            while factors[i] == factors[i+1]:
                how_many += 1
                i += 1
                if i == len(factors)-1:
                    break
        if how_many > 0:
            print str(factors[i-1]) + "^" + str(how_many+1),
        else:
            print factors[i],
        i += 1

while 1:
    n = raw_input("")
    if n == "primes":
        x = input("Upto: ")
        generate_primes(x)
        for i in range(x):
            print primes[i]
    elif n == "quit":
        break
    else:
        factorize(int(n))
    print ""
print time.time()-start