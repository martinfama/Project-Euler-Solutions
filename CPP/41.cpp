#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdint.h>

using namespace std;

int main()
{
	ifstream file("primes.txt");
	string line;
	uint64_t counter = 0;
	uint64_t prime = 0;
	while(getline(file, line) && prime <= 9876543210)
	{
        prime = atoi(line.c_str());
        counter++;
	}
	cout << prime << endl;
	uint64_t primes[counter];
	file.close();
	file.open("primes.txt");
	uint64_t loop = 0;
	while (getline(file, line) && loop < counter)
	{
        primes[loop] = 0;
        cout << primes[loop] << endl;
        loop++;
	}
	return 0;
}
