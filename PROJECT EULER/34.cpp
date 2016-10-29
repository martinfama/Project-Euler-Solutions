#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

int get_length(unsigned long long int copy_i)
{
    int length = 0;
    for (; copy_i > 0; length++)
        copy_i /= 10;
    return length;
}

int factorial(int number)
{
    int temp = 1;
    if (number > 1)
        temp = number*factorial(number-1);
    return temp;
}

int main()
{
    unsigned long long int total = 0;
    for (unsigned int i = 3; i <= 999999; i++)
    {
        int length = get_length(i);
        unsigned int current_sum = 0;
        for (int x = 0; x < length; x++)
        {
            int number = (int)(i/pow(10, x))%10;
            current_sum += factorial(number);
        }
        if (current_sum == i)
            total += i;
    }
    cout << total << endl;
	return 0;
}
