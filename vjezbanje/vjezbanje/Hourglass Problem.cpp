#include "pch.h"




using namespace std;

//https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=arrays

int	HourglassSum(vector<vector<int>>& matrix)
{
	int Max = -2000000000, Sum = 0;


	for (int i = 0; i < 4; i++)
	{

		for (int j = 0; j < 4; j++)
		{

			Sum = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i + 1][j + 1] + matrix[i + 2][j] + matrix[i + 2][j + 1] + matrix[i + 2][j + 2];
			

			if (Sum > Max)
				Max = Sum;
		}
	}

	return Max;
}

void HourglassSum()
{
	const int rows = 6, columns = 6;
	vector<vector<int>> matrix;
	int a;

	cout << "\n\n\tEnter the array elements:\n";

	for (int i = 0; i < rows; i++)
	{
		vector <int> temp;
		for (int j = 0; j < columns; j++)
		{
			cout << "\t\t";
			cin >> a;
			temp.push_back(a);
		}

		matrix.push_back(temp);
	}

	cout << "\n\n\t\t";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << setw(4) << matrix[i][j];
		}
		cout << "\n\t\t";
	}

	cout << "\n\n\n\tBiggest sum of hourglass shapes: " << HourglassSum(matrix);

}