#include <iostream>

using namespace std;

int main()
{
    double final_p;
    int x = 0;
    for (double p = 5; p <= 1000; p++)
    {
        int y = 0;
        for (double c = 1; c < p; c++)
        {
            double b = p*(p-2*c)/2/(p-c);
            int b_int = p*(p-2*c)/2/(p-c);
            double a = p-b-c;
            if (b - b_int == 0 && b > 0 && c < b)
            {
                cout << c << ", " << b << ", " << a << endl;
                y++;
            }
        }
        if (x < y)
        {
            x = y;
            final_p = p;
        }
	}
	cout << x << ", " << final_p << endl;
	return 0;
}
