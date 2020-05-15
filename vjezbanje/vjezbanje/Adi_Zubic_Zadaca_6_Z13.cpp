#include "pch.h"


//Zadatak zahtijeva pisanje programa koji ce desifrovati poruke koje su sifrirane kako je opisano u
//narednom primjeru.Dat je sifrirani tekst : saoreecessinntfi.Potrebno je primjetiti da se sastoji od sesnaest
//slova.Tekst je moguce postaviti u matricu velicine 4×4 cime se dobije :
//
//s a o r
//e e c e
//s s i n
//n t f i
//
//Tekst ce se desifrovati ukoliko se znakovi poredaju na osnovu kolona odozgo prema dolje, tj.prvo znakovi iz
//prve kolone, potom znakovi iz druge kolone itd.Na osnovu navedenog, trazena rijec u primjeru je :
//sesnaestocifreni.Program otvara fajl pod nazivom ”test.txt”.U fajlu se nalaze sifrirani tekstovi jedan ispod
//drugog.Program treba ispisati desifrovane tekstove svaki u zasebnoj liniji.Ukoliko broj znakova ulaznog teksta
//nije kvadrat nekog broja program ispisuje rijec GRESKA.
//test.txt Output :
//1. saoreecessinntfi sesnaestocifreni
//2. pmrrj ie2 primjer 2
//3. dobar tekst GRESKA
//4. borj broj
//5. Bjsr aoOm Broj Osam

void Adi_Zubic_Zadaca_6_Z13()
{
	std::ifstream file("test.txt");

	if (file.is_open())
	{
		std::string recenica;
		while (getline(file, recenica))
		{
			std::cout << "\n\t";
			if (sqrt(recenica.size()) != floor(sqrt(recenica.size())))		// provjera kvadrata
			{
				std::cout << "GRESKA";
				continue;
			}

			int size = sqrt(recenica.size());
			int counter = 0;
			std::vector <std::vector <char>> matrica;		// vektor vektora charova, tj matrica slova
			for (int i = 0; i < size; i++)
			{
				std::vector <char> temp;				// slova spasavamo u vektor charova temp
				for (int j = 0; j < size; j++)
				{
					temp.push_back(recenica[counter]);
					counter++;
				}
				matrica.push_back(temp);				// taj temp stavljamo u matricu
			}	// ovo se sve moglo dinamicki alocirati, ali sam ja uradio ovako samo da pokazem da se moze i ovako uraditi, buduci
				// da sam u ranijim zadacima koristio dinamicku alokaciju
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					std::cout << matrica[j][i];		// ispisujemo slova zamijenjena po dijagonali
				}
			}
		}

		file.close();
	}
	else
		std::cout << "\n\n\tDatoteka \"test.txt\" nije pronadjena";
	std::cout << "\n\n\n";
}