#include "pch.h"


//Napravite program koji generise niz slucajnih brojeva, a zatim ispisuje te brojeve poredane po sumi
//njihovih cifara, od manjeg ka vecem.Npr.neka su dati brojevi 121 i 35. Suma cifara broja 121 je 4, a
//broja 35 je 8, tako da broj 121 treba biti ispisan prije broja 35. U rjesenju zadatka obavezno koristiti
//funkcije koje kao parametar primaju niz ili nizove.


int sumaCifara(int n)
{
	if (n == 0)		// rekurzivnja funkcija koja sabere cifre brojeva
		return 0;
	return n % 10 + sumaCifara(n / 10);
}

void popuni(int* arr, int brBrojeva, int maxBroj)
{
	srand(time(NULL));
	for (int i = 0; i < brBrojeva; i++) // petlja koja generise random brojeve manje od maxBroj
		arr[i] = rand() % maxBroj + 1;
}

void sortiraj(int* arr, int brBrojeva)
{
	for (int i = 0; i < brBrojeva; i++)			// sorting algoritam koji sortira po rezuntatu funkcije sumaCifara
		for (int j = i + 1; j < brBrojeva; j++)
			if (sumaCifara(arr[i]) < sumaCifara(arr[j]))
				std::swap(arr[i], arr[j]);
}

void ispisi(int* arr, int brBrojeva)
{
	std::cout << "\n\n\tGenerisani brojevi sortirani po zbiru njihovih cifara:\n\n";
	for (int i = 0; i < brBrojeva; i++)
		std::cout << arr[i] << "  ";		// ispis
	std::cout << "\n\n\n";
}

void Adi_Zubic_Zadaca_Z13_ZaDobrovoljce()
{
	int maxBroj, brBrojeva;

	std::cout << "\n\n\tUnesite velicinu niza koji ce se generisati: ";
	std::cin >> brBrojeva;

	std::cout << "\n\n\tUnesite najveci broj koji ce moci biti generisan: ";
	std::cin >> maxBroj;

	int* arr = new int[brBrojeva];

	popuni(arr, brBrojeva, maxBroj);
	sortiraj(arr, brBrojeva);
	ispisi(arr, brBrojeva);
}