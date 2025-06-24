#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int is_square(uint64_t n)
{
    if (n < 2)
        return 1;

    uint64_t left = 2, right = n / 2, mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        uint64_t square = mid * mid;

        if (square == n)
            return 1;
        else if (square < n)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return 0;
}

int main()
{
    uint64_t count = 0;
    for (uint64_t M = 1;; M++)
    {
        uint64_t W = M;
        for (uint64_t L = 1; L <= M; L++)
        {
            for (uint64_t H = L; H <= M; H++)
            {
                uint64_t s = W * W + (L + H) * (L + H);
                if (is_square(s))
                    count++;
            }
        }
        printf("M = %u, count = %u\n", M, count);
        if (count >= 1000000)
        {
            printf("Minimum M with at least 1000000 integer shortest paths: %u\n", M);
            break;
        }
    }
    return 0;
}