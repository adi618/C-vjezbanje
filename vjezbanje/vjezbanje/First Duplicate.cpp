#include "pch.h"



int firstDuplicate(std::vector<int> arr)
{
	int length = arr.size();

	int* numbers = (int*)calloc(length, sizeof(int));


	for (int i = 0; i < length; i++)
	{
		if (numbers[arr[i] - 1] == 0)
		{
			numbers[arr[i] - 1]++;
		}
		else
		{
			return arr[i];
		}
	}

	delete[] numbers;

	return -1;
}


void firstDuplicate()
{
	std::vector <int> arr = { 2, 1, 3, 5, 3, 2 };

	firstDuplicate(arr);
}