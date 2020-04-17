#include "pch.h"



using namespace std;


bool binaryToDecimal(string s)
{
	int decimal = 0, counter = 0;
	string copy;

	for (int i = s.size() - 1; i > -1; i--)
	{
		copy.push_back(s[i]);
		counter++;
	}

	for (int i = 0; i < copy.size(); i++)
	{
		if (copy[i] == '1')
		{
			decimal = decimal + pow(2, i);
		}
		else if (copy[i] == '0') {}
		else
			return false;
	}

	if (decimal % 3 == 0)
		return true;
	else
		return false;
}

void binaryToDecimal()
{
	string s;
	getline(cin, s);

	cout << binaryToDecimal(s);
}