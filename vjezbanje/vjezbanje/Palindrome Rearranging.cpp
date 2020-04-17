#include "pch.h"



bool palindromeRearranging(std::string inputString)
{
	int alphabet[26] = { 0 };
	int oddNumber = 0;

	for (int i = 0; i < inputString.size(); i++)
	{
		alphabet[(int)inputString[i] - (int)'a']++;
	}

	for (int i = 0 ; i < 26;i++)
	{
		if (alphabet[i] % 2 == 1)
		{
			oddNumber++;
		}
	}

	if (inputString.size() % 2 == 0)
		return oddNumber == 0;
	else
		return oddNumber == 1;
}

void palindromeRearranging()
{
	std::string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaabc";

	palindromeRearranging(s);
}