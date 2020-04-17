#include "pch.h"



using namespace std;

//https://www.hackerrank.com/challenges/repeated-string/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup

long NumberOfLetterAOccurrences(string string, long n)
{
	long A_Occurrences = 0;
	long counter = 0;

	for (int i = 0; i < string.size(); i++)
	{
		if (string[i] == 'a')
		{
			A_Occurrences++;
		}
	}

	A_Occurrences *= (n / string.size());

	for (int i = 0; i < n % string.size(); i++)
	{
		if (string[i] == 'a')
		{
			A_Occurrences++;
		}
	}

	return A_Occurrences;
}

void NumberOfLetterAOccurrences()
{
	string string;
	long n;

	cout << "\n\n\tEnter letters:\n\t\t";
	cin >> string;

	cout << "\n\n\tEnter the number of characters to consider:\n\t\t";
	cin >> n;
	
	cout << "\n\n\tNumber of letter A occurrences until the " << n << "th occurrense: " << NumberOfLetterAOccurrences(string, n);
	
	cout << "\n\n\n\n";
}