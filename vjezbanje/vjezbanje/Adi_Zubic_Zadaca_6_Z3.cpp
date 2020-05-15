#include "pch.h"


//Napisati program u kome se citaju podaci o radnicima iz postojece datoteke radnici.txt i kreira niz
//struktura tipa radnik(ime, prezime, broj godina radnog staza, stepen strucne spreme i plata), a zatim
//stampa :
//-ukupan broj radnika u datoteci,
//-prosjecna plata radnika,
//-broj radnika koji imaju vise od 5 godina radnog staza,
//-imena radnika sa najvisim stepenom strucne spreme,
//-spisak radnika sortiranih po imenima.


struct radnik
{
	std::string ime;
	std::string prezime;
	int godStaza;
	int stepenSpreme;
	int plata;
};


void bubbleSortRadnika(std::vector <radnik>& radnici)
{
	for (int i = 0; i < radnici.size(); i++)
	{
		for (int j = 0; j < radnici.size() - 1; j++)
		{
			if (radnici[j].plata > radnici[j + 1].plata)
				std::swap(radnici[j], radnici[j + 1]);
		}
	}
}

void Adi_Zubic_Zadaca_6_Z3()
{
	std::ifstream file("radnici.txt");	// otvaramo file

	if (file.is_open())		// provjera da li je file otvoren
	{
		radnik temp;
		std::vector <radnik> radnici;
		int zbirPlata = 0;
		int najveciStepenSpreme = 0;
		int godStazaPreko5 = 0;

		while (file >> temp.ime)		// petlja koja ucitava datoteku u temp vrijednost koju kasnije stavljamo u vektor
		{
			file >> temp.prezime;
			file >> temp.godStaza;
			file >> temp.stepenSpreme;
			file >> temp.plata;
			zbirPlata += temp.plata;
			if (temp.godStaza > 5)
				godStazaPreko5++;
			if (najveciStepenSpreme < temp.stepenSpreme)
				najveciStepenSpreme = temp.stepenSpreme;
			radnici.push_back(temp);
		}
		file.close();		// zatvaramo file

		if (radnici.size() == 0)
		{							
			std::cout << "\n\n\tDatoteka je otvorena ali niti jedan radnik nije ucitan!\n\n\n";
			return;
		}

		bubbleSortRadnika(radnici);		// sortiramo apartmane

		std::cout << "\n\n\tDatoteka je pronadjena!";
		std::cout << "\n\n\tUkupan broj radnika: " << radnici.size();	// ispisujemo velicinu, kao i ostale podatke
		std::cout << "\n\n\tProsjecna plata radnika: " << ((zbirPlata == 0) ? 0 : zbirPlata / radnici.size());
		// ternary operator iznad koristim da izbjegnem bug dijeljenja sa nulom.
		std::cout << "\n\n\tBroj radnika sa preko 5 godina staza: " << godStazaPreko5;
		std::cout << "\n\n\tImena radnika sa najvisim stepenom strucne spreme: ";
		bool radnikPronadjen = false;
		for (const radnik& iteratorRadnika : radnici)
			if (iteratorRadnika.stepenSpreme == najveciStepenSpreme)
				std::cout << iteratorRadnika.ime;

		std::cout << "\n\n\tRadnici sortirani po plati:";
		for (const radnik& iteratorRadnika : radnici)
		{
			std::cout << "\n\n\t\t\tIme: " << iteratorRadnika.ime;
			std::cout << "\n\t\t\tPrezime: " << iteratorRadnika.prezime;
			std::cout << "\n\t\t\tBroj godina staza: " << iteratorRadnika.godStaza;
			std::cout << "\n\t\t\tStepen spreme: " << iteratorRadnika.stepenSpreme;
			std::cout << "\n\t\t\tPlata: " << iteratorRadnika.plata;
		}
	}
	else
		std::cout << "\n\n\tDatoteka \"radnici.txt\" nije pronadjena!";
	std::cout << "\n\n\n\n";
}