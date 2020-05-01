#include "pch.h"


int partition(std::vector <int>& array, int pivot, int left, int right)
{
	int pivotValue = array[pivot];
	int partitionIndex = left;

	for (int i = left; i < right; i++)
	{
		if (array[i] > pivotValue)
		{
			std::swap(array[i], array[partitionIndex]);
			partitionIndex++;
		}
	}
	std::swap(array[right], array[partitionIndex]);

	return partitionIndex;
}


void QuickSort(std::vector <int>& array, int right, int left = 0)
{
	if (left < right)
	{
		int pivot = right;
		int partitionIndex = partition(array, pivot, left, right);

		QuickSort(array, left, partitionIndex - 1);
		QuickSort(array, partitionIndex + 1, right);
	}
}


void QuickSort(std::vector <int>& array)
{
	QuickSort(array, array.size() - 1);
}


void QuickSort()		// bugged
{
	std::vector <int> array = { 1,2,6,8,7,9,5,3,5,8,0,4 };

	QuickSort(array);
	return;
}