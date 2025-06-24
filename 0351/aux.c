#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../primes.h"

int main(int argc, char *argv[])
{
    uint64_t *primes = NULL;
    load_primes(&primes);

    uint64_t N = 1e8;

    uint64_t *p = NULL;
    uint64_t *c = NULL;

    uint64_t max_prime = 0;
    for (uint64_t n = 1; n <= N; n++)
    {
        for (uint64_t m = n + 1; m <= N; m++)
        {
        }
    }
    printf("Maximum prime factor found: %" PRIu64 "\n", max_prime);
    return 0;
}
