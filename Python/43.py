import itertools
a = list(itertools.permutations([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]))
numbers = [0]*7
primes = (2, 3, 5, 7, 11, 13, 17)
total = 0
for i in range(3628800):
    is_it = True
    for x in range(7):
        numbers[x] = 100*a[i][x+1] + 10*a[i][x+2] + a[i][x+3]
        if numbers[x] % primes[x] != 0:
            break
        if x == 6:
            for p in range(0, 10):
                total += a[i][p]*(10**(9-p))
print total