#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "../primes.h"

uint64_t last_n_digits(uint64_t x, uint64_t n)
{
    uint64_t mod = 1;
    for (uint64_t i = 0; i < n; i++)
        mod *= 10;
    return x % mod;
}

int main()
{
    uint64_t *primes = NULL;
    load_primes(&primes);

    uint64_t s = 0;
    for (uint64_t i = 2; primes[i] < 1000000; i++)
    {
        uint64_t p1 = primes[i];
        uint64_t p2 = primes[i + 1];
        uint64_t p1_len_digits = (uint64_t)log10(p1) + 1;
        for (uint64_t j = 1;; j++)
        {
            uint64_t n = p2 * j;
            if (last_n_digits(n, p1_len_digits) == p1)
            {
                s += n;
                break;
            }
        }
    }
    printf("\n%lu\n", s);
    return 0;
}