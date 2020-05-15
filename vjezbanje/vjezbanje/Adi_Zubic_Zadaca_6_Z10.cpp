#include "pch.h"


//Napisati funkciju koja racuna prosjecnu vrednost niza cjelih brojeva i broj elemenata jednakih 5. Glavna
//funkcija koristi datoteku Ocjene.txt u kojoj se cuva broj ucenika u odeljenju(u prvom redu) i u svakom
//sljedecem : ime ucenika, prezime, strani jezik koji uci(engleski / njemacki) i ocjena.Stampati prosjecne
//ocjene iz engleskog i njemackog i broj petica iz oba jezika.


void Adi_Zubic_Zadaca_6_Z10()
{
	std::ifstream file("Ocjene.txt");

	if (file.is_open())
	{
		int brUcenika;
		std::string strTemp;
		int intTemp;
		float engleskiZbir = 0, njemackiZbir = 0;
		int engleskiUkupno = 0, njemackiUkupno = 0;
		int engleskiBrPetica = 0, njemackiBrPetica = 0;

		file >> brUcenika;

		for (int i = 0; i < brUcenika; i++)
		{
			file >> strTemp;		// ovdje bi islo ime, ali posto mi ta informacija opste nije potrebna, necu je zadrzavati
			file >> strTemp;		// isti vazi i za prezime
			file >> strTemp;		// predmet
			file >> intTemp;		// ocjena

			if (strTemp == "engleski")
			{
				engleskiZbir += intTemp;
				engleskiUkupno++;
				if (intTemp == 5)
					engleskiBrPetica++;
			}
			if (strTemp == "njemacki")		// moze se ovo zamijeniti sa 'else', ukoliko smo 100% sigurni da korisnik nece unijeti neki drugi predmet
			{								// osim engleskog ili njemackog
				njemackiZbir += intTemp;
				njemackiUkupno++;
				if (intTemp == 5)
					njemackiBrPetica++;
			}
		}
		std::cout << "\n\n\tProsjecna ocjena iz engleskog: " << ((engleskiUkupno == 0) ? 0 : engleskiZbir / engleskiUkupno);
		std::cout << "\n\tBroj petica iz engleskog: " << engleskiBrPetica;
		std::cout << "\n\n\tProsjecna ocjena iz njemackog: " << ((njemackiUkupno == 0) ? 0 : njemackiZbir / njemackiUkupno);
		std::cout << "\n\tBroj petica iz njemackog: " << njemackiBrPetica;
	}
	else
		std::cout << "\n\n\t\"Ocjene.txt\" fajl nije pronadjen!";
	std::cout << "\n\n\n\n";
}