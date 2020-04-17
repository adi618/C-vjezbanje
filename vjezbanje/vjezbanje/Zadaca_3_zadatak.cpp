#include "pch.h"



using namespace std;

void Hanoi(int n, int sa = 1, int na = 2, int preko = 3)
{
	if (n > 0)
	{
		Hanoi(n - 1, sa, preko, na);
		cout << sa << " -> " << na << endl;
		Hanoi(n - 1, preko, na, sa);
	}
}

void Zadaca_3_zadatak()
{
	int n;
	cout << "Unesite broj koji predstavlja broj stubova: ";
	cin >> n;

	Hanoi(n);
}