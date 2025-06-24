#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "../primes.h"

uint32_t *primes;

void polynomial_mult(uint32_t *p, uint32_t *q, uint32_t degree, uint32_t **r)
{
    *r = calloc(2 * degree + 1, sizeof(uint32_t));
    for (uint32_t k = 0; k <= 2 * degree; k++)
    {
        (*r)[k] = 0;
        if (k <= degree)
        {
            for (uint32_t i = 0; i <= k; i++)
            {
                (*r)[k] += p[i] * q[k - i];
            }
        }
        else
        {
            for (uint32_t i = k - degree; i <= degree; i++)
            {
                (*r)[k] += p[i] * q[k - i];
            }
        }
    }
}

uint32_t prime_partitions(uint32_t n)
{
    uint32_t i = 0;
    uint32_t **prime_partition_factors = NULL;
    while (primes[i] <= n)
    {
        prime_partition_factors = realloc(prime_partition_factors, (i + 1) * sizeof(uint32_t *));
        prime_partition_factors[i] = calloc(n + 1, sizeof(uint32_t));
        for (int j = 0; primes[i] * j <= n; j++)
        {
            prime_partition_factors[i][primes[i] * j] = 1;
        }
        i++;
    }

    uint32_t *result = calloc(n + 1, sizeof(uint32_t));
    for (uint32_t j = 0; j < i; j++)
    {
        if (j == 0)
        {
            for (uint32_t k = 0; k <= n; k++)
            {
                result[k] = prime_partition_factors[j][k];
            }
        }
        else
        {
            uint32_t *temp = NULL;
            polynomial_mult(result, prime_partition_factors[j], n, &temp);
            // copy values from temp to result
            for (uint32_t k = 0; k <= n; k++)
            {
                result[k] = temp[k];
            }
            free(temp);
            temp = NULL;
        }
    }
    // the total is the factor at n
    uint32_t partitions = result[n];
    for (uint32_t j = 0; j < i; j++)
    {
        free(prime_partition_factors[j]);
    }
    free(prime_partition_factors);
    return partitions;
}

int main()
{
    load_primes(&primes);
    for (uint32_t i = 0;; i++)
    {
        uint32_t result = prime_partitions(i);
        if (result > 5000)
        {
            printf("%u has %u > 5000 prime partitions\n", i, result);
            free(primes);
            break;
        }
    }
    return 0;
}