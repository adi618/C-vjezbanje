#include "pch.h"



std::vector<int> alternatingSums(std::vector<int>& arr)
{
	int a = 0, b = 0;
	
	for (int i = 0; i < arr.size(); i++)
	{
		if (i % 2 == 1)
		{
			a += arr[i];
		}
		else
		{
			b += arr[i];
		}
	}

	std::vector <int> temp;

	temp.push_back(b);
	temp.push_back(a);

	return temp;
}


void alternatingSums()
{
	std::vector <int> arr = { 50, 60, 60, 45, 70 };

	arr = alternatingSums(arr);

	std::cout << arr[0] << std::endl << arr[1];
}