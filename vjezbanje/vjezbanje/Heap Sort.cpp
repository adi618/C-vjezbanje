#include "pch.h"


void heap(std::vector <int>& array, int size, int i)
{
	int root = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size and array[left] > array[root])
		root = left;

	if (right < size and array[right] > array[root])
		root = right;

	if (root != i)
	{
		std::swap(array[i], array[root]);

		heap(array, size, root);
	}
}

void HeapSort(std::vector <int>& array)
{
	for (int i = array.size() / 2 - 1; i >= 0; i--)
	{
		heap(array, array.size(), i);
	}

	for (int i = array.size() - 1; i >= 0; i--)
	{
		std::swap(array[0], array[i]);

		heap(array, i, 0);
	}
}


void HeapSort()
{
	std::vector <int> array = { 1,2,6,8,7,9,5,3,5,8,0,4 };

	HeapSort(array);
	return;
}