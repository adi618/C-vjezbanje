#include "pch.h"



using namespace std;

int findOutlier(vector<int>& array)
{
	int odd = 0, even = 0;
	bool status = true;

	if (array[0] % 2 == 0)
		even++;
	else
		odd++;

	if (array[1] % 2 == 0)
		even++;
	else
		odd++;

	if (array[2] % 2 == 0)
		even++;
	else
		odd++;

	if (even < odd)
		status = false;


	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] % 2 == status || array[i] % 2 == -status)
			return array[i];
	}

	return -1;
}

void findOutlier()
{
	vector<int> array = { 2, -6, 8, -10, -3 };

	cout << findOutlier(array);
}