#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <uthash.h>

uint32_t gospers_hack(uint32_t x)
{
    uint32_t c = x & -x; // Get the rightmost 1-bit
    uint32_t r = x + c;  // Add c to x
    return ((r ^ x) >> 2) / c | r;
}

typedef struct
{
    uint32_t id;
    uint32_t *primes;
    uint32_t count;
    UT_hash_handle hh; // makes this structure hashable
} PrimeHash;

// for context, we are solving the Project Euler problem 51, which is about finding prime families
/*
By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.
Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
*/
// We will use the PrimeHash structure to store the prime numbers and their families.
// The id for a family will be the digits we are NOT replacing, i.e. the digits that are fixed.
// So in the examples given by the problem, the family id for 56**3 would be 56003, and the family id for *3 would be 3.

int main(int argc, char *argv[])
{
    // The argument --family-number=<family_number> is required.
    uint32_t family_number = 0;
    for (int i = 1; i < argc; i++)
    {
        if (sscanf(argv[i], "--family-number=%u", &family_number) == 1)
        {
            break;
        }
    }

    for (uint32_t digits = 1; digits < 10; digits++)
    {
        FILE *file = fopen("primes.txt", "r");
        uint32_t prime;
        uint32_t *primes = NULL;
        uint32_t count = 0;
        while (fscanf(file, "%u", &prime) == 1)
        {
            if (prime >= pow(10, digits - 1) && prime < pow(10, digits))
            {
                primes = realloc(primes, (count + 1) * sizeof(uint32_t));
                primes[count++] = prime;
            }
        }
        fclose(file);

        for (uint32_t digit_replacements = 1; digit_replacements <= digits; digit_replacements++)
        {
            // use Gosper's hack, with k=digit_replacements and n=digits
            uint32_t x = (1 << digit_replacements) - 1;
            // if digit_replacements is of type 2**N - 1, then skip, since we don't want to replace all digits
            if (x == (1 << digits) - 1)
            {
                continue;
            }
            uint32_t limit = 1 << digits;
            uint32_t idxs[family_number];
            while (x < limit)
            {
                PrimeHash *families = NULL;
                uint32_t other_mask = ~x & ((1 << digits) - 1);
                uint32_t family_count = 0;
                for (uint32_t d = 0; d <= 9; d++)
                {
                    for (uint32_t idp = 0; idp < count; idp++)
                    {
                        // check if each digit at location of x is equal to d
                        uint32_t prime_candidate = primes[idp];
                        uint32_t temp = prime_candidate;
                        uint32_t digit_mask = 1;
                        uint32_t valid = 1;
                        for (uint32_t i = 0; i < digits; i++)
                        {
                            if (x & digit_mask)
                            {
                                if ((temp % 10) != d)
                                {
                                    valid = 0;
                                    break;
                                }
                            }
                            temp /= 10;
                            digit_mask <<= 1;
                        }
                        if (valid)
                        {
                            // conver the prime into a family id, by converting the digits in the mask (x) to 0
                            uint32_t prime_candidate_id = prime_candidate;
                            temp = prime_candidate_id;
                            digit_mask = 1;
                            for (uint32_t i = 0; i < digits; i++)
                            {
                                if (x & digit_mask)
                                {
                                    prime_candidate_id -= (temp % 10) * pow(10, i);
                                }
                                temp /= 10;
                                digit_mask <<= 1;
                            }
                            // check if the family id is already in the hash table
                            PrimeHash *family;
                            HASH_FIND_INT(families, &prime_candidate_id, family);
                            if (family == NULL)
                            {
                                // create a new family
                                family = malloc(sizeof(PrimeHash));
                                family->id = prime_candidate_id;
                                family->primes = malloc(sizeof(uint32_t));
                                family->primes[0] = prime_candidate;
                                HASH_ADD_INT(families, id, family);
                                family->count = 1;
                            }
                            else
                            {
                                // add the prime to the existing family
                                family->primes = realloc(family->primes, (family->count + 1) * sizeof(uint32_t));
                                family->primes[family->count++] = prime_candidate;
                                if (family->count == family_number)
                                {
                                    // since we are iterating over the primes in ascending order, we will therefore find the smallest prime first
                                    printf("Found smallest prime with family number %u: %u\n", family_number, family->primes[0]);
                                    printf("Full family: ");
                                    for (uint32_t i = 0; i < family->count; i++)
                                    {
                                        printf("%u ", family->primes[i]);
                                    }
                                    printf("\n");
                                    return 0;
                                }
                            }
                        }
                    }
                }

                // we get the next mask
                x = gospers_hack(x);
            }
        }
    }

    return 0;
}