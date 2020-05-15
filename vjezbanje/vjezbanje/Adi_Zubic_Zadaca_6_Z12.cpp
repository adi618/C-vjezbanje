#include "pch.h"


//Data je tekstualna datoteka pismo.txt.Napisati funkcije za :
//a) ispis datoteke na standardni izlaz zadrzavajuci strukturu po redovima;
//b) prepis datoteke u novu mijenjajuci mala i velika slova;
//c) ispisati datoteku u obrnutom redosljedu na izlaz(prva postaje zadnja, druga postaje pretposljednja rijec...)
//d) ispitati da li je neka rijec palindrom(isto znacenje kada se cita i u obrnutom smjeru)


void ispis(const std::vector <std::vector <std::string>>& pismo)
{
	for (const std::vector <std::string>& red : pismo)
	{
		std::cout << "\n\t";
		for (const std::string& rijec : red)
		{
			std::cout << rijec << " ";
		}
	}
}

void prepis(const std::vector <std::vector <std::string>>& pismo)
{
	std::string ime;
	std::cout << "\n\n\tUnesite ime datoteke u koju zelite spasiti ovo pismo.\n\t\t*Velika slova biti ce pretvorena u mala i obrnuto\n\n\tIme: ";
	std::cin >> ime;

	std::ofstream file(ime);

	if (file.is_open())
	{
		for (const std::vector <std::string>& red : pismo)	// iako ovdje imamo 3 petlje, time complexity je opet O(n) gdje je n duzina pisma
		{													// buduci da ove petlje samo dijele pismo na redove, rijeci i slova
			for (const std::string& rijec : red)
			{
				for (const char& slovo : rijec)
				{
					if (slovo >= 'A' and slovo <= 'Z')
						file << char(slovo + 32);
					else if (slovo >= 'a' and slovo <= 'z')
						file << char(slovo - 32);
					else
						file << char(slovo);
				}
				file << " ";
			}
			file << "\n";
		}
		file.close();
	}
	else
		std::cout << "\n\t\t\"" << ime << "\" je invalidno ime za datoteku\n";
}

void obrnutiIspis(const std::vector <std::vector <std::string>>& pismo)
{
	std::cout << "\n\n\tPismo ispisano obrnutim redoslijedom rijeci:\n";

	for (int i = pismo.size() - 1; i >= 0; i--)			// obrnuti redoslijed i redova i rijeci
	{
		std::cout << "\n\t";
		for (int j = pismo[i].size() - 1; j >= 0; j--)
		{
			std::cout << pismo[i][j] << " ";
		}
	}
}

bool jePalindrom(std::string rijec)
{
	for (int i = 0; i < rijec.size() / 2; i++)	// provjera palindroma
	{
		if (rijec[i] != rijec[rijec.size() - i - 1])
			return false;
	}
	return true;
}

void ispisPalindroma(const std::vector <std::vector <std::string>>& pismo)
{
	std::cout << "\n\n\tIspis rijeci u pismu koje su palindromi: ";
	for (const std::vector <std::string>& red : pismo)
	{
		for (const std::string& rijec : red)
		{
			if (jePalindrom(rijec))
				std::cout << " " << rijec;
		}
	}
}

void Adi_Zubic_Zadaca_6_Z12()
{
	std::ifstream file("pismo.txt");

	if (file.is_open())
	{
		std::vector <std::vector <std::string>> pismo;
		std::string red;

		while (getline(file, red))
		{
			std::string strTemp = "";
			std::vector <std::string> vecTemp;
			red += " ";
			for (const char& slovo : red)	// uzimam red po red pomocu getline(file, red) i onda taj red iteriram po slovima da razdvojim rijeci gdje god ima razmak
			{
				if (slovo != ' ')
				{
					strTemp += slovo;
				}
				else
				{
					vecTemp.push_back(strTemp);
					strTemp = "";
				}
			}
			pismo.push_back(vecTemp);
		}
		file.close();

		ispis(pismo);
		prepis(pismo);
		obrnutiIspis(pismo);
		ispisPalindroma(pismo);
	}
	else
		std::cout << "\n\n\tPismo nije pronadjeno! (\"pismo.txt\")";
	std::cout << "\n\n\n\n";
}