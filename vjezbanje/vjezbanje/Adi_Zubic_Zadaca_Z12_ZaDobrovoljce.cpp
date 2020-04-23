#include "pch.h"


//U gradu Sarajevu tokom dvije godine vrsena su svakodnevna mjerenja temperatura i to u 9, 13, 16 i 20
//sati.Ta mjerenja zapisana su u datoteku mjerenja - sarajevo.txt i to u obliku :
//9.2 16.4 15.2 10.5
//12.7 21.1 20.5 15.6
//13.2 21.6 21.0 15.5
//11.9 20.5 19.8 14.9 itd.
//Ova mjerenja potrebno je ucitati u niz struktura oblika :
//
//struct mjerenja { float u9, u13, u16, u20; } sarajevo[731];
//
//Ovaj niz treba sortirati po mjerenju u 13 sati i zatim upisati u datoteku sortirano13 - sarajevo.txt.Takode na
//ekranu treba ispisati ukupan broj ucitanih mjerenja, broj dana u kojima temperatura u 9 sati nije bila najmanja te
//broj dana u kojima temperatura u 13 sati nije bila najveca.Primjer: Iz datoteke su ucitani podaci za 730 dana.Od
//toga, ima 25 dana u kojima temperatura u 9 nije najmanja, a 27 dana u kojima temperatura u 13 nije najveca.


struct mjerenja
{
	float u9, u13, u16, u20;
} sarajevo[721];



void Adi_Zubic_Zadaca_Z12_ZaDobrovoljce()
{
	std::ifstream file("mjerenja - sarajevo.txt");		// ucitavamo file iz kojeg cemo ucitati informacije

	if (file.is_open())		// provjeravamo jesmo li uspjesno otvorili file, ako nismo nema potrebe nastaviti
	{
		int brojac = 0;

		while (file >> sarajevo[brojac].u9)		// ponavljamo petlju dokle god se u9 moze upisati, kada se ne moze upsati
		{										// to znaci da je cijeli .txt upisan u nase strukture
			file >> sarajevo[brojac].u13;
			file >> sarajevo[brojac].u16;
			file >> sarajevo[brojac].u20;
			brojac++;
		}
		file.close();	// file nam nije vise potreban, mozemo ga zatvoriti

		for (int i = 0; i < brojac - 1; i++)
		{
			for (int j = i + 1; j < brojac; j++)
			{
				if (sarajevo[i].u13 > sarajevo[j].u13)
					std::swap(sarajevo[i], sarajevo[j]);	// obicni algoritam za sortiranje koji sortira sarajevo po u13
			}
		}

		std::ofstream newFile("sortirano13 - sarajevo.txt");	// pravimo novi file u koji mozemo samo upisivati
		
		int u9minIndeks = 0, u13maxIndeks = 0;
		for (int i = 0; i < brojac; i++)
		{
			newFile << sarajevo[i].u9;
			newFile << " ";
			newFile << sarajevo[i].u13;
			newFile << " ";
			newFile << sarajevo[i].u16;
			newFile << " ";
			newFile << sarajevo[i].u20;
			newFile << "\n";

			if (sarajevo[u9minIndeks].u9 > sarajevo[i].u9)		// if koji ce nam zapisati najmanju u9 valutu
				u9minIndeks = i;
		}
		u13maxIndeks = brojac - 1;		// mjerenja su vec sortirana po temperaturi u 13 sati, tako da ce najveca temeratura bit zadnja


		std::cout << "\n\n\tUkupan broj ucitanih mjerenja: " << brojac * 4; // Ukoliko je .txt file korektno ispunjen, imacemo "brojac" redova
																			// i 4 kolone, mnozenjem to dvoje dovijemo ukupni broj mjerenja

		int u9minBrojac = 0, u13maxBrojac = 0;
		for (int i = 0; i < brojac; i++)	// petlja da izbrojimo broj dana 
		{
			if (sarajevo[i].u9 != sarajevo[u9minIndeks].u9)
				u9minBrojac++;
		}
		for (int i = 0; i < brojac; i++)
		{
			if (sarajevo[i].u13 != sarajevo[u13maxIndeks].u13)
				u13maxBrojac++;
		}

		std::cout << "\n\n\tUkupan broj dana u kojima temperatura u 9 sati nije bila najmanja: " << u9minBrojac;
		std::cout << "\n\n\tUkupan broj dana u kojima temperatura u 13 sati nije bila najveca: " << u13maxBrojac;

		newFile.close();
	}
	else
		std::cout << "\n\n\tFile \"mjerenja - sarajevo.txt\" nije uspjesno pronadjen.";
	std::cout << "\n\n\n";
}