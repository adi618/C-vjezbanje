#include "pch.h"



using namespace std;

//https://www.hackerrank.com/challenges/ctci-making-anagrams/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=strings

int makeAnagram(string& a, string& b)
{
	int totalLettersDeleted = 0;

	int a_Frequencies[26];
	int b_Frequencies[26];

	for (int i = 0; i < 26; i++)
	{
		a_Frequencies[i] = 0;
		b_Frequencies[i] = 0;
	}

	for (int i = 0; i < a.size(); i++)
	{
		a_Frequencies[a[i] - (int)'a']++;
	}

	for (int i = 0; i < b.size(); i++)
	{
		b_Frequencies[b[i] - (int)'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		totalLettersDeleted += abs(a_Frequencies[i] - b_Frequencies[i]);
	}


	return totalLettersDeleted;
}

void makeAnagram()
{
	string a = "fcrxzwscanmligyxyvym";
	string b = "jxwtrhvujlmrpdoqbisbwhmgpmeoke";

	cout << makeAnagram(a, b);


	vector <int> name;


}