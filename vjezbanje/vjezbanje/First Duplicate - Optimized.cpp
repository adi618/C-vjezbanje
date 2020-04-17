#include "pch.h"



int firstDuplicateO(std::vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		int temp = abs(arr[i]);

		if (arr[temp - 1] < 0)
		{
			return arr[i];
		}

		arr[temp - 1] = -arr[temp - 1];
	}

	return -1;
}


void firstDuplicateO()
{
	std::vector <int> arr = { 2, 1, 3, 5, 3, 2 };

	firstDuplicateO(arr);
}