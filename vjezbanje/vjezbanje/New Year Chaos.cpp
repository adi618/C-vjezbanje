#include "pch.h"




using namespace std;

//https://www.hackerrank.com/challenges/new-year-chaos/problem

void minimumBribes(vector<int>& array)
{
	int bribes = 0;


	for (int i = array.size() - 1; i > -1; i--)
	{

		if (array[i] > i + 1 + 2)
		{
			cout << "Too chaotic" << endl;
			return;
		}

		int max = 0;
		if (array[i] - 2 > 0)
			max = array[i] - 2;

		for (int j = max; j < i; j++)
		{

			if (array[j] > array[i])
			{
				bribes++;
			}
		}
	}

	cout << bribes << endl;
}

void minimumBribes()
{
	int a;
	vector <int> array;
	
	cout << "\n\n\tEnter the array elements:\n\t\t";
	
	cin >> a;
	while (a != 0)
	{
		array.push_back(a);
		cout << "\t\t";
		cin >> a;
	}

	cout << "\n\n\n\n\t\t";


	minimumBribes(array);


	cout << "\n\n\n\n";
}


/*


1 2 3 4 5 6 7 8  : 0  (initial)
1 2 3 5 4 6 7 8  : 1  (5 and 4)
1 2 3 5 6 4 7 8  : 2  (6 and 4)
1 2 3 5 6 7 4 8  : 3  (7 and 4)
1 2 3 5 6 7 8 4  : 4  (8 and 4)
1 2 5 3 6 7 8 4  : 5  (5 and 3)
1 2 5 3 7 6 8 4  : 6  (7 and 6)
1 2 5 3 7 8 6 4  : 7  (8 and 6)


*/