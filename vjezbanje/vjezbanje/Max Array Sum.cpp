#include "pch.h"




//https://www.hackerrank.com/challenges/max-array-sum/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dynamic-programming

int MaxArraySum(std::vector<int>& array)
{
	int Include = array[0];
	int Exclude = 0;
	int temp;


	for (int i = 1; i < array.size(); i++)
	{
		temp = std::max(Include, Exclude);

		Include = Exclude + array[i];
		Exclude = temp;
	}


	return std::max(Include, Exclude);
}

void MaxArraySum()
{
	std::vector <int> array = { 2, 1, 2, 6, 1, 8, 10, 10 };

	std::cout << "\n\n\t" << MaxArraySum(array) << "\n\n\n\n";
}