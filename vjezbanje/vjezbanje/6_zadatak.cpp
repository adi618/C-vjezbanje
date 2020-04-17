#include "pch.h"



int duzina(std::string& s)
{
	int counter = 0;
	
	for (unsigned i = 0; i < s.size(); i++)
	{
		counter++;
	}

	return counter;
}

int izbroji(std::string& s, char& c)
{
	int counter = 0;

	for (unsigned i = 0; i < s.size(); i++)
	{
		if (s[i] == c)
		{
			counter++;
		}
	}

	return counter;
}

int samogl(std::string& s)
{
	int counter = 0;

	for (unsigned i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case 'a': case 'o' : case 'u' : case 'e' : case 'i' :
			counter++;
			break;
		}
	}

	return counter;
}

void Zadatak_6()
{
	std::string s;
	char c;


	std::cout << "\n\n\tUnesite rijec:\n\t\t";
	getline(std::cin, s);

	
	std::cout << "\n\tUnesite znak:\n\t\t";
	std::cin >> c;


	std::cout << "\n\tDuzina rijeci:\n\t\t" << duzina(s);


	std::cout << "\n\n\tBroj ponavljanja znaka u rijeci:\n\t\t" << izbroji(s, c);


	std::cout << "\n\n\tBroj samoglasnika u rijeci:\n\t\t" << samogl(s);


	std::cout << "\n\n\n\n";
}