#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "../primes.h"

int main(int argc, char *argv[])
{
    uint64_t *primes = NULL;
    load_primes(&primes);

    uint64_t N = 1e8 + 1;
    uint64_t *spf = NULL;
    sieve(N, &spf);

    uint64_t total_visible = 0;
    double time_spent_on_factorization = 0.0;
    for (uint64_t n = 2; n <= N - 1; n++)
    {
        uint64_t phi = n;
        uint64_t current = n;
        while (current > 1)
        {
            uint64_t prime_factor = spf[current];
            phi *= (1 - 1.0 / (double)prime_factor);
            while (current % prime_factor == 0)
            {
                current /= prime_factor;
            }
        }
        total_visible += phi;
    }
    total_visible *= 2;
    total_visible += 1;
    uint64_t non_visible = (N - 1) * (N - 1) - total_visible;
    non_visible -= (N - 2);
    non_visible /= 2;
    non_visible += (N - 2);
    printf("Non-visible %" PRIu64 "\n", 6 * non_visible);
    return 0;
}
