#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

void repeated_fraction_of_root(uint32_t x, uint32_t **result, uint32_t length)
{
    *result = realloc(*result, sizeof(uint32_t));
    (*result)[0] = (uint32_t)sqrt(x);

    for (uint32_t i = 1; i < length; i++)
    {
        uint32_t a = (*result)[i - 1];
        uint32_t ration_denom = x - a * a;
        uint32_t numerator_split = ration_denom - a;

        *result = realloc(*result, sizeof(uint32_t) * (i + 1));
        (*result)[i] = a;
    }
}

int main(int argc, char *argv[])
{
    uint32_t v = 23;

    uint32_t *result = NULL;
    repeated_fraction_of_root(v, &result, 50);
    for (uint32_t i = 0; i < 50; i++)
    {
        printf("%u ", result[i]);
    }
    printf("\n");
    free(result);

    return 0;
}