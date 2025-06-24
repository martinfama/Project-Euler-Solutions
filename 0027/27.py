import math
primes = []
primes.append(2)
primes.append(3)
primes.append(5)

def generate_primes(n):
    generated = 0
    i = primes[len(primes)-1]+2
    while generated < n:
        x = 0
        is_it = True
        while primes[x] <= math.sqrt(i):
            if i % primes[x] == 0:
                is_it = False
                break
            x += 1
        if is_it == True:
            primes.append(i)
            generated += 1
        i += 2
        if str(i)[len(str(i))-1] == '5':
            i += 2

generate_primes(1000)
total_max = 0
product = 0

for a in range(-999, 1000):
    for b in range(-999, 1000, 2):
        if b in primes:
            n = 0
            current = 0
            while 1:
                if n**2 + n*a + b >= primes[len(primes)-1]:
                    generate_primes(10000)
                if n**2 + n*a + b in primes:
                    current += 1
                else:
                    break
                n += 1
            if current > total_max:
                total_max = current
                product = a*b
print product