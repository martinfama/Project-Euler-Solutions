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
            else:
                it_isnt = True
            if it_isnt == False:
                primes.append(i)
            i += 1
    elif how == 'n':
        generated = len(primes)
        i = primes[len(primes)-1] + 2
        while generated < number:
            x = 0
            it_isnt = False
            if str(i)[len(str(i))-1] != '5':
                while primes[x] <= math.sqrt(i):
                    if i % primes[x] == 0:
                        it_isnt = True
                        break
                    x += 1
            else:
                it_isnt = True
            if it_isnt == False:
                primes.append(i)
                generated += 1
            i += 1


current = 0

distincer = 4

def factorize(n):
    global current
    new_n = n
    x = 0
    factors = []
    while new_n > 1:
        if x > len(primes)-1:
            generate_primes(x, 'plus')
        elif new_n % primes[x] == 0:
            new_n /= primes[x]
            factors.append(primes[x])
        else:
            x += 1
    i = 0
    distinct = 0
    while i < len(factors):
        how_many = 0
        if i < len(factors)-1:
            while factors[i] == factors[i+1]:
                how_many += 1
                i += 1
                if i == len(factors)-1:
                    break
        distinct += 1
        i += 1
    if distinct == distincer:
        current += 1

found = False

number = 10

while not found:
    current = 0
    factorize(number)
    if current == 1:
        factorize(number+1)
        if current == 2:
            factorize(number+2)
            if current == 3:
                factorize(number+3)
                if current == 4:
                    print number
                    found = True
    number += 1