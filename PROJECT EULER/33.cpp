#include <iostream>

using namespace std;

int main()
{
	for (int i = 11; i < 100; i++)
	{
        for (int j = 11; j < i; j++)
        {
            if (i%10 != 0 && j%10 != 0)
            {
                if (float(j%10)/(i%10) == float(j)/i && j/10==i/10)
                {
                    cout << j << "/" << i << " = " << j%10 << "/" << i%10 << endl;
                }
                else if (float(j/10)/(i%10) == float(j)/i && j%10==i/10)
                {
                    cout << j << "/" << i << " = " << j/10 << "/" << i%10 << endl;
                }
                else if (float(j%10)/(i/10) == float(j)/i && j/10==i%10)
                {
                    cout << j << "/" << i << " = " << j%10 << "/" << i/10 << endl;
                }
                else if (float(j/10)/(i/10) == float(j)/i && j%10==i%10)
                {
                    cout << j << "/" << i << " = " << j/10 << "/" << i/10 << endl;
                }
            }
        }
	}
    return 0;
}
