#include "pch.h"


//Napisati program u kome se citaju podaci o apartmana jedne turisticke agencije iz postojece datoteke
//apartmani.txt i kreira niz struktura tipa apartman(naziv, mjesto, broj kreveta, cjena), a zatim stampa :
//-ukupan broj apartmana u datoteci,
//-prosjecna cjena apartmana u toj agenciji,
//-broj apartmana u mjestu Paralia,
//-naziv apartmana za 2 osobe sa najmanjom cjenom,
//-spisak apartmana sortiranih po cjeni.


struct apartman
{
	std::string naziv;
	std::string mjesto;
	int brojKreveta;
	int cijena;
};


void bubbleSortApartmana(std::vector <apartman>& apartmani)	// Bubble Sort: O(n^2) time complexity, O(1) space complexity
{
	for (int i = 0; i < apartmani.size(); i++)
	{
		for (int j = 0; j < apartmani.size() - 1; j++)
		{
			if (apartmani[j].cijena > apartmani[j + 1].cijena)
				std::swap(apartmani[j], apartmani[j + 1]);
		}
	}
}


void Adi_Zubic_Zadaca_6_Z2()
{
	std::ifstream file("apartmani.txt");	// otvaramo file

	if (file.is_open())		// provjera da li je file otvoren
	{
		apartman temp;
		std::vector <apartman> apartmani;
		int zbirCijena = 0;
		int brojParalia = 0;

		while (file >> temp.naziv)		// petlja koja ucitava datoteku u temp vrijednost koju kasnije stavljamo u vektor
		{
			file >> temp.mjesto;
			file >> temp.brojKreveta;
			file >> temp.cijena;
			zbirCijena += temp.cijena;
			if (temp.mjesto == "Paralia")
				brojParalia++;
			apartmani.push_back(temp);
		}
		file.close();		// zatvaramo file

		bubbleSortApartmana(apartmani);		// sortiramo apartmane

		std::cout << "\n\n\tDatoteka je pronadjena!";
		std::cout << "\n\n\tUkupan broj apartmana: " << apartmani.size();	// ispisujemo velicinu, kao i ostale podatke
		std::cout << "\n\n\tProsjecna cijena apartmana: " << ((zbirCijena == 0)? 0 : zbirCijena / apartmani.size());
					// ternary operator iznad koristim da izbjegnem bug dijeljenja sa nulom.
		std::cout << "\n\n\tBroj apartmana u mjestu \"Paralia\": " << brojParalia;
		std::cout << "\n\n\tNaziv apartmana za 2 osobe sa najmanjom cijenom: ";
		for (const apartman& apart : apartmani)		// posto su apartmani vec sortirani, prvi 2 krevetni apartman koji nadjemo
		{											// ce biti najjeftiniji
			if (apart.brojKreveta == 2)
			{									// Ukoliko imamo vise apartmana najmanje cijene, ovo ce ispisati samo jednu, sto bi mogla
				std::cout << apart.naziv;		// biti greska.
				goto dalje;			// preporuceno je da se goto nikada ne koristi zato sto zakoplikuje problem ali mislim da je ovdje
			}						// uredu, koristim ga kao zamjenu za break i nacin da ispisem cout ispod ukoliko brojKreveta == 2 ne postoji
		}
		std::cout << "Nema apartman za 2 osobe";
	dalje:

		std::cout << "\n\n\tApartmani sortirani po cijeni:";
		for (const apartman& apart : apartmani)	// petlja koja iterira vektor apartmani. Da ne bi bespotrebno pravili kopije svakog
		{										// apartmana proslijedio sam iterator po referenci, a da ga slucajno ne bih promijenio kada
			std::cout << "\n\n\t\t\tNaziv apartmana: " << apart.naziv;			// ne trebam, stavio sam da je const (ovo je jedino vazno
			std::cout << "\n\t\t\tNaziv lokacije: " << apart.mjesto;		// kod velikih projekata, za ove male zadatke nije).
			std::cout << "\n\t\t\tBroj kreveta: " << apart.brojKreveta;
			std::cout << "\n\t\t\tCijena apartmana: " << apart.cijena;
		}
	}
	else
		std::cout << "\n\n\tDatoteka \"apartmani.txt\" nije pronadjena!";
	std::cout << "\n\n\n\n";
}