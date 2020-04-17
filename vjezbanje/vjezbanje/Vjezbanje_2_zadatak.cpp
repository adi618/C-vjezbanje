#include "pch.h"



using namespace std;

int Factorijel(int n)
{
	if (n < 1)
		return 1;

	return n * Factorijel(n - 1);
}

int SumaFaktorijela(int n)
{
	if (n == 0)
		return 0;

	return Factorijel(n % 10) + SumaFaktorijela(n / 10);
}

void Vjezbanje_2_zadatak()
{
	cout << "\n\tIspisati sve trocifrene brojeve koji su jednaki sumi faktorijela svojih cifara:\n\n\t";

	for (int i = 100; i < 1000; i++)
		if (i == SumaFaktorijela(i))
			cout << setw(7) << i;
	cout << "\n\n\n";
}