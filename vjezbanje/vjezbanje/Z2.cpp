#include "pch.h"



using namespace std;

char* adresa(char* ime, char* prezime)
{
	int cifreImena = 0;
	int cifrePrezimena = 0;
	char temp[40];

	char* ptr = temp;

	while (*(ime + cifreImena) != 0)
	{
		cifreImena++;
	}

	while (*(prezime + cifrePrezimena) != 0)
	{
		*(ptr + cifrePrezimena) = *(prezime + cifrePrezimena);
		cifrePrezimena++;
	}

	*(ptr + cifrePrezimena) = '.';

	int counter = 0;

	for (int i = cifrePrezimena + 1; i < cifrePrezimena + cifreImena + 1; i++)
	{
		*(ptr + i) = *(ime + counter);
		counter++;
	}

	char email[] = "@gmail.com";

	char* emailptr = email;

	counter = 0;
	int counter1 = cifrePrezimena + cifreImena + 1;

	while (*(emailptr + counter) != 0)
	{
		*(ptr + counter1) = *(emailptr + counter);
		counter1++;
		counter++;
	}

	for (int i = 0; i < counter1; i++)
	{
		*(prezime + i) = *(ptr + i);
	}

	return prezime;
}

void Z2()
{
	char ime[40];
	char prezime[40];


	cin >> ime;
	cin >> prezime;


	char* ptr = adresa(ime, prezime);

	
	int i = 0;

	while (*(ptr + i) > 0 && *(ptr + i) < 127)
	{
		cout << *(ptr + i++);
	}
}