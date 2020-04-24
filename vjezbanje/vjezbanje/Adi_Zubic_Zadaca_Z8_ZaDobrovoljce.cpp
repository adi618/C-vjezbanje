#include "pch.h"


//Program ucitava jednu rijec a i znak c koji se treba prebrojati u toj rijeci.Nakon toga program poziva
//funkcije duzina() i izbroji() i samogl(), te ispisuje duzinu unesene rijeci a i broj pojavljivanja znaka c u
//toj rijeci, kao i broj samoglasnika u rijeci.

int duzina(std::string a)
{
	return a.size();		// Ukoliko ne smijemo koristiti string, ovdje mozemo koristiti strlen funkciju ili mozemo napravili
}							// while petlju koja povecava brojac dok uneseno slovo nije u ascii tabeli nula, posto nula oznacava kraj char niza

int izbroji(std::string a, char c)
{
	int brojac = 0;
	for (char slovo : a)	// ukoliko je slovo jednako a brojac se povecava
		if (slovo == c)
			brojac++;
	return brojac;
}

int samogl(std::string a)
{
	int brojac = 0;
	for (char slovo : a)
		if (slovo == 'a' || slovo == 'e' || slovo == 'i' || slovo == 'u' || slovo == 'o' ||	// ukoliko je slovo samoglasnik brojac se povecava
			slovo == 'A' || slovo == 'E' || slovo == 'I' || slovo == 'U' || slovo == 'O')
			brojac++;
	return brojac;
}

void Adi_Zubic_Zadaca_Z8_ZaDobrovoljce()
{
	std::string a;
	char c;

	std::cout << "\n\n\tUnesite rijec: ";
	getline(std::cin, a);		// stavo sam getline u slucaju da korisnik zeli unijeti vise rijeci, iako za jednu rijec nije potrebno

	std::cout << "\n\n\tUnesite slovo: ";
	std::cin >> c;

	std::cout << "\n\n\tDuzina rijeci: " << duzina(a);
	std::cout << "\n\n\tBroj unesenih slova u rijeci: " << izbroji(a, c);
	std::cout << "\n\n\tBroj samoglasnika u rijeci: " << samogl(a);
	std::cout << "\n\n\n";
}