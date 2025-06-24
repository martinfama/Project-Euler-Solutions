#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string stream = "";
	stringstream ss;
	ss.str("");
	for (unsigned long long int i = 1; i < 1000000; i++)
	{
        ss << i;
	}
	stream = ss.str();
	unsigned long long int result = (stream[0] - '0') * (stream[9] - '0') * (stream[99] - '0') * (stream[999] - '0') * (stream[9999] - '0') * (stream[99999] - '0') * (stream[999999] - '0');
	cout << result << endl;
	return 0;
}
