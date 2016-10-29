#include <iostream>
#include <fstream>
#include <stdint-gcc.h>
#include <vector>
#include <cstdlib>
#include <math.h>

using namespace std;

int main()
{
    ifstream file("primes.txt");
    vector< unsigned long long int > primes(10000);
    string line;
    uint64_t counter = 0;
    while (getline(file,line))
    {
        primes[counter] = atoi(line.c_str());
        counter++;
    }
    uint64_t maximum = counter;
    for (int i = 9; i < 104729; i+=2)
    {
        counter = 0;
        bool is_prime = false;
        while (primes[counter] <= i && counter <= maximum && is_prime == false)
        {
            if (i == primes[counter])
            {
                is_prime = true;
            }
            //cout << i << endl;
            counter++;
        }
        if (is_prime == false)
        {
            counter = 0;
            bool is_true = false;
            for (int p = 1; pow(p, 2)*2 <= i-2 && is_true == false; p++)
            {
                counter = 0;
                uint64_t difference = pow(p, 2)*2;
                //cout << difference << endl;
                while (primes[counter]+difference <= i && is_true == false)
                {
                    if (primes[counter]+difference == i)
                    {
                        //cout << primes[counter] << " + 2x" << p << "^2 == " << i << endl;
                        is_true = true;
                    }
                    counter++;
                }
            }
            if (is_true == false)
            {
                cout << i << endl;
                i = 104729;
            }
        }
    }
    return 0;
}
