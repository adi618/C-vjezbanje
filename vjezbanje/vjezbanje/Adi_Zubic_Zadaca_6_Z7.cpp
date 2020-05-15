#include "pch.h"


//U datotekama grupa1.txt, grupa2.txt i grupa3.txt prati se rad ucenika na vjezbama iz programiranja.U
//svakom redu datoteka je ime ucenika, prosjecna ocjena vjezbi i broj vjezbi koje je ucenik propustio.
//Procitati sve podatke i u datoteku izvjestaj.txt upisati sortirane ucenike, njihove zakljucne ocjene i
//komentar da li je ucenik zadovoljio minimum rada na vjezbama(manje od 5 propustenih vjezbi).


struct informacija
{
	std::string ime;
	float prosjecnaOcjena;
	int brPropusta;
};


void Adi_Zubic_Zadaca_6_Z7()
{
	std::ifstream grupa1("grupa1.txt");
	std::ifstream grupa2("grupa2.txt");
	std::ifstream grupa3("grupa3.txt");

	if (grupa1.is_open() and grupa2.is_open() and grupa3.is_open())
	{
		std::cout << "\n\n\tSva 3 .txt fajla su ucitana i izvjestaj je spasen u \"izvjestaj.txt\"!";
		std::vector <informacija> informacije;

		informacija temp;

		while (grupa1 >> temp.ime)
		{
			grupa1 >> temp.prosjecnaOcjena;
			grupa1 >> temp.brPropusta;
			informacije.push_back(temp);
		}

		while (grupa2 >> temp.ime)
		{
			grupa2 >> temp.prosjecnaOcjena;
			grupa2 >> temp.brPropusta;
			informacije.push_back(temp);
		}

		while (grupa3 >> temp.ime)
		{
			grupa3 >> temp.prosjecnaOcjena;
			grupa3 >> temp.brPropusta;
			informacije.push_back(temp);
		}

		for (int i = 0; i < informacije.size(); i++)
		{
			for (int j = 0; j < informacije.size() - 1; j++)
			{
				if (informacije[j].ime > informacije[j + 1].ime)
					std::swap(informacije[j], informacije[j + 1]);
			}
		}
		grupa1.close();
		grupa2.close();
		grupa3.close();

		std::ofstream file("izvjestaj.txt");

		for (const informacija& iter : informacije)
		{
			file << "\n\n\tIme: ";
			file << iter.ime;
			file << "\n\tProsjecna ocjena: ";
			file << iter.prosjecnaOcjena;
			file << "\n\tBroj propusta: ";
			file << iter.brPropusta;

			if (iter.prosjecnaOcjena >= 9.5 and iter.prosjecnaOcjena <= 10)
				file << "\n\tZakljucna ocjena: 10";
			else if (iter.prosjecnaOcjena >= 8.5)
				file << "\n\tZakljucna ocjena: 9";
			else if (iter.prosjecnaOcjena >= 7.5)
				file << "\n\tZakljucna ocjena: 8";
			else if (iter.prosjecnaOcjena >= 6.5)
				file << "\n\tZakljucna ocjena: 7";
			else if (iter.prosjecnaOcjena >= 5.5)
				file << "\n\tZakljucna ocjena: 6";
			else if (iter.prosjecnaOcjena >= 5)
				file << "\n\tZakljucna ocjena: 5";
			else
				file << "\n\tZakljucna ocjena nije mogla biti izracunara posto unos prosjecne ocjene nije validan (ocjene idu od 5 do 10)";

			if (iter.brPropusta > 5)
				file << "\n\tKomentar: Ucenik ima preko 5 propusta te nije zadovoljio rad na vjezbama";
		}
	}
	else
		std::cout << "\n\n\tJedan od 3 .txt fajla nedostaje!";
	std::cout << "\n\n\n\n";
}