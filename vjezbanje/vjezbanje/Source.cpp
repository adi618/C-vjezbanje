#include "pch.h"


void singlyLinkedList();
void doublyLinkedList();
void DTStack();
void DTQueue();
void DTBinarySearchTree();
void SelectionSort();
void InsertionSort();
void MergeSort();
void QuickSort();
void HeapSort();
void Adi_Zubic_Zadaca_6_Z15();
void BinarySearch();
void BreadthFirstSearch();
void Adi_Zubic_Zadaca_6_Z6();
void DepthFirstSearch();
void DTSStackv2();
void ContainsCommonItem();


std::vector<std::vector<int>> spiralNumbers(int n)
{
	std::vector <std::vector <int>> matrix(n, std::vector <int>(n));

	int num = 1;
	int x = 0;
	int y = 0;
	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };
	int i = 0;
	int counter = 1;
	bool outer = true;

	while (num != n * n + 1)
	{
		if (x < n - 1 and y < n - 1 and matrix[x + dx[i]][y + dy[i]])
		{
			outer = false;
			i = (i + 1) % 4;
		}

		if (outer)
		{
			if (counter % n == 0)
			{
				i = (i + 1) % 4;
				counter++;
			}
			counter++;
		}

		matrix[x][y] = num;

		x += dx[i];
		y += dy[i];

		num++;
	}

	return matrix;
}


std::vector<int> chessBishopDream(std::vector<int> boardSize, std::vector<int> initPosition, std::vector<int> initDirection, int k)
{
	if (boardSize[0] == 1 && boardSize[1] == 1)
	{
		return { 0, 0 };
	}
	int dx[] = { -1, 1, 1, -1 };
	int dy[] = { 1, 1, -1, -1 };

	int d;
	int x = initPosition[0];
	int y = initPosition[1];

	for (int i = 0; i < 4; i++)
	{
		if (initDirection[0] == dx[i] and initDirection[1] == dy[i])
		{
			d = i;
			break;
		}
	}

	for (int i = 1; i < k; i++)
	{
		int a = 1;

		if ((x + dx[d] == boardSize[0] and y + dy[d] == boardSize[1]) or
			(x + dx[d] == boardSize[0] and y + y + dy[d] < 0) or
			(x + dx[d] < 0 and y + dy[d] == boardSize[1]) or
			(x + dx[d] < 0 and y + y + dy[d] < 0))
		{
			d = (d + 2) % 4;
			x += dx[d];
			y += dy[d];
			continue;
		}

		if (d % 2 == 0)
		{
			if (x + dx[d] >= boardSize[0] or x + dx[d] < 0)
			{
				d = (d + 1) % 4;
				y += dy[d];
				continue;
			}

			else if (y + dy[d] >= boardSize[1] or y + dy[d] < 0)
			{
				d = (d - 1) % 4;
				x += dx[d];
				continue;
			}
		}
		else
		{
			if (x + dx[d] >= boardSize[0] or x + dx[d] < 0)
			{
				d = (d - 1) % 4;
				y += dy[d];
				continue;
			}

			else if (y + dy[d] >= boardSize[1] or y + dy[d] < 0)
			{
				d = (d + 1) % 4;
				x += dx[d];
				continue;
			}
		}

		x += dx[d];
		y += dy[d];
	}

	return { x, y };
}



int stringsConstruction(std::string a, std::string b)
{
	int res = 333333;
	std::map <char, int> string1;
	std::map <char, int> string2;

	for (auto letter : a)
	{
		string1[letter]++;
	}

	for (auto letter : b)
	{
		string2[letter]++;
	}

	for (char letter : a)
	{
		if (string2[letter] / string1[letter] < res)
			res = string2[letter] / string1[letter];
	}

	return res;
}



bool subsetSum(std::vector<int> arr)
{
	int sum = 0;

	for (int n : arr)
	{
		sum += n;
	}

	for (int i = 2; i < arr.size(); i++)
	{
		for (int n : arr)
		{
			if (sum / i == n)
				return true;
		}
	}

	return false;
}




int main()
{
	std::vector <int> a = { 258, 924, 637, 62, 624, 600, 36, 452, 899, 379, 550, 468, 71, 973, 131, 881, 930, 933, 894, 660, 163, 199, 981, 899, 996, 959, 773, 813, 668, 190, 95, 926, 466, 84, 340, 90, 684, 376, 542, 936, 107, 445, 756, 179, 418, 887, 412, 348, 172, 659, 9, 336, 210, 342, 587, 206, 301, 713, 372, 321, 255, 819, 599, 721, 904, 939, 811, 940, 667, 705, 228, 127, 150, 984, 658, 920, 224, 422, 269, 396, 81, 630, 84 };

	subsetSum(a);
}