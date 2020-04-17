#include "pch.h"



using namespace std;

int array_Max_Sum_Consecutive_Elements(vector <int>& vector)		//Kadanes algorithm
{
	int Max = vector[0];
	int Sum = Max;

	for (int i = 1; i < vector.size(); i++)
	{
		if (Sum + vector[i] > vector[i])
			Sum += vector[i];
		else
			Sum = vector[i];

		if (Max < Sum)
			Max = Sum;
	}

	return Max;
}


void array_Max_Sum_Consecutive_Elements()
{
	cout << "Korisnik unosi niz, program ispisuje najveci broj koji se moze dobiti sabiranjem susjednih elemenata\n\n\n";

	vector <int> vector;
	vector.reserve(3);

	cout << "\n\tMolimo unesite elemente matrice, kraj unosa matrice oznacite sa '0':\n\t\t";

	int a;
	cin >> a;

	while (a != 0)
	{
		vector.push_back(a);
		cout << "\t\t";
		cin >> a;
	};

	cout << "\n\n\tElementi matrice:\n\n\t\t";

	for (int i = 0; i < vector.size(); i++) {
		cout << vector[i] << "   ";
	}

	cout << "\n\n\n\n\tNajveci broj koji se moze dobiti sabiranjem sujednih elemenata: "
		<< array_Max_Sum_Consecutive_Elements(vector)
		<< "\n\n\n\n";

}