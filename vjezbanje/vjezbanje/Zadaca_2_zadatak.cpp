#include "pch.h"



using namespace std;

bool prost(int n, int i);

void Najblizi_Prosti_Broj(int n, int i)
{
	static bool positive = false;
	static bool negative = false;

	if (prost(n + i, 2))
		positive = true;

	if (prost(n - i, 2))
		negative = true;

	if (!positive && !negative)
		Najblizi_Prosti_Broj(n, i + 1);
	else
		if (positive && negative)
			cout << "Ovome broju su dva prosta broja najbliza, a to su: " << n + i << " i " << n - i;
		else
			cout << "Najblizi prost broj ovome broju je: " << ((positive) ? n + i : n - i);
}

void Zadaca_2_zadatak()
{
	cout << "Ispitati da li je uneti broj N prost koristeci rekurzivnu funkciju prost. Odrediti najblizi prost broj datom prirodnom broju koristeci rekurziju." << endl << endl;

	int n;
	cout << "Unesite broj da saznate da li je prost i koji mu je najblizi prost broj: ";
	cin >> n;

	cout << "\nUneseni broj " << ((prost(n, 2)) ? "je" : "nije") << " prost" << endl;

	Najblizi_Prosti_Broj(n, 1);
}