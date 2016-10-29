#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << setprecision(100);
    long double hex = 1;
    int nums_found = 0;
	for (unsigned long long int i = 1; nums_found < 3; i++)
	{
        hex = i*(2*i-1);
        unsigned long long int int_p = ((0.5+sqrt(0.25-4*3/2*((-1)*hex)))/3*2)-1;
        long double dob_p = ((0.5+sqrt(0.25-4*3/2*((-1)*hex)))/3*2)-1;
        unsigned long long int int_t = (-0.5+sqrt(0.25-4*0.5*((-1)*hex)))*2-1;
        long double dob_t = (-0.5+sqrt(0.25-4*0.5*((-1)*hex)))*2-1;
        if (dob_p - int_p == 0 && dob_t - int_t == 0)
        {
            cout << i << ": " << hex << endl;
            cout << int_p << ": " << int_p*(3*int_p-1)/2 << endl;
            cout << int_t << ": " << int_t*(int_t+1)/2 << endl;
            nums_found++;
        }
    }
	return 0;
}
