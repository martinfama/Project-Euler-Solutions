#include <iostream>
#include <math.h>
#include <stdint-gcc.h>

using namespace std;

int main()
{
    double i = 1;
	uint64_t current = 2;
	uint64_t sum = 0;
        while (i <= 1001*1001)
        {
            double intpart;
            sum += i;
            i += current;
            if (modf(sqrt(i), &intpart) == 0.0)
            {
                current += 2;
            }
        }
        cout << sum << endl;
    return 0;
}
