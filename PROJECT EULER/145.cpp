#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

int main()
{
    unsigned long long int total = 0;
	for (unsigned long long int i = 1; i < 1000000000; i++)
	{
        if (i % 10000000 == 0)
        {
            cout << i/10000000 << "%" << endl;
        }
        if (i % 10 != 0)
        {
            stringstream current;
            current.str("");
            current << i;
            string rev = "";
            string cur = current.str();
            for (int j = cur.length()-1; j >= 0; j--)
            {
                rev += cur[j];
            }
            unsigned long long int reversed = 0;
            for (int j = 0; j < rev.length(); j++)
            {
                char d = rev[j];
                reversed += pow(10, rev.length()-j-1)*(d - '0');
            }
            unsigned long long int sum = i+reversed;
            current.str("");
            current << sum;
            rev = current.str();
            for (int j = 0; j < rev.length(); j++)
            {
                char t = rev[j];
                if (t != '1' && t != '3' && t != '5' && t != '7' && t != '9')
                {
                    j = rev.length()+1;
                }
                if (j == rev.length()-1)
                {
                    total++;
                }
            }
        }
	}
	cout << total << endl;
	return 0;
}
