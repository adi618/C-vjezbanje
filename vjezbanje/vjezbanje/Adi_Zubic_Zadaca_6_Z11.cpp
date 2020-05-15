#include "pch.h"



//Data je datoteka ispiti.txt ciji redovi imaju sljedecu strukturu :
//brindexa predmet ocjena
//
//Kreirajte ovu datoteku koristeci Notepad i napunite je nekim testnim podacima.predmeti su zadani
//imenom predmeta.
//Zatim napravite program koji na ulazu trazi broj predmeta, te ispisuje prosjecnu ocjenu i prolaznost
//(procenat studenata koji su polozili tj.dobili ocjenu 6 ili vise).Takoder treba program ispisat ukupan broj
//predmeta koje je student odslusao, broj polozenih, te prosjecnu ocjenu.


struct info
{
	int brIndexa;
	std::string predmet;
	int ocjena;
};


void Adi_Zubic_Zadaca_6_Z11()		// nije mi jasan ovaj zadatak posto kaze da nam je data datoteka "ispiti.txt" i onda ispod kaze da kreiramo tu datoteku?
{										// ja cu napraviti da ucita "ispiti.txt" i iz nje ispisuje trazene informacije
	std::ifstream file("ispiti.txt");

	if (file.is_open())
	{
		std::vector <info> informacije;
		info temp;

		while (file >> temp.brIndexa)
		{
			file >> temp.predmet;
			file >> temp.ocjena;
			informacije.push_back(temp);
		}
		file.close();

		std::cout << "\n\n\tUcitani predmeti:\n";
		for (const info& iter : informacije)
		{
			std::cout << "\n\n\tBroj indeksa: " << iter.brIndexa;
			std::cout << "\n\tPredmet: " << iter.brIndexa;
			std::cout << "\n\tOcjena: " << iter.ocjena;
		}

		std::string strTemp;
		std::cout << "\n\n\tUnesite predmet cije informacije zelite pogledati: ";
		std::cin >> strTemp;

		float zbirOcjena = 0;
		int ukupnoOcjena = 0;
		int brPolozili = 0;
		for (const info& iter : informacije)
		{
			if (iter.predmet == strTemp)
			{
				zbirOcjena += iter.ocjena;
				ukupnoOcjena++;
				if (iter.ocjena > 5)
					brPolozili++;
			}
		}
		std::cout << "\n\tPredmet je ukupno polozilo: " << brPolozili << " studenata.";
		std::cout << "\n\tProsjecna ocjena na predmetu: " << ((zbirOcjena == 0)? 0 : zbirOcjena / ukupnoOcjena);
	}
	else
		std::cout << "\n\n\tDatoteka \"ispiti.txt\" nije pronadjena!";
	std::cout << "\n\n\n";
}