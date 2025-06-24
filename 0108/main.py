p = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
# we only need the first 10 primes, because if every prime is a factor:
# 2*3*5..., then the number of divisors is (1+1)(1+1)(1+1)... = 2^10 = 1024
# any extra prime would increase n, and any other prime larger than 29
# could be replaced by a smaller prime.


def num_divisors(n):
    # this might seem bad if the n's factorization has other primes,
    # but notice that we will always undercount the number of divisors
    # in that case, never overcounting
    if n == 1:
        return 1
    count = 1
    for i, prime in enumerate(p):
        if n == 1:
            break
        exp = 0
        while n % prime == 0:
            n //= prime
            exp += 1
        count *= exp + 1
    return count


n = 1
while True:
    divs = num_divisors(n**2)
    if divs // 2 + 1 > 1000:
        print(f"{n}")
        break
    n += 1
