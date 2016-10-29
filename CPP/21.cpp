#include <iostream>

using namespace std;

int main()
{
    unsigned long long int total_sum = 0;
	for(int i = 1; i < 10000; i++)
	{
        unsigned long long int current_sum = 0;
        for (unsigned long long int j = 1; j <= i/2; j++)
        {
            if (i % j == 0)
            {
                current_sum += j;
            }
        }
        unsigned long long int current_sum_2 = 0;
        for (unsigned long long int j = 1; j <= current_sum/2; j++)
        {
            if (current_sum % j == 0)
            {
                current_sum_2 += j;
            }
        }
        if (current_sum_2 == i && i != current_sum)
        {
            cout << i << ", " << current_sum << endl;
            total_sum += i;
        }
	}
	cout << total_sum << endl;
}
