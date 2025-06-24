#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <uthash.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int contains(int *arr, int len, int val)
{
    return bsearch(&val, arr, len, sizeof(int), compare) != NULL;
}

int prime_pairs(uint32_t *primes, uint32_t count, uint32_t p1, uint32_t p2)
{
    // check if concatenating p1 and p2 (in both orders) forms a prime number
    uint32_t c1 = p1 * (uint32_t)pow(10, (int)log10(p2) + 1) + p2;
    uint32_t c2 = p2 * (uint32_t)pow(10, (int)log10(p1) + 1) + p1;
    return contains(primes, count, c1) && contains(primes, count, c2);
}

typedef struct
{
    uint32_t key;
    uint32_t *pairs;
    uint32_t count;
    UT_hash_handle hh; // makes this structure hashable
} PairHash;

int main(int argc, char *argv[])
{
    FILE *file = fopen("primes.txt", "r");
    uint32_t prime;
    uint32_t *primes = NULL;
    uint32_t count = 0;
    while (fscanf(file, "%u", &prime) == 1)
    {
        primes = realloc(primes, (count + 1) * sizeof(uint32_t));
        primes[count++] = prime;
    }
    fclose(file);

    PairHash *pair_hash = NULL;

    for (uint32_t i = 1; i < 20000; i++)
    {
        for (uint32_t j = i + 1; j < 20000; j++)
        {
            if (prime_pairs(primes, count, primes[i], primes[j]))
            {
                // check if hash table for primes[i] exists
                PairHash *pair_entry;
                HASH_FIND_INT(pair_hash, &primes[i], pair_entry);
                if (!pair_entry)
                {
                    // create a new entry for primes[i]
                    pair_entry = malloc(sizeof(PairHash));
                    pair_entry->key = primes[i];
                    pair_entry->pairs = NULL;
                    pair_entry->count = 0;
                    HASH_ADD_INT(pair_hash, key, pair_entry);
                }
                // add primes[j] to the pairs of primes[i]
                pair_entry->pairs = realloc(pair_entry->pairs, (pair_entry->count + 1) * sizeof(uint32_t));
                pair_entry->pairs[pair_entry->count++] = primes[j];
            }
        }
    }

    PairHash *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL;
    // now, for each element of p1, use the value as a key to find the next pair hash at p2.
    // for each element of p2, first check it is contained in p1's values, and then do the same thing
    // for p3, wherein each new level has to be checked to be contained in p1, p2, etc.
    for (uint32_t ip = 0; ip < count; ip++)
    {
        uint32_t key1 = primes[ip];
        HASH_FIND_INT(pair_hash, &key1, p1);
        if (!p1)
            continue;
        for (uint32_t i = 0; i < p1->count; i++)
        {
            uint32_t key2 = p1->pairs[i];
            HASH_FIND_INT(pair_hash, &key2, p2);
            if (p2)
            {
                for (uint32_t j = 0; j < p2->count; j++)
                {
                    uint32_t key3 = p2->pairs[j];
                    if (contains(p1->pairs, p1->count, key3))
                    {
                        HASH_FIND_INT(pair_hash, &key3, p3);
                        if (p3)
                        {
                            for (uint32_t k = 0; k < p3->count; k++)
                            {
                                uint32_t key4 = p3->pairs[k];
                                if (contains(p1->pairs, p1->count, key4) && contains(p2->pairs, p2->count, key4))
                                {
                                    // printf("Found prime pair chain: %u, %u, %u, %u\n", 3, key, key2, key3);
                                    HASH_FIND_INT(pair_hash, &key4, p4);
                                    if (p4)
                                    {
                                        for (uint32_t l = 0; l < p4->count; l++)
                                        {
                                            uint32_t key5 = p4->pairs[l];
                                            if (contains(p1->pairs, p1->count, key5) && contains(p2->pairs, p2->count, key5) && contains(p3->pairs, p3->count, key5))
                                            {
                                                printf("Found prime pair chain: %u, %u, %u, %u, %u\n", key1, key2, key3, key4, key5);
                                                printf("Sum is: %u\n", key1 + key2 + key3 + key4 + key5);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}