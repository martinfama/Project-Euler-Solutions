// helper function for working with prime numbers

#ifndef PRIMES_H
#define PRIMES_H

#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

static void load_primes(uint64_t **primes)
{
    FILE *file = fopen("../primes.txt", "r");
    uint64_t prime;
    uint64_t count = 0;
    while (fscanf(file, "%" SCNu64, &prime) == 1)
    {
        *primes = (uint64_t *)realloc(*primes, (count + 1) * sizeof(uint64_t));
        (*primes)[count++] = prime;
    }
    fclose(file);
}

static uint64_t factorization(uint64_t n, uint64_t **p, uint64_t **c, uint64_t *primes)
{
    // p: array of prime factors
    // c: array of counts of each prime factor
    // returns the number of distinct prime factors
    *p = NULL;
    *c = NULL;
    uint64_t p_count = 0;
    for (uint64_t i = 0;; i++)
    {
        if (primes[i] > n)
            break;
        int current_ = 0;
        while (1)
        {
            uint64_t current_count = 0;
            if (n % primes[i] == 0)
            {
                n /= primes[i];
                if (current_ == 0)
                {
                    *p = (uint64_t *)realloc(*p, (p_count + 1) * sizeof(uint64_t));
                    (*p)[p_count] = primes[i];
                    *c = (uint64_t *)realloc(*c, (p_count + 1) * sizeof(uint64_t));
                    (*c)[p_count] = 0;
                    p_count++;

                    current_ = 1;
                }
                (*c)[p_count - 1]++;
            }
            else
            {
                break;
            }
        }
    }
    return p_count;
}

void sieve(uint64_t n, uint64_t **spf)
{
    // spf: smallest prime factor for each number
    *spf = (uint64_t *)malloc((n + 1) * sizeof(uint64_t));
    for (uint64_t i = 0; i <= n; i++)
        (*spf)[i] = i;

    for (uint64_t i = 2; i * i <= n; i++)
    {
        if ((*spf)[i] == i) // i is prime
        {
            for (uint64_t j = i * i; j <= n; j += i)
            {
                if ((*spf)[j] == j)
                    (*spf)[j] = i;
            }
        }
    }
}

static uint64_t sieve_factorization(uint64_t n, uint64_t **p, uint64_t **c, uint64_t *spf, uint64_t n_spf)
{
    // p: array of prime factors
    // c: array of counts of each prime factor
    // returns the number of distinct prime factors
    *p = NULL;
    *c = NULL;
    uint64_t p_count = 0;

    while (n > 1)
    {
        uint64_t prime_factor = spf[n];
        int current_ = 0;
        while (1)
        {
            if (n % prime_factor == 0)
            {
                n /= prime_factor;
                if (current_ == 0)
                {
                    *p = (uint64_t *)realloc(*p, (p_count + 1) * sizeof(uint64_t));
                    (*p)[p_count] = prime_factor;
                    *c = (uint64_t *)realloc(*c, (p_count + 1) * sizeof(uint64_t));
                    (*c)[p_count] = 0;
                    p_count++;

                    current_ = 1;
                }
                (*c)[p_count - 1]++;
            }
            else
            {
                break;
            }
        }
    }
    return p_count;
}

#endif