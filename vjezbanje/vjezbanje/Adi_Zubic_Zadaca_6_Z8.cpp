#include "pch.h"


//U datoteci ulaz.txt nalazi se broj elemenata niza.Procitati taj broj, alocirati niz te ducine i unjeti
//vrijednosti elemenata tog niza.Izracunati prosjecnu vrijednost, prosiriti niz za jedno mjesto i ubaciti
//prosjek u niz.U novu datoteku Izlaz.txt upisati sortiran dati niz.


void Adi_Zubic_Zadaca_6_Z8()
{
	std::ifstream file("ulaz.txt");

	if (file.is_open())
	{
		int velicina;

		file >> velicina;		// pretpostavljam da se u fajlu nalazi samo jedan broj i onda korisnik kroz konzolu unosi brojeve dalje
		if (velicina < 1)
		{
			std::cout << "\n\tInvalidna velicina (manja od 1)";
			return;
		}
		std::cout << "\n\tNapravljen niz velicine " << velicina;

		float ukupno = 0;
		float* niz = new float[velicina];

		for (int i = 0; i < velicina; i++)
		{
			std::cout << "\n\tUnesite " << i + 1 << ". broj: ";
			std::cin >> niz[i];
			ukupno += niz[i];
		}
		velicina++;
		float* noviNiz = new float[velicina];

		for (int i = 0; i < velicina - 1; i++)
		{
			noviNiz[i] = niz[i];
		}
		delete[] niz;

		noviNiz[velicina - 1] = ukupno / velicina;

		std::ofstream file("Izlaz.txt");

		for (int i = 0; i < velicina; i++)
		{
			file << noviNiz[i] << " ";
		}
		file.close();
	}
	else
		std::cout << "\n\n\t\"ulaz.txt\" fajl nije pronadjen!";
	std::cout << "\n\n\n\n";
}