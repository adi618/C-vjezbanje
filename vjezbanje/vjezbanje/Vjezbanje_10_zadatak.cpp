#include "pch.h"



using namespace std;

int binarno(int n)
{
	if (n == 0)
		return 0;

	return binarno(n / 2) * 10 + n % 2;
}

void Vjezbanje_10_zadatak()
{
	cout << "Napisati rekurzivnu funkciju koja prevodi prirodan broj N iz dekadnog u binarni brojni sistem." << endl << endl;

	int x;
	cout << "Unesite broj: ";
	cin >> x;
	cout << binarno(x);
}