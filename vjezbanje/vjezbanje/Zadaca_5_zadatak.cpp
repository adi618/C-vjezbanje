#include "pch.h"



using namespace std;

double funkcija(double n)
{
	double clan = 1 / (n * (n + 1) * (n + 2));

	if (clan < 0.001)
		return 0;
	return clan + funkcija(n + 1);
}

void Zadaca_5_zadatak()
{
	cout << "Napisati rekurzivnu funkciju koja nalazi sumu niza realnih brojeva 1 / (n (n + 1) (n + 2))," << endl;
	cout << "pri cemu se sumiranje vrsi do prvog clana koji je manji od ucitane vrednosti 10 ^ -3" << endl << endl;

	double n;
	cout << "Unesite broj za funkciju 1 / (n * (n + 1) * (n + 2)), sumirati ce se svi clanovi dok jedan clan ne bude manji od 10 ^ -3: ";
	cin >> n;

	cout << "Suma: " << funkcija(n);
}