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



int main()
{
	std::vector<int> a = { 3, 7 };
	std::vector<int> s = { 1, 2 };
	std::vector<int> d = { -1, 1 };
	int k = 13;

	chessBishopDream(a, s, d, k);
}