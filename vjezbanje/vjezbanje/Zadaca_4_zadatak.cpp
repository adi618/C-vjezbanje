#include "pch.h"




using namespace std;

bool prost(int n, int i);

void goldbaha(int n, int i)
{
	if (n > 2 && n % 2 == 0)
	{
		if (prost(i, 2) && prost(n - i, 2))
			cout << "\nOvaj broj se moze napisati kao zbir dva prosta broja: " << i << " + " << n - i;
		else
			goldbaha(n, i + 1);
	}
	else
	{
		cout << "\nUneseni broj se ne moze napisati kao zbir dva prosta broja";
		return;
	}
}

void Zadaca_4_zadatak()
{
	cout << "Za paran broj N proveriti hipotezu Goldbaha koriscenjem rekurzije. Prema toj hipotezi," << endl;
	cout << "svaki paran broj veci od 2 moze se predstaviti zbirom dva prosta broja." << endl;
	cout << endl;
	cout << "Resenje se sastoji u proveri da li je za svaki prost broj i(i = 3, ..., n / 2) broj n - i takode prost." << endl;
	cout << "Da li je broj prost proverava se funkcijom prost." << endl << endl;

	int n;
	cout << "Unesite broj da provjerite moze li se napisati kao zbir prostih brojeva: ";
	cin >> n;

	goldbaha(n, 2);
}