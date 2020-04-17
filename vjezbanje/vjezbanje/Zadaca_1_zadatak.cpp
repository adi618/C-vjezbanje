#include "pch.h"



using namespace std;

int dvostruki_faktorijel(int n)
{
	if (n < 2) 
		return 1;

		return n * dvostruki_faktorijel(n - 2);
}

int suma_kvadrata_dvostrukih_faktorijela(int n)
{
	if (n == 0)
		return 0;

	return pow(dvostruki_faktorijel(n % 10), 2) + suma_kvadrata_dvostrukih_faktorijela(n / 10);
}

void provjera_i_ispis(int n)
{
	cout << endl << "Ti brojevi su: ";

	for (int i = 1; i < n; i++)
		if (i == suma_kvadrata_dvostrukih_faktorijela(i))
			cout << i << "  ";
}

void Zadaca_1_zadatak()
{
	cout << "Ispisati sve prirodne brojeve manje od N koji su jednaki sumi kvadrata dvostrukih faktorijela svojih cifara." << endl << endl;
	
	int n;
	cout << "Unesite broj do kojega zelite da program ispise sve prirodne brojeve koji su jednaki sumi kvadrata dvostrukih faktorijela svojih cifara: ";
	cin >> n;

	provjera_i_ispis(n);
}