#include "pch.h"



using namespace std;

int armstrongov_broj(int n, bool reset)
{
	static int i = 0, suma = 0, num = n;

	if (reset)
	{
		i = 0; suma = 0; num = n;
	}

	if (n > 0)
	{
		i++;
		return armstrongov_broj(n / 10, false);
	}

	suma += pow(num % 10, i);
	num /= 10;
	
	if (num > 0)
		return armstrongov_broj(n, false);
	else
		return suma;
}

void Vjezbanje_9_zadatak()
{
	cout << "Ispitati da li je uneti prirodan broj N Armstongov broj.n - tocifreni broj je Armstrongov broj ako je" << endl;
	cout << "jednak sumi n - tih stepena svojih cifara.Npr. 370, 407, ... Ispisati sve Armstrongove brojeve manje od 1000000." << endl << endl;

	cout << "Armstrongovi brojevi manji od 1000000:" << endl;

	for (int i = 0; i < 1000000; i++)
		if (armstrongov_broj(i, true) == i)
			cout << i << endl;
}