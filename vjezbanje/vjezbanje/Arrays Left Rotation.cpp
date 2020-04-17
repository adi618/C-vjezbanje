#include "pch.h"




using namespace std;

//https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=arrays&h_r=next-challenge&h_v=zen

vector<int> LeftRotate(vector<int>& array, int n)
{
	vector <int> rotated;
	rotated = array;


	n %= array.size();


	for (int i = 0; i < array.size() - n; i++)
	{

		rotated[i] = array[i + n];
	}

	int counter = 0;


	for (int i = array.size() - n; i < array.size(); i++)
	{

		rotated[i] = array[counter];


		counter++;
	}

	return rotated;
}

void LeftRotate()
{
	int a, n;
	vector <int> array;
	
	cout << "\n\n\tEnter the array elements:\n\t\t";
	
	cin >> a;
	while (a != 0)
	{
		array.push_back(a);
		cout << "\t\t";
		cin >> a;
	}

	cout << "\n\n\n\tEnter the number of rotations:\n\t\t";
	cin >> n;
	
	cout << "\n\n\n\tArray elements:\n\t\t";
	
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i] << "   ";
	}

	cout << "\n\n\n\tRotated array elements:\n\t\t";

	array = LeftRotate(array, n);

	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i] << "   ";
	}
	
	cout << "\n\n\n\n";

}