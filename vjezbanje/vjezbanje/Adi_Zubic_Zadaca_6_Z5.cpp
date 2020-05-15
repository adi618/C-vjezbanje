#include "pch.h"


//Napisati program u kome se citaju podaci o klijentima iz postojece datoteke klijenti.txt i kreira niz
//struktura tipa klijent(ime, prezime, mjesto, telefonski broj i posljednji racun), a zatim stampa :
//-ukupan broj klijenata,
//prosjecan racun za posljednji mjesec,
//broj klijenata iz Zenice,
//ime i broj klijenata sa najvecim racunom,
//spisak klijenata sortiranih po prezimenu.



struct klijent
{
	std::string ime;
	std::string prezime;
	std::string mjesto;
	std::string telBr;
	float posljednjiRacun;
};


void bubbleSortKlijenta(std::vector <klijent>& klijenti)
{
	for (int i = 0; i < klijenti.size(); i++)
	{
		for (int j = 0; j < klijenti.size() - 1; j++)
		{
			if (klijenti[j].prezime > klijenti[j + 1].prezime)
				std::swap(klijenti[j], klijenti[j + 1]);
		}
	}
}


void Adi_Zubic_Zadaca_6_Z5()
{
	std::ifstream file("klijenti.txt");	// otvaramo file

	if (file.is_open())		// provjera da li je file otvoren
	{
		klijent temp;
		std::vector <klijent> klijenti;
		float ukupniRacun = 0;
		int brKlijenataIzZenice = 0;
		int i = 0;			// brojac koji cu koristiti da pratim index unesenog klijenta
		int max = 0;		// max u koji cu sacuvat index klijenta sa najvecim posljednjim racunom
		while (file >> temp.ime)		// petlja koja ucitava datoteku u temp vrijednost koju kasnije stavljamo u vektor
		{
			file >> temp.prezime;
			file >> temp.mjesto;
			file >> temp.telBr;
			file >> temp.posljednjiRacun;

			ukupniRacun += temp.posljednjiRacun;
			if (temp.mjesto == "Zenica")
				brKlijenataIzZenice++;

			klijenti.push_back(temp);
			
			if (temp.posljednjiRacun > klijenti[max].posljednjiRacun)
				max = i;
			i++;
		}
		file.close();		// zatvaramo file

		std::cout << "\n\n\tDatoteka je pronadjena";
		if (klijenti.size() == 0)
		{
			std::cout << ", ali niti jedan ucenik nije ucitan!\n\n\n";
			return;
		}
		bubbleSortKlijenta(klijenti);

		std::cout << "\n\n\tUkupan broj klijenta: " << klijenti.size();
		std::cout << "\n\n\tProsjecan racun klijenata: " << ((ukupniRacun == 0) ? 0 : ukupniRacun / klijenti.size());
		std::cout << "\n\n\tIme i broj klijenta sa najvecim racunom:";
		std::cout << "\n\t\tIme: " << klijenti[max].ime;
		std::cout << "\n\t\tBroj: " << klijenti[max].telBr;

		std::cout << "\n\n\tKlijenti sortirani po razredima:";
		for (const klijent& iter : klijenti)
		{
			std::cout << "\n\n\t\tIme: " << iter.ime;
			std::cout << "\n\t\tPrezime: " << iter.prezime;
			std::cout << "\n\t\tMjesto: " << iter.mjesto;
			std::cout << "\n\t\tBroj: " << iter.telBr;
			std::cout << "\n\t\tPosljednji racun: " << iter.posljednjiRacun;
		}
	}
	else
		std::cout << "\n\n\tDatoteka \"klijenti.txt\" nije pronadjena!";
	std::cout << "\n\n\n\n";
}