#include "pch.h"



using namespace std;

void unos()
{
	static int suma = 0;
	static int i = 0;
	cout << "Unesite broj: ";
	int n;
	cin >> n;
		
	suma = suma + n;
	i++;

	if (suma > 100) {
		cout << endl;
		cout << "Suma unesenih brojeva: " << suma << ". Broj unesenih brojeva: " << i;
		cout << endl;
		return;
	}

	unos();
}

void Vjezbanje_7_zadatak()
{
	cout << "Napisati rekurzivnu funkciju kojim se omogucuje unos prirodnih brojeva sa tastature sve dok njihova suma" << endl;
	cout << "ne postane veca od 100. Program stampa koliko je brojeva bilo potrebno uneti i kolika je vrenost sume." << endl << endl << endl;

	unos();
}