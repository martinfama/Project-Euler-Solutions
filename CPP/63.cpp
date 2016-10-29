#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

int main()
{
    int counter = 0;
    cout << numeric_limits<unsigned long long int>::max();
    cin.get();
    for (int i = 1; i < 50; i++)
    {
        int x = 1;
        while (1)
        {
            unsigned long long int number = pow(x, i);
            unsigned long long int number_2 = pow(x, i);
            int length = 0;
            while (number_2 > 0)
            {
                length++;
                number_2 /= 10;
            }
            if (length > i)
            {
                break;
            }
            else if (length == i)
            {
                cout << x << "^" << i << " = " << number << endl;
                counter++;
            }
            x += 1;
        }
    }
    cout << counter << endl;
	return 0;
}
