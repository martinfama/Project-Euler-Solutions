#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../primes.h"

int main(int argc, char *argv[])
{
    uint32_t *primes = NULL;
    load_primes(&primes);

    uint32_t N = 1e7;
    uint32_t *phi;
    phi = (uint32_t *)malloc(N * sizeof(uint32_t));
    for (uint32_t i = 0; i < N; i++)
    {
        phi[i] = i;
    }
    for (uint32_t i = 2; i < N; i++)
    {
        if (phi[i] == i)
        {
            for (uint32_t j = i; j < N; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
    double minimal_ratio = 1000000.0;
    uint32_t minimal_n = N + 1;
    uint32_t minimal_eu_n = phi[N] + 1;
    double progress = 0.0;
    for (uint32_t n = 2; n < N; n++)
    {
        printf("\rProgress: %.2f%%", (double)n / N * 100);
        uint32_t n_copy = n;
        uint32_t eu_n = phi[n];
        uint32_t eu_n_copy = eu_n;
        int c[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        while (n_copy)
        {
            c[n_copy % 10]++;
            n_copy /= 10;
        }
        while (eu_n_copy)
        {
            c[eu_n_copy % 10]--;
            eu_n_copy /= 10;
        }
        uint32_t res = 1;
        for (uint32_t i = 0; i < 10; i++)
        {
            res &= c[i] == 0;
        }

        if (res)
        {
            double ratio = (double)n / eu_n;
            if (ratio < minimal_ratio)
            {
                minimal_ratio = ratio;
                minimal_n = n;
                minimal_eu_n = eu_n;
            }
        }
    }
    printf("\nMinimal n: %u, Minimal Euler's Totient: %u, Ratio: %.6f\n", minimal_n, minimal_eu_n, minimal_ratio);
    return 0;
}