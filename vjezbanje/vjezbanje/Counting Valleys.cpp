#include "pch.h"



using namespace std;

//https://www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup

int CountingValleys(string string)
{
	bool sealevel = true;
	int level = 0, valleys = 0;


	for (int i = 0; i < string.size(); i++)
	{

		if (string[i] == 'D')
		{
			if (level == 0)
			{
				valleys++;
			}

			level--;
		}

		else 
			if (string[i] == 'U')
			{
				level++;
			}
	}

	return valleys;
}



void CountingValleys()
{
	string string;
	cout << "\n\n\tEnter string:\n\n\t\t";
	cin >> string;

	cout << "\n\n\n\tValleys entered: " << CountingValleys(string) << "\n\n\n\n";
}