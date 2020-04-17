#include "pch.h"



using namespace std;

//https://www.hackerrank.com/challenges/ctci-making-anagrams/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=strings

int alternatingCharacters(string& a)
{
	int count = 0;

	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] == a[i - 1])
			count++;
	}
	
	return count;
}

void alternatingCharacters()
{
	string a = "fcrxzwscanmligyxyvym";

	cout << alternatingCharacters(a);
}