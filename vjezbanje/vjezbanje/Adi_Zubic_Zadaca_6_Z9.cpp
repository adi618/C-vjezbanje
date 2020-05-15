#include "pch.h"


//Neopravdani izostanci ucenika cuvaju se u datoteci Izostanci.txt.Procitati ih i napraviti niz.Pomocu
//funkcija izracunati : ukupan broj izostanaka u odjeljenju, prosjecan broj izostanaka, koliki je najveci broj i
//koliko ima ucenika bez neopravdanih izostanaka.

int ukupanBrIzostanaka(const std::vector <int>& izostanci)
{
	int ukupno = 0;

	for (int br : izostanci)
	{
		ukupno += br;
	}
	return ukupno;
}

int prosjecanBrIzostanaka(const std::vector <int>& izostanci)
{
	int ukupno = 0;

	for (int br : izostanci)
	{
		ukupno += br;
	}
	return ukupno / izostanci.size();
}

int najveci(const std::vector <int>& izostanci)
{
	int max = 0;

	for (int br : izostanci)
	{
		if (max < br)
			max = br;
	}
	return max;
}

int brUcenikaBezIzostanka(const std::vector <int>& izostanci)
{
	int brNula = 0;

	for (int br : izostanci)
	{
		if (br == 0)
			brNula++;
	}
	return brNula;
}

void Adi_Zubic_Zadaca_6_Z9()
{
	std::ifstream file("Izostanci.txt");		// pretpostavljam da se u fajlu nalaze samo brojevi koji oznacavaju izostanke

	if (file.is_open())
	{
		int temp;
		std::vector <int> izostanci;
		while (file >> temp)
			izostanci.push_back(temp);

		std::cout << "\n\n\tDatoteka je ucitana!";
		std::cout << "\n\n\tUkupan broj izostanaka: " << ukupanBrIzostanaka(izostanci);
		std::cout << "\n\n\tProsjecni broj izostanaka: " << prosjecanBrIzostanaka(izostanci);
		std::cout << "\n\n\tNajveci broj izostanaka jednog studenta: " << najveci(izostanci);
		std::cout << "\n\n\tBroj studenata bez izostanaka: " << brUcenikaBezIzostanka(izostanci);
	}
	else
		std::cout << "\n\n\t\"Izostanci.txt\" fajl nije pronadjen!";
	std::cout << "\n\n\n\n";
}