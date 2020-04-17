#include "pch.h"



using namespace std;

bool BinarySearch(int array[], int left, int right, int n)
{
	int mid;
	if (left <= right)
	{
		//mid = (left + right) / 2;
		mid = left + (right - left) / 2;
		if (array[mid] == n)
			return true;
		else
			if (array[mid] > n)
				BinarySearch(array, left, mid - 1, n);
			else
				BinarySearch(array, mid + 1, right, n);
	}
	else
		return false;
}

bool BinarySearchWithIteration(int array[], int left, int right, int n)
{
	int mid;
	while (left <= right)
	{
		//mid = (left + right) / 2;
		mid = left + (right - left) / 2;
		if (array[mid] == n)
			return true;
		else
			if (array[mid] > n)
				right = mid - 1;
			else
				left = mid + 1;
	}
	return false;
}

void BinarySearch()
{
	int array[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int n;

	cout << "\n\n\tElementi niza:";
	for (int i = 0; i < 15; i++)
		cout << setw(5) << array[i];

	cout << "\n\n\n\t\tTrazi: ";
	cin >> n;

	cout << "\n\n\t\t\tBroj " << ((BinarySearch(array, 0, 15, n)) ? "je" : "nije") << " pronadjen koristeci rekurziju!\n";
	cout << "\n\n\t\t\tBroj " << ((BinarySearchWithIteration(array, 0, 15, n)) ? "je" : "nije") << " pronadjen koristeci iteraciju!\n\n\n";
}