#include "pch.h"



using namespace std;

void Zadatak_2()
{
	cout << "\n\n\n\t";

	int arr[5];

	int* ptr = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << "\t";
		cin >> *(ptr + i);
	}

	cout << "\n\n\n\t";

	for (int i = 0; i < 5; i++)
	{
		cout << *(ptr + i) << " ";
	}

	cout << "\n\n\n\t";

	for (int i = 0; i < 5; i++)
	{
		cout << *(ptr + i) * 7 << " ";
	}

	cout << "\n\n\n\t";
}