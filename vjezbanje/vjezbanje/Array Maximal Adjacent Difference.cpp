#include "pch.h"



int arrayMaximalAdjacentDifference(std::vector<int>& arr)
{
	int curr = abs(arr[0] - arr[1]);
	int max = curr;

	for (int i = 0; i < arr.size() - 1; i++)
	{
		curr = abs(arr[i] - arr[i + 1]);

		if (max < curr)
		{
			max = curr;
		}
	}

	return max;
}


void arrayMaximalAdjacentDifference()
{
	std::vector <int> arr = { 2 , 4 , 1, 0 };

	arrayMaximalAdjacentDifference(arr);
}