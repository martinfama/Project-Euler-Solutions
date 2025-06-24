import math
primes = []
primes.append(2)
primes.append(3)
primes.append(5)

def generate_primes(number = 0):
    last_prime = primes[len(primes)-1]
    i = primes[len(primes)-1] + 2
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

generate_primes(1000000)
total_sum = 0
found = 0
n = 4
while found < 11 and n < len(primes):
    bool_found = True
    new_primes = primes[n]
    for i in range(len(str(primes[n]))-1):
        new_primes = str(new_primes)[:-1]
        if not int(new_primes) in primes:
            bool_found = False
            break
    new_primes = primes[n]
    if bool_found == True:
        for i in range(len(str(primes[n]))-1):
            new_primes = str(new_primes)[1:]
            if not int(new_primes) in primes:
                bool_found = False
                break
    if bool_found == True:
        total_sum += primes[n]
        found += 1
        print primes[n]
    n += 1

print total_sum