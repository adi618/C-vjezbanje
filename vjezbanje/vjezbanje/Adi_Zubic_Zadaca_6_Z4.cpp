#include "pch.h"


//Napisati program u kome se citaju podaci o ucenicima iz postojece datoteke ucenici.txt i kreira niz
//struktura tipa ucenik(ime, prezime, razred(1 - 4), uspjeh, prosjecna ocjena), a zatim stampa :
//-ukupan broj ucenika u datoteci,
//-broj ucenika 4. razreda,
//-imena ucenika koji imaju odlican uspjeh,
//-ime ucenika koji ima najbolju prosjecnu ocjenu,
//-imena ucenika sortiranih po razredima.


struct ucenik
{
	std::string ime;
	std::string prezime;
	int razred;
	int uspjeh;
	float prosjecnaOcjena;
};


void bubbleSortUcenika(std::vector <ucenik>& ucenici)
{
	for (int i = 0; i < ucenici.size(); i++)
	{
		for (int j = 0; j < ucenici.size() - 1; j++)
		{
			if (ucenici[j].razred > ucenici[j + 1].razred)
				std::swap(ucenici[j], ucenici[j + 1]);
		}
	}
}


void Adi_Zubic_Zadaca_6_Z4()
{
	std::ifstream file("ucenici.txt");	// otvaramo file

	if (file.is_open())		// provjera da li je file otvoren
	{
		std::cout << "\n\n\tDatoteka je pronadjena!";
		ucenik temp;
		std::vector <ucenik> ucenici;
		int brUcenika4Razreda = 0;
		float maxProsjecnaOcjena = 0;

		while (file >> temp.ime)		// petlja koja ucitava datoteku u temp vrijednost koju kasnije stavljamo u vektor
		{
			file >> temp.prezime;
			file >> temp.razred;
			file >> temp.uspjeh;
			file >> temp.prosjecnaOcjena;
			if (temp.razred > 4)			// prepravka za inkorektan unos razreda
			{
				std::cout << "\n\t\tInkorektan unos razreda, prepravlljen na 4\n";
				temp.razred = 4;
			}
			else if (temp.razred < 1)
			{
				std::cout << "\n\t\tInkorektan unos razreda, prepravlljen na 1\n";
				temp.razred = 1;
			}
			if (temp.uspjeh > 5)
			{
				std::cout << "\n\t\tInkorektan unos uspjeha, prepravlljen na 5\n";
				temp.uspjeh = 5;
			}
			else if (temp.razred < 1)
			{
				std::cout << "\n\t\tInkorektan unos uspjeha, prepravlljen na 1\n";
				temp.uspjeh = 1;
			}
			if (temp.razred == 4)
				brUcenika4Razreda++;
			if (maxProsjecnaOcjena < temp.prosjecnaOcjena)
				maxProsjecnaOcjena = temp.prosjecnaOcjena;
			ucenici.push_back(temp);
		}
		file.close();		// zatvaramo file

		if (ucenici.size() == 0)
		{
			std::cout << "\n\n\tDatoteka je otvorena ali niti jedan ucenik nije ucitan!\n\n\n";
			return;
		}
		bubbleSortUcenika(ucenici);

		std::cout << "\n\n\tUkupan broj ucenika: " << ucenici.size();
		std::cout << "\n\n\tBroj ucenika 4 razreda: " << brUcenika4Razreda;
		std::cout << "\n\n\tImena ucenika koji imaju odlican uspjeh:  ";
		for (const ucenik& iteratorUcenika : ucenici)
		{
			if (iteratorUcenika.uspjeh == 5)
				std::cout << iteratorUcenika.ime << ", ";
		}
		std::cout << "\n\n\tIme ucenika koji ima najbolju prosjecnu ocjenu: ";
		for (const ucenik& iteratorUcenika : ucenici)
		{
			if (iteratorUcenika.uspjeh == 5)
			{
				std::cout << iteratorUcenika.ime;
				break;
			}
		}

		std::cout << "\n\n\tImena ucenika sortiranih po razredima:";
		for (const ucenik& iteratorRadnika : ucenici)
		{
			std::cout << "\n\t\t" << iteratorRadnika.ime;
		}
	}
	else
		std::cout << "\n\n\tDatoteka \"ucenici.txt\" nije pronadjena!";
	std::cout << "\n\n\n\n";
}