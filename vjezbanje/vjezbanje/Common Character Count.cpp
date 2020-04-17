#include "pch.h"



int commonCharacterCount(std::string s1, std::string s2)
{
	int common = 0;
	int s1_Frequencies[26] = { 0 };
	int s2_Frequencies[26] = { 0 };

	for (unsigned i = 0; i < s1.size(); i++)
	{
		s1_Frequencies[s1[i] - (int)'a']++;
	}

	for (unsigned i = 0; i < s2.size(); i++)
	{
		s2_Frequencies[s2[i] - (int)'a']++;
	}

	for (unsigned i = 0; i < 26; i++)
	{
		common += std::min(s1_Frequencies[i], s2_Frequencies[i]);
	}

	return common;
}

void commonCharacterCount()
{
	std::string a = "aabcc";
	std::string b = "adcaa";

	std::cout << commonCharacterCount(a, b);
}