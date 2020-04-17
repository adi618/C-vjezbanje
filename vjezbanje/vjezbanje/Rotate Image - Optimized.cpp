#include "pch.h"



std::vector<std::vector<int>> rotateImageO(std::vector<std::vector<int>>& a)
{
	int n = a.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n - i - 1; ++j)
		{
			std::swap(a[i][j], a[j][n - i - 1]);
			std::swap(a[i][j], a[n - i - 1][n - j - 1]);
			std::swap(a[i][j], a[n - j - 1][i]);
		}
	}
	return a;
}

void rotateImageO()
{
	std::vector <std::vector<int>> a =    {	{1,2,3},
											{4,5,6},
											{7,8,9} };

	rotateImageO(a);

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			std::cout << a[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}