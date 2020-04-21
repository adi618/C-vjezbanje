#include "pch.h"

//Napisati funkcije :
//-brojpoz(), koja racuna broj pozitivnih clanova niza,
//-proizvod(), kоја racuna proizvod svih clanova niza,
//-zbirparnih(), koja racuna zbir svih parnih clanova,
//-brojnula(), koja racuna broj clanova jednakih nuli,
//-brojneg(), koja racuna broj negativnih clanova,
//-prosek(), koja racuna srednju vrijednost niza.
//U glavnoj funkciji se unosi prirodan broj n < 100, zatim niz od n cijelih brojeva i stampaju rezultati funkcije.

int brojpoz(int arr[], int n)
{
	int brojac = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] > 0)
			brojac++;
	return brojac;
}

int proizvod(int arr[], int n)
{
	int proizvod = 1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			std::cout << "\n\n\t\tJedan od unesenih brojeva je nula tako da je proizvod svih brojeva 0!";
		proizvod *= arr[i];
	}
	return proizvod;
}

int zbirparnih(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] % 2 == 0)
			sum += arr[i];
	return sum;
}

int brojnula(int arr[], int n)
{
	int brojac = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] == 0)
			brojac++;
	return brojac;
}

int brojneg(int arr[], int n)
{
	int brojac = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] < 0)
			brojac++;
	return brojac;
}

float prosek(int arr[], int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum / n;
}

void Adi_Zubic_Zadaca_Z2_ZaDobrovoljce()
{
	int n, num;
	int arr[100];
	std::cout << "\n\n\tUnesite koliko brojeva zelite unijeti (do 100): ";
	
	while (true)
	{
		std::cin >> n;
		if (n > 0 && n < 100)
			break;
		std::cout << "\n\t\tPokusajte ponovo (0 > n > 100): ";
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << "\n\tMolimo unesite " << i + 1 << ". broj: ";
		std::cin >> num;
		arr[i] = num;
	}

	std::cout << "\n\n\n\tBroj pozitivnih clanova niza: " << brojpoz(arr, n);
	std::cout << "\n\n\tProizvod clanova niza: " << proizvod(arr, n);
	std::cout << "\n\n\tZbir parnih clanova niza: " << zbirparnih(arr, n);
	std::cout << "\n\n\tBroj clanova niza jednakih nuli: " << brojnula(arr, n);
	std::cout << "\n\n\tBroj negativnih clanova niza: " << brojneg(arr, n);
	std::cout << "\n\n\tProsjek clanova niza: " << prosek(arr, n);
	std::cout << "\n\n";
}
