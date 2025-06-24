import math
from decimal import *

cubes = []
cubes.append(1)
def add_cubes(x):
    length = len(cubes)+1
    while cubes[len(cubes)-1] < x:
        cubes.append(length**3)
        length += 1
add_cubes(10000000)

primes = []
primes.append(2)
new_prime = 3;
while new_prime < 1000000:
    x = 0
    found = True
    while primes[x] <= math.sqrt(new_prime):
        if new_prime % primes[x] == 0:
            found = False
            break
        x += 1
    if found:
        primes.append(new_prime)
    new_prime += 2

last = 0

for x in range(len(primes)):
    r = last
    while 1:
        n = cubes[r]
        if n > primes[x]*150:
            break
        total = n**3 + n**2*primes[x]
        if total > cubes[len(cubes)-1]:
            add_cubes(total*2)
        if r == len(cubes)-1:
            add_cubes(2*(cubs[len(cubes)]-1))
        if total in cubes:
            print str(primes[x]) + ", " + str(n) + ", " + str(n**(1.0/3.0)) + " = " + str(total) + "      " + str(primes[x]/1.0/n)
            last = r
            break
        r += 1