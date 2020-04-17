#include "pch.h"


char firstNotRepeatingCharacter(std::string s)
{
	int arr[26] = { 0 };

	for (int i = 0; i < s.size(); i++)
	{
		arr[s[i] - (int)'a']++;
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (arr[s[i] - (int)'a'] == 1)
			return s[i];
	}

	return '_';
}

void firstNotRepeatingCharacter()
{
	std::string s = "abacabad";

	firstNotRepeatingCharacter(s);
}