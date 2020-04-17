#include "pch.h"



using namespace std;

int nzd(int, int);

int NZS(int a, int b)
{
	return a * b / nzd(a, b);
}

void Vjezbanje_4_zadatak()
{
	cout << "Napisati rekurzivnu funkciju kojom se izracunava najmanji zajednicki sadrzalac\n";
	cout << "dva prirodna broja tako sto se maksimumu dva broja dodaje 1 u svakom rekurzivnom pozivu.\n\n\n";

	int a, b;
	cout << "\tUnesite dva broja:\n\n\t\t";
	cin >> a;
	cout << "\n\t\t";
	cin >> b;
	cout << "\n\tNajmanji zajednicki sadrzalac: " << NZS(a, b) << "\n\n\n";
}