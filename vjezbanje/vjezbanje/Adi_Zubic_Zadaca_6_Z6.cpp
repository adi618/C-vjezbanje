#include "pch.h"

//Kreiranje tekstualne datoteke „Podaci.txt“ u radnom direktorijumu i upis jednog reda koji sadrzi : ime,
//pol, godiste i prosjek.Omoguciti dodavanje novih podataka u datoteku.Odrediti broj zenskih osoba i
//osoba sa prosjekom vecim od 4.50 u datoteci Podaci.txt.


struct podatak
{
	std::string ime;
	std::string spol;
	std::string godiste; // std::string u slucaju da korisnik unese tacku
	float prosjek;
};

void ispis(std::vector <podatak>& podaci)
{
	while (true)
	{
		std::cout << "\n\n\t1 - Dodati podatke nove osobe";
		std::cout << "\n\t2 - Ispis broja zenskih osoba";
		std::cout << "\n\t3 - Ispis osoba sa prosjekom vecim od 4.50";
		std::cout << "\n\t0 - Izlaz";
		std::cout << "\n\t\tOdabir: ";

		int odabir;
		std::cin >> odabir;
		std::cin.ignore();

		if (odabir == 1)
		{
			podatak temp;
			std::cout << "\n\n\tUnesite ime: ";
			getline(std::cin, temp.ime);
			std::cout << "\n\tUnesite spol: ";
			getline(std::cin, temp.spol);
			std::cout << "\n\tUnesite godiste: ";
			getline(std::cin, temp.godiste);
			std::cout << "\n\tUnesite prosjek: ";
			std::cin >> temp.prosjek;
			podaci.push_back(temp);
		}
		if (odabir == 2)
		{
			bool baremJednoZensko = false;
			for (const podatak& iter : podaci)
			{
				if (iter.spol == "zensko")
				{
					std::cout << "\n\n\tIme: " << iter.ime;
					std::cout << "\n\tSpol: " << iter.spol;
					std::cout << "\n\tGodiste: " << iter.godiste;
					std::cout << "\n\tProsjek: " << iter.prosjek;
					baremJednoZensko = true;
				}
			}
			if (!baremJednoZensko)
				std::cout << "\n\tNiti jedna zenska osoba nije pronadjena!";
		}
		if (odabir == 3)
		{
			bool baremJedanOdlican = false;
			for (const podatak& iter : podaci)
			{
				if (iter.prosjek > 4.50)
				{
					std::cout << "\n\n\tIme: " << iter.ime;
					std::cout << "\n\tSpol: " << iter.spol;
					std::cout << "\n\tGodiste: " << iter.godiste;
					std::cout << "\n\tProsjek: " << iter.prosjek;
					baremJedanOdlican = true;
				}
			}
			if (!baremJedanOdlican)
				std::cout << "\n\tNiti jedna osoba sa prosjekom vecim od 4.50 nije pronadjena!";
		}
		if (odabir == 0)
		{
			if (podaci.size() != 0)		// if da izbjegne bug ako korisnik nije unio nista
			{
				std::ofstream file("Podaci.txt");

				for (int i = 0; i < podaci.size() - 1; i++)		// ako je unesen jedan podatak, ova petlja se nece aktivirati te nece doci do buga
				{
					file << podaci[i].ime;
					file << " ";
					file << podaci[i].spol;
					file << " ";
					file << podaci[i].godiste;
					file << " ";
					file << podaci[i].prosjek;
					file << "\n";
				}
				file << podaci[podaci.size() - 1].ime;
				file << " ";
				file << podaci[podaci.size() - 1].spol;			// razlog petlje + ovog ovdje dijela jeste da '\n' nemam na samom kraju notepada
				file << " ";
				file << podaci[podaci.size() - 1].godiste;
				file << " ";
				file << podaci[podaci.size() - 1].prosjek;
			}

			break;
		}
		std::cout << "\n\t";
		system("pause");
		system("cls");
	}
}

void Adi_Zubic_Zadaca_6_Z6()
{
	std::ifstream file("Podaci.txt");
	std::vector <podatak> podaci;

	if (file.is_open())
	{
		podatak temp;
		while (file >> temp.ime)
		{
			file >> temp.spol;
			file >> temp.godiste;
			file >> temp.prosjek;

			podaci.push_back(temp);
		}
		file.close();

		std::cout << "\n\n\tDatoteka je otvorena" << ((podaci.size() != 0) ? " i ucitani su sljedeci podaci:" : ", ali nikakvi podaci nisu pronadjeni!");
		for (const podatak& iter : podaci)
		{
			std::cout << "\n\n\tIme: " << iter.ime;
			std::cout << "\n\tSpol: " << iter.spol;
			std::cout << "\n\tGodiste: " << iter.godiste;
			std::cout << "\n\tProsjek: " << iter.prosjek;
		}
		ispis(podaci);
	}
	else
	{
		std::ofstream file("Podaci.txt");

		std::cout << "\n\n\tDatoteka \"Podaci.txt\" nije pronadjena, pa smo Vam je kreirali!";

		ispis(podaci);
	}
	std::cout << "\n\n\n\n";
}