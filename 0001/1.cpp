#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	unsigned long long int number = 0;
	for (unsigned long long int i = 0; number < 2000000; i++)
	{
        number += i;
        cout << number << endl;
	}
	return 0;
}
