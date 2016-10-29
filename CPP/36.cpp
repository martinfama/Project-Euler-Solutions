#include <iostream>
#include <math.h>

using namespace std;

int get_length(unsigned long long int copy_i)
{
    unsigned long long int length = 0;
    for (; copy_i > 0; length++)
        copy_i /= 10;
    return length;
}

bool is_palindrome(unsigned long long int number)
{
    unsigned long long int length = get_length(number);
    unsigned long long int digits[length];
    for (unsigned long long int i = 0; i < length; i++)
    {
        unsigned long long int digit = (unsigned long long int)(number/pow(10, i))%10;
        digits[i] = digit;
    }
    for (unsigned long long int i = 0; i < length/2; i++)
    {
        unsigned long long int fucking_value = digits[i] - digits[length-i-1];
        if (fucking_value != 0)
        {
            return false;
        }
    }
    return true;
}

unsigned long long int total = 0;

int main()
{
	for (unsigned long long int base_ten = 1; base_ten < 1000000; base_ten++)
    {
        if (is_palindrome(base_ten))
        {
            unsigned long long int binary_length = log10(base_ten)/log10(2)+1;
            int base_two[binary_length];
            unsigned long long int copy_base_ten = base_ten;
            for(int i = 0; copy_base_ten > 0; copy_base_ten/= 2)
            {
                base_two[i] = copy_base_ten%2;
                i++;
            }
            bool binary_palindrome = true;
            for (int i = 0; i < binary_length/2; i++)
            {
                if (base_two[i] != base_two[binary_length-i-1])
                {
                    binary_palindrome = false;
                    break;
                }
            }
            if (binary_palindrome)
            {
                cout << base_ten << " = ";
                for (int i = 0; i < binary_length; i++)
                {
                    cout << base_two[i];
                }
                cout << endl;
                total += base_ten;
                cin.get();
            }
        }
    }
    cout << total << endl;
	return 0;
}
