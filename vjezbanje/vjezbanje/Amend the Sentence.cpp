#include "pch.h"

std::string amendTheSentence(std::string& s)
{
	int length = s.size();

	for (int i = length; i > -1; i--)
	{
		if (s[i] < 91)
		{
			s[i] += 32;
			s.insert(s.begin() + i, ' ');
		}
	}

	length = s.size() - 1;

	if (s[length] == ' ')
		s.erase(s.begin() + length);

	if (s[0] == ' ')
		s.erase(s.begin());

	return s;
}

void amendTheSentence()
{
	std::string s = "CodesignalIsAwesome";

	amendTheSentence(s);
}