#include "pch.h"


void BubbleSort(std::vector <int>& array)		// Time: O(n^2); Space: O(1)
{
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < array.size() - 1; j++)
		{
			if (array[j] > array[j + 1])
				std::swap(array[j], array[j + 1]);
		}
	}
}