#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../primes.h"

int main()
{
    uint64_t *primes = NULL;
    load_primes(&primes);

    uint64_t n = 1000000000;
    uint64_t ip = 3; // skip 2,3 and 5 since clearly not suitable
    uint64_t found = 0;
    uint64_t sum = 0;
    while (found < 40)
    {
        uint64_t r = 0;
        uint64_t i = 0;
        for (; i < n; i++)
        {
            r = (10 * r + 1) % primes[ip];
            if (r == 0)
            {
                break;
            }
        }
        if (n % (i + 1) == 0)
        {
            sum += primes[ip];
            found++;
        }
        ip++;
    }
    printf("%lu\n", sum);
}