#include "pch.h"




std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>>& a)
{
	int length = a.size();

	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			std::swap(a[i][j], a[j][i]);
		}
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length / 2; j++)
		{
			std::swap(a[i][j], a[i][length - 1 - j]);
		}
	}

	return a;
}

void rotateImage()
{
	std::vector <std::vector<int>> a =    {	{1,2,3},
											{4,5,6},
											{7,8,9} };

	rotateImage(a);

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			std::cout << a[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}