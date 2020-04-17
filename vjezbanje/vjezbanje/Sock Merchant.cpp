#include "pch.h"




using namespace std;

//https://www.hackerrank.com/challenges/sock-merchant/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup

int socks(vector <int>& vector)
{
	int pairs = 0;

	for (int i = 0; i < vector.size(); i++)
	{

		for (int j = i + 1; j < vector.size(); j++)
		{

			if (vector[i] == vector[j])
			{
				pairs++;
				vector.erase(vector.begin() + j);
				break;
			}
		}
	}
	return pairs;
}

void socks()
{
	int a;
	vector <int> vector;

	cout << "\n\n\tEnter the array elements:\n\t\t";

	cin >> a;
	while (a != 0)
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

	cout << "Max number of pairs: " << socks(vector);

	cout << "\n\n\n\n";
}