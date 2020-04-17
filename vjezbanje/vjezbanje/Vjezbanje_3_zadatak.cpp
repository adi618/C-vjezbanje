#include "pch.h"



using namespace std;

int nzd(int a, int b)
{
	if (a == 0)
		return b;

	return nzd(b % a, a);
}

int Nzd(vector <int>& vector)
{
	int n = vector[0];

	for (int i = 1; i < vector.size(); i++)
		n = nzd(n, vector[i]);

	return n;
}

void Vjezbanje_3_zadatak()
{
	cout << "Napisati rekurzivnu funkciju za izracunavanje NZD - a dva broja.Unositi prirodne brojeve";
	cout << "\ndok se ne unese vrednost <= 0. Izracunati NZD unetih brojeva.\n\n";

	vector <int> vector;
	//vector.reserve(3);
	int n;
	cout << "\n\tUnesite broj: ";
	cin >> n;
	while (n > 0)
	{
		vector.push_back(n);
		//vector.emplace_back(n);
		cout << "\n\tUnesite broj: ";
		cin >> n;
	}
	cout << "\n\n\tNajveci zajednicki djelilac: " << Nzd(vector) << "\n\n\n";
}