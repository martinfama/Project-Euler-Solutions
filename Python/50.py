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
primes.pop()
primes.pop()
print primes[len(primes)-1]

found = False

maximum = 0

for i in range(len(primes)):
    for l in range(len(primes)):
        if primes[l] > primes[i]:
            break
        total_sum = 0
        x = l
        found = False
        while total_sum < primes[i]:
            total_sum += primes[x]
            if total_sum == primes[i]:
                if x-l > maximum:
                    maximum = x-l
                    print primes[i], maximum
                    found = True
                    break
            x += 1
        if found == True:
            break

print maximum