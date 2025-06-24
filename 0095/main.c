#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "../primes.h"

uint64_t proper_divisors(uint64_t n, uint64_t *p, uint64_t *c, uint64_t count, uint64_t **divisors)
{
    // n: number to find proper divisors of
    // p: array of prime factors
    // c: array of counts of each prime factor
    // count: number of distinct prime factors
    // divisors: array to store proper divisors
    // returns the number of proper divisors
    uint64_t divisor_count = 1;
    for (uint16_t i = 0; i < count; i++)
    {
        divisor_count *= (c[i] + 1);
    }
    divisor_count--; // Exclude the number itself
    *divisors = (uint64_t *)malloc(divisor_count * sizeof(uint64_t));
    uint64_t *prime_exponent_counter = (uint64_t *)calloc(count, sizeof(uint64_t));
    for (uint64_t i = 0; i < divisor_count; i++)
    {
        uint64_t divisor = 1;
        for (uint16_t j = 0; j < count; j++)
        {
            divisor *= pow(p[j], prime_exponent_counter[j]);
        }
        (*divisors)[i] = divisor;

        // Increment the prime exponent counter
        for (uint16_t j = 0; j < count; j++)
        {
            if (prime_exponent_counter[j] < c[j])
            {
                prime_exponent_counter[j]++;
                break;
            }
            else
            {
                prime_exponent_counter[j] = 0;
            }
        }
    }
}

int main()
{
    uint64_t *primes = NULL;
    load_primes(&primes);
    // FILE *file = fopen("../primes.txt", "r");
    // uint64_t prime;
    // uint64_t count = 0;
    // uint64_t *primes = NULL;
    // while (fscanf(file, "%lu", &prime) == 1)
    // {
    //     primes = (uint64_t *)realloc(primes, (count + 1) * sizeof(uint64_t));
    //     primes[count++] = prime;
    // }
    // fclose(file);

    uint64_t N = 1000000;
    uint64_t *chain = (uint64_t *)malloc(N * sizeof(uint64_t));
    for (uint64_t n = 1; n <= N; n++)
    {
        uint64_t *p = NULL;
        uint64_t *c = NULL;
        uint64_t count = factorization(n, &p, &c, primes);

        uint64_t *divisors = NULL;
        uint64_t divisor_count = proper_divisors(n, p, c, count, &divisors);
        uint64_t sum = 0;
        for (uint64_t i = 0; i < divisor_count; i++)
            sum += divisors[i];

        chain[n - 1] = sum;
        free(p);
        free(c);
        free(divisors);
    }

    uint64_t *longest_chain = NULL;
    uint64_t longest_chain_size = 0;
    for (uint64_t n = 1; n <= N; n++)
    {
        uint64_t in = n;
        int found_amicable_chain = 0;
        uint64_t *current_chain = NULL;
        uint64_t current_chain_size = 0;
        uint64_t chain_start_id = 0;
        while (1)
        {
            uint64_t next = chain[in - 1];
            if (next == 0 || next > N)
                break;
            if (next == n)
            {
                found_amicable_chain = 1;
                break;
            }
            for (chain_start_id = 0; chain_start_id < current_chain_size; chain_start_id++)
            {
                if (current_chain[chain_start_id] == next)
                {
                    found_amicable_chain = 1;
                    break;
                }
            }
            if (found_amicable_chain)
            {
                if (current_chain_size - chain_start_id + 1 >= longest_chain_size)
                {
                    longest_chain_size = current_chain_size - chain_start_id + 1;
                    longest_chain = (uint64_t *)realloc(longest_chain, longest_chain_size * sizeof(uint64_t));
                    for (uint64_t k = 0; k < longest_chain_size; k++)
                        longest_chain[k] = current_chain[chain_start_id + k];
                    longest_chain[longest_chain_size - 1] = next;
                }
                break;
            }
            // Add to current chain
            current_chain = (uint64_t *)realloc(current_chain, (current_chain_size + 1) * sizeof(uint64_t));
            current_chain[current_chain_size++] = next;
            in = next;
        }
    }

    // Print the longest chain
    uint64_t smallest = 1e6;
    printf("Longest chain size: %lu\n", longest_chain_size);
    for (uint64_t i = 0; i < longest_chain_size; i++)
    {
        printf("%lu ", longest_chain[i]);
        smallest = (longest_chain[i] < smallest) ? longest_chain[i] : smallest;
    }
    printf("\n");
    printf("Smallest number in longest chain: %lu\n", smallest);

    return 0;
}