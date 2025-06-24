/*#include <iostream>
#include <math.h>
#include <fstream>
#include <stdint-gcc.h>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream file("primes.txt");
    vector< unsigned long long int > primes(708863662);
    string liner;
    uint64_t counter = 0;
    while (getline(file,liner))
    {
        primes[counter] = atoi(liner.c_str());
        counter++;
    }
    counter = 0;
    double amount_of_primes = 0;
	uint64_t line = 3;
	double diagonals = 1;
	double i = 1;
	uint64_t current = 2;
	do
	{
        while (i <= line*line)
        {
            while (primes[counter] <= i)
            {
                if (primes[counter] == i)
                {
                    amount_of_primes++;
                }
                counter++;
            }
            double intpart;
            i += current;
            if (modf(sqrt(i), &intpart) == 0.0)
            {
                current += 2;
                diagonals += 4;
            }
        }
        cout << "Side length = " << line << ", amount of primes = " << amount_of_primes << ", diagonals = " << diagonals;
        cout << ", amp / diagonals = " << amount_of_primes/diagonals << endl;
        line+=2;
    } while (amount_of_primes / diagonals > 0.1);
    cout << amount_of_primes << " / " << diagonals << ", " << line-2 << endl;
	return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int is_prime(int n)
{
    if(n<2)return 0;
    if(n==2)return 1;
    if(n%2==0)return 0;
    int i;
    for(i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
int main()
{
    int total_elements=1,prime_elements=0;
    int i;
    float ratio;
    int element=1;
    int dimension=1;
    int increment=0;
    while(1)
    {
        dimension+=2;
        increment+=2;
        for(i=0;i<4;i++)
        {
            element+=increment;
            total_elements++;
            if(is_prime(element))prime_elements++;
        }
        ratio=(float)prime_elements/(float)total_elements;
        if(ratio<0.10)break;
    }
    printf("%d\n",dimension);
    return 0;
}
