#include "pch.h"



using namespace std;

int obrni(int n)
{
	static int obrnuto = 0;
	obrnuto = obrnuto * 10 + n % 10;

	if (n < 10)
		return obrnuto;

	return obrni(n / 10);
}

void Zadaca_6_zadatak()
{
	cout << "Napisati rekurzivnu funkciju koja od broja N odredjuje broj ispisan u obrnutnom poretku." << endl;
	cout <<"Ispitati da li je uneti broj N palindrom(pise se isto i s leva i s desna).Npr. 12321, 3456543." << endl << endl;

	int n;
	cout << "Unesite broj cije cifre zelite obrnuti: ";
	cin >> n;

	int obrnuto = obrni(n);

	cout << "Uneseni broj sa obrnutim ciframa: " << obrnuto << endl;
	cout << "Ovaj broj " << ((obrnuto == n) ? "je" : "nije") << " palindrom";
}