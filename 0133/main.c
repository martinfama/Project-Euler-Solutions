#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../primes.h"

int main()
{
    uint64_t N = 1000000;
    uint64_t *primes = NULL;
    load_primes(&primes);
    uint64_t *spf = NULL;
    sieve(N, &spf);

    uint64_t *p = NULL;
    uint64_t *c = NULL;

    uint64_t ip = 3; // skip 2,3 and 5 since clearly not suitable
    uint64_t sum = 0;
    while (primes[ip] < 100000)
    {
        uint64_t r = 0;
        uint64_t i = 1;
        for (;; i++)
        {
            r = (10 * r + 1) % primes[ip];
            if (r == 0)
                break;
        }

        // check if any of the prime factors of i is not 2 or 5
        uint64_t p_count = sieve_factorization(i, &p, &c, spf, N);
        if (p_count == 1)
        {
            if (p[0] != 2 && p[0] != 5)
                sum += primes[ip];
        }
        else if (p_count == 2)
        {
            if (p[0] != 2 || p[1] != 5)
                sum += primes[ip];
        }
        else
        {
            sum += primes[ip];
        }
        ip++;
    }
    printf("%lu\n", sum + 2 + 3 + 5);

    return 0;
}