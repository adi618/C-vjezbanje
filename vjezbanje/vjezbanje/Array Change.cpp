#include "pch.h"



int arrayChange(std::vector<int>& arr)
{
	int minMoves = 0;
	int current;

	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i] >= arr[i + 1])
		{
			current = arr[i] - arr[i + 1] + 1;
			minMoves += current;
			arr[i + 1] += current;
		}
	}

	return minMoves;
}

void arrayChange()
{
	std::vector <int> arr = { 1,1,1 };

	std::cout << arrayChange(arr);
}