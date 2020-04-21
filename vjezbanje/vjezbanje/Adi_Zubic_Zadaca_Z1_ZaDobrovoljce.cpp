#include "pch.h"
#include <fstream>

//Program kojim se vrsi sifriranje podataka postojece datoteke tekst.txt(sadrzi samo velika slova), tako sto
//se svako slovo zamjenjuje narednim ASCII znakom(slovo Z zamjeniti sa A).

void Adi_Zubic_Zadaca_Z1_ZaDobrovoljce()
{
	std::string recenica;
	std::string recenica2 = "";
	std::ifstream file("tekst.txt");
	file.open("tekst.txt");

	getline(file, recenica);
	for (auto slovo : recenica)
	{
		if (slovo >= 'A' && slovo <= 'Z')
		{
			if (slovo == 'Z')
				slovo = 'A';
			else
				slovo++;
		}
	}
	recenica2 = recenica2 + recenica;

	file.close();
	std::fstream tempfile("tempfile.txt");
	tempfile.open("tempfile.txt");
	remove("tekst.txt");
	rename("tempfile.txt", "tekst.txt");
	tempfile.close();

}
