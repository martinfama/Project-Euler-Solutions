#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../primes.h"

uint64_t D(uint64_t k, uint64_t *p, uint64_t *c, uint64_t p_count)
{
    double s = 0;
    for (uint64_t i = 0; i < p_count; i++)
    {
        s += (double)c[i] / (double)p[i];
    }
    uint64_t result = (uint64_t)((double)k * s);
    return result;
}

uint64_t gcd(uint64_t a, uint64_t b)
{
    while (b != 0)
    {
        uint64_t t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(int argc, char *argv[])
{
    uint64_t N = strtoull(argv[1], NULL, 10);

    uint64_t *primes = NULL;
    load_primes(&primes);

    uint64_t *spf = NULL;
    sieve(N, &spf);

    uint64_t *p = NULL;
    uint64_t *c = NULL;
    uint64_t s = 0;
    for (uint64_t n = 1; n <= N; n++)
    {
        // print progress as percentage n/N
        if (n % (N / 100) == 0)
        {
            printf("\rProgress: %" PRIu64 "%%", n * 100 / N);
            fflush(stdout);
        }
        uint64_t p_count = sieve_factorization(n, &p, &c, spf, n + 1);
        uint64_t d = D(n, p, c, p_count);
        s += gcd(n, d);
    }
    printf("\n%" PRIu64 "\n", s);

    return 0;
}