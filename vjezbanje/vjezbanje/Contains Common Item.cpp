#include "pch.h"
#include "Benchmark.h"

// Given 2 arrays, create a function that lets the user know (true/false) whether these two arrays contain any common items


bool quadraticTimeSolution(const std::vector<int>& arr1, const std::vector<int>& arr2)
{
	for (int num1 : arr1)
	{
		for (int num2 : arr2)
		{
			if (num1 == num2)	// Time complexity: O (a * b); space complexity: O(1)
				return true;
		}
	}
	return false;
}

bool linearTimeSolution(const std::vector<int>& arr1, const std::vector<int>& arr2)
{
	std::unordered_map <int, bool> dict;

	for (int num : arr1)
	{
		dict[num] = true;	// Time complexity: O (a + b); space complexity: O(a)
	}

	for (int num : arr2)
	{
		if (dict[num])
			return true;
	}
	return false;
}


void ContainsCommonItem()
{
	std::vector<int> arr1 = { 1,2,3,4,5,5,6 };
	std::vector<int> arr2 = { -1,-2,-3,-4,-5 };
	{
		Timer timer;
		std::cout << quadraticTimeSolution(arr1, arr2);
	}
	std::cout << "\n\n";
	{
		Timer timer;
		std::cout << linearTimeSolution(arr1, arr2);
	}
	std::cout << "\n\n";
}