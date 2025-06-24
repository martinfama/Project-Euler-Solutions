#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream file("18.txt");
	string text = "";
	string lines = "";
    while (getline(file, lines))
	{
        text += lines;
        text += " ";
	}
	int numbers[text.length()/3];
	for (int i = 0; i < text.length()/3; i++)
	{
        char tens = text[i*3];
        char ones = text[i*3+1];
        numbers[i] = (tens - '0')*10 + (ones - '0');
	}
	int numbers_2[15][15];
	int counter = 0;
	for (int i = 0; i < 15; i++)
	{
        for (int j = 0; j < i+1; j++)
        {
            numbers_2[i][j] = numbers[counter];
            counter++;
            cout << numbers_2[i][j] << " ";
        }
        cout << endl;
	}
	unsigned long long int sum = 0;
	for (int )
	return 0;
}
