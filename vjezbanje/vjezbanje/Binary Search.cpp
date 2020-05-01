#include "pch.h"


int BinarySearch(const std::vector <int>& array, int key)
{
	int left = 0;
	int right = array.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (key == array[mid])
			return mid;

		if (key < array[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	return -1;
}


void BinarySearch()
{
	std::vector <int> array { 1,2,5,6,8,11,55,243,3456,13643 };

	std::cout << BinarySearch(array, 6);
	return;
}