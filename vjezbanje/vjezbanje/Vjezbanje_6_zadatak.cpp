#include "pch.h"



using namespace std;

int suma_delitelja(int n)
{
	static int i = 2, suma = 0;

	if (n % i == 0) {
		if (i == (n / i))
			suma += i;
		else
			suma += (i + n / i);
	}
	i++;
	if (i <= sqrt(n))
		return suma_delitelja(n);

	i = 2;
	int temp = suma;
	suma = 0;

	return temp + 1;
}

int divSum(int num)
{
	int suma = 0;

	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			if (i == (num / i))
				suma += i;
			else
				suma += (i + num / i);
		}
	}

	return (suma + 1);
}

void Vjezbanje_6_zadatak()
{
	cout << "Ispisati sve parove prijateljskih brojeva od 1..10000.Dva broja su prijateljska ukoliko je svaki od" << endl;
	cout << "njih jednak sumi delitelja drugog broja.Npr. 220 = 1 + 2 + 4 + 71 + 142     284 = 1 + 2 + 4 + 5 + ... + 110" << endl << endl;


	for (int i = 1; i < 10001; i++)
		for (int j = i; j < 10001; j++)
			if (divSum(i) == j && divSum(j) == i)
				cout << "Broj " << i << " i " << j << " su prijateljski brojevi!" << endl;
}