#include "pch.h"



using namespace std;

void br_cifara_i_suma(int n)
{
	static int i = 0;
	static int suma = 0;

	suma = suma + n % 10;
	i++;

	if (n < 10)
	{
		cout << "Broj cifara unesenog broja: " << i << "\nSuma cifara unesenog broja: " << suma << endl;
		return;
	}

	br_cifara_i_suma(n / 10);
}

void Vjezbanje_8_zadatak()
{
	cout << "Odrediti sumu i broj cifara nekog prirodnog broja N, koji se ucitava sa tastature.Koristiti rekurziju." << endl << endl;

	int n;
	cout << "Unesite broj: ";
	cin >> n;

	br_cifara_i_suma(n);
}