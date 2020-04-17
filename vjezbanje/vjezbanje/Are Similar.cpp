#include "pch.h"



bool areSimilar(std::vector<int>& a, std::vector<int>& b)
{
	std::vector <int> s;
	s.reserve(4);

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			s.push_back(a[i]);
			s.push_back(b[i]);
		}
	}

	if (s.size() == 0)
		return true;

	if (s.size() != 4)
		return false;

	if (s[0] == s[3] && s[1] == s[2])
		return true;
	else
		return false;
}

void areSimilar()
{
	std::vector <int> a = { 1, 2, 3 };
	std::vector <int> b = { 1, 2, 3 };

	std::cout << areSimilar(a, b);
}