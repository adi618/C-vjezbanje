#include "pch.h"


void SelectionSort(std::vector <int>& array)		// Time: O(n^2); Space: O(1)
{
	int min;
	for (int i = 0; i < array.size(); i++)
	{
		min = i;
		for (int j = i + 1; j < array.size() - 1; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}
		std::swap(array[i], array[min]);
	}
}



void SelectionSort()
{
	std::vector <int> array = { 1,5,7,4,3,7,8,4,5,7,3 };
	SelectionSort(array);
	return;
}