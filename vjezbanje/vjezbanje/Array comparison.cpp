#include "pch.h"



bool same(const std::vector<int>& arr1, const std::vector<int>& arr2)
{
	if (arr1.size() != arr2.size())
		return false;

	std::map<int, int> dict1;
	std::map<int, int> dict2;

	for (int num : arr1)
		if (dict1[num])
			dict1[num]++;
		else
			dict1[num] = 1;

	for (int num : arr2)
		if (dict2[num])
			dict2[num]++;
		else
			dict2[num] = 1;

	for (int key : arr1)
		if (dict1[key * key] != dict2[key])
			return false;

	return true;
}

void ArrayComparison()
{
	std::cout << same({ 1,1,2 }, { 1,1,4 }) << std::endl;
	std::cout << same({ 2,1,2 }, { 1,1,4 }) << std::endl;
	std::cout << same({ 8,5,3,2 }, { 9,25,4,64 }) << std::endl;
}