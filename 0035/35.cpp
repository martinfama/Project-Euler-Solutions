#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> primes;
    primes.push_back(2);
	int new_prime = 3;
	for (; new_prime < 1000000; new_prime += 2)
	{
        bool found = true;
        for (int x = 0; primes[x] <= sqrt(new_prime); x++)
        {
            if (new_prime % primes[x] == 0)
            {
                found = false;
                break;
            }
        }
        if (found)
            primes.push_back(new_prime);
    }
    int circular_primes = 2;
    for (int i = 0; i < primes.size(); i++)
    {
        new_prime = primes[i];
        int length_of_prime = 1;
        while (new_prime/10 > 0)
        {
            length_of_prime++;
            new_prime /= 10;
        }
        new_prime = primes[i];
        int digits[length_of_prime];
        for (int x = 0; x < length_of_prime; x++)
        {
            digits[x] = int(new_prime/pow(10, x))%10;
            if (digits[x] % 2 == 0 || digits[x] == 5)
            {
                goto nope;
            }
        }
        for (int j = 0; j < length_of_prime; j++)
        {
            new_prime = 0;
            for (int x = 0; x<length_of_prime; x++)
            {
                new_prime += digits[(j+x)%length_of_prime]*pow(10, x);
            }
            if (find(primes.begin(), primes.end(), new_prime) == primes.end())
                break;
            if (j == length_of_prime-1)
                circular_primes++;
        }
        nope:;
    }
    cout << circular_primes << endl;
	return 0;
}
