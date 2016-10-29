#include <iostream>
#include <vector>
#include <math.h>

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
    cout << "Size: " << primes.size() << endl;
    cout << "Max: " << primes[primes.size()-1] << endl;
    int maximum = 0;
    for (int i = 0; i < primes.size(); i++)
    {
        for (int l = 0; l < primes.size() && primes[l] < primes[i]; l++)
        {
            int total_sum = 0;
            int x = l;
            bool found = false;
            while (total_sum < primes[i])
            {
                total_sum += primes[x];
                if (total_sum == primes[i])
                {
                    if (x-l > maximum)
                    {
                        found = true;
                        maximum = x-l;
                        cout << primes[i] << ", " << maximum << endl;
                        break;
                    }
                }
                x++;
            }
            if (found == true)
            {
                break;
            }
        }
    }
	return 0;
}
