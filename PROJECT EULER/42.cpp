#include <iostream>
#include <math.h>
#include <stdint.h>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ifstream file("42.txt"); //The text file containing the words
	string line;
	string liner;
	while (getline(file, line))
	{
        liner = line;
	}
	string line_2 = "";
	stringstream ss;
	ss.str("");
	int counter = 0;
	int total_words = 0;
    for (int i = 0; i < liner.length(); i++)   //Counts the words and also adds the to a Stringstream
	{
        char t = liner[i];
        if (t != '"' && t != ',')
        {
            counter = 0;
            ss << liner[i];
        }
        else
        {
            counter++;
            if (counter == 3)
            {
                total_words++;
                ss << endl;
            }
        }
	}
	line_2 = ss.str();
	string words[total_words];                   //Create an array of strings for each word
	counter = 0;
	for (int i = 0; i < total_words; i++)
	{
        ss.str("");
        bool n_line = false;
        while (n_line == false)
        {
            if (line_2[counter] == char(10))         //Sorts through the long string, which has newlines, and checks for
            {                                        //these newlines
                n_line = true;
            }
            if (n_line == false)
            {
                ss << line_2[counter];
            }
            counter++;
        }
        words[i] = ss.str();
	}
	int triangular_words = 0;
	for (int i = 0; i < total_words; i++)
	{
        int word_value = 0;
        for (int j = 0; j < words[i].length(); j++)                              //The actual triangular checking
        {
            word_value += int(words[i][j])-64;
        }
        uint64_t integer = (-1+(sqrt(1-(4*(word_value*-2)))))/2;
        long double dob = (-1+(sqrt(1-(4*(word_value*-2)))))/2;
        if (dob-integer == 0)
        {
            triangular_words++;     //If dob-integer wasn't eqaul to 0, the number wouldn't be triangular
        }
	}
	cout << triangular_words << endl;
	return 0;
}
