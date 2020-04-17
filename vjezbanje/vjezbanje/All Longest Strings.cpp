#include "pch.h"



std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray)
{
	std::vector<std::string> temp;
	int max = 0;


	for (int i = 0; i < inputArray.size(); i++)
	{
		if (inputArray[i].size() > max)
		{
			max = inputArray[i].size();
		}
	}

	for (int i = 0; i < inputArray.size(); i++)
	{
		if (inputArray[i].size() == max) {
			temp.push_back(inputArray[i]);
		}
	}

	return temp;
}

void allLongestStrings()
{
	std::vector <std::string> arr =		  {	 "enyky",
											 "benyky",
											 "yely",
											 "varennyky" };


	std::vector <std::string> arr2 = allLongestStrings(arr);

	for (int i = 0; i < arr2.size(); i++)
	{
		std::cout << arr2[i] << "  ";
	}
}