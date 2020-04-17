#include "pch.h"




using namespace std;

//https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup

int MinNumberOfJumps(vector <int>& vector)
{
	int jumps = 0;

	for (int i = 0; i < vector.size() - 1; i++)
	{

		if (vector[i + 2] == 0)
			i++;


		jumps++;
	}

	return jumps;
}

void MinNumberOfJumps()
{
	vector <int> vector;
	
	cout << "\n\n\tEnter elements (0 or 1):\n\n\t\t";

	int a;
	cin >> a;

	while (a == 0 || a == 1)
	{
		vector.push_back(a);
		cout << "\t\t";
		cin >> a;
	}

	cout << "\n\n\n\tArray elements:\n\t\t";
	
	for (int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << "   ";
	}
	
	cout << "\n\n\n";
	
	cout << "\tMin number of jumps: " << MinNumberOfJumps(vector);
	
	cout << "\n\n\n\n";
}