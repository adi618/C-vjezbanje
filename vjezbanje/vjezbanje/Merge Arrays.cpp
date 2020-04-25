#include "pch.h"


// Create a function that takes in two sorted arrays and merges them

std::vector <int> MergeArrays(const std::vector <int>& arr1, const std::vector <int>& arr2)
{
	if (arr1.size() == 0)
		return arr2;

	if (arr2.size() == 0)
		return arr1;

	std::vector <int> mergedArray;
	mergedArray.reserve(arr1.size() + arr2.size());

	int counter1 = 0, counter2 = 0;

	while (counter1 < arr1.size() && counter2 < arr2.size())		// bugged
	{
		if (counter1 < arr1.size())
		{
			if (arr1[counter1] < arr2[counter2] || !(counter2 < arr2.size() - 1))
			{
				mergedArray.push_back(arr1[counter1]);
				counter1++;
			}
		}
		else
		{
			mergedArray.push_back(arr2[counter2]);
			counter2++;
		}

	}
	return mergedArray;
}


void mergeArrays()
{
	std::vector <int> arr1{ 1, 5, 7, 8, 9 };
	std::vector <int> arr2{ 1, 2, 3, 4, 5, 9 };

 	std::vector <int> arr3 = MergeArrays(arr1, arr2);
	return;
}