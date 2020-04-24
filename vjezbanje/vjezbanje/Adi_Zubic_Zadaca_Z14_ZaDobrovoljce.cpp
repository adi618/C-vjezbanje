#include "pch.h"


//Napravite program koji racuna period izmedu dva datuma.Pri unosu testirajte ispravnost unesenog
//datuma.U realizaciji programa koristite funkcije.
//Napomena: Prilikom provjere ispravnosti datuma pazite na prestupne godine.U prestupnoj godini februar
//ima 29 dana, a inace 28. Prestupna je godina koja je djeljiva sa 4 (npr. 2004, 2008, 1996...) osim onih
//koje su djeljive sa 100 (npr. 1900, 2100...), ali su godine djeljive sa 400 ipak prestupne(npr. 2000).
//Primjer :
//	Unesite prvi datum(d, m, g) : 31, 13, 2006 Neispravan datum!Unesite prvi datum(d, m, g) : 31, 12, 2006
//	Unesite drugi datum(d, m, g) : 2, 1, 2007 Izmedju datuma je proteklo 2 dana


bool prijestupnaGodina(int n)		// Prijestupna godina, linija ~105 objasnjava kako se racunaju prijestupne godine, samo sto je ovdje
{								// napisano koristeci i/ili operatore, a na liniji ~105 koristeci +, =, /, ali je princip isti.
	return (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0);
}

std::vector<int> korektanStrDatum(std::string datum)
{
	std::vector <int> vecDatum;
	datum += ' ';
	std::string temp = "";

	for (char karakter : datum)			// petlja koja razdvaja brojeve od ostalih karaktera, tako da korisnik moze unijeti
	{									// "2 2 2020", ili "2, 2, 2020" ili "2/2/2020".
		if ((karakter >= '0' && karakter <= '9') || karakter == '-')	// propustamo karakter - u slucaju da korisnik unese negativne
		{										// brojeve, ako je negativni broj unesen onda ce if-ovi ispod javiti gresku,
			temp += karakter;					// mogao sam odmah returnati gresku ukoliko nadjem -, ali sam zelio ostaviti
		}										// korisniku mogucnost da unese npr 2 - 2 - 2020, sto bi bio korektan datum.
		else if (temp != "")
		{
			vecDatum.push_back(stoi(temp));		// ovaj isti algoritam sam koristio da razdvojim rijeci u recenici u drugom zadatku
			temp = "";							// pete zadace, tako da nisam opet u velike detalje objasnjavao algoritam
		}
	}

	std::vector <int> prazanVector;
	if (vecDatum.size() < 3)		// ako nisu unijeta 3 broja, jedan za dan, jedan za mjesec, i jedan za godinu, funkcija
	{								// vraca prazan vektor kao znak da je izvrsen nekorektan unos
		return prazanVector;
	}
	else if (vecDatum[0] < 1 || vecDatum[0] > 31 || vecDatum[1] < 1 || vecDatum[1] > 12)
	{							// provjera da li su uneseni dan i mjesec moguci
		return prazanVector;
	}
	else
		if ((vecDatum[1] == 1 && vecDatum[0] > 31) || (vecDatum[1] == 2 && vecDatum[0] > 29) ||
			(vecDatum[1] == 3 && vecDatum[0] > 31) || (vecDatum[1] == 4 && vecDatum[0] > 30) ||
			(vecDatum[1] == 5 && vecDatum[0] > 31) || (vecDatum[1] == 6 && vecDatum[0] > 30) ||
			(vecDatum[1] == 7 && vecDatum[0] > 31) || (vecDatum[1] == 8 && vecDatum[0] > 31) ||
			(vecDatum[1] == 9 && vecDatum[0] > 30) || (vecDatum[1] == 10 && vecDatum[0] > 31) ||
			(vecDatum[1] == 11 && vecDatum[0] > 30) || (vecDatum[1] == 12 && vecDatum[0] > 31))
		{							// provjera da li su uneseni dan i mjesec moguci za svaki mjesec pojedinacno
			std::cout << "\t\tNAPOMENA: Uneseni mjesec ima manje dana nego broj unesenih dana!\n";
			return prazanVector;
		}
		else if (vecDatum[1] == 2 && vecDatum[0] == 29 && !(prijestupnaGodina(vecDatum[2])))
		{							// provjera da li je unesen 29 februar za godinu koja nije prijestupna
			std::cout << "\t\tNAPOMENA: Uneseni dan je 29 a unesena godina nije prijestupna!\n";
			return prazanVector;
		}
		else
			return vecDatum;		// ako je proslo sve if-ove, vracamo vektor u kojem se nalaze dan, mjesec, godina. 
}



void Adi_Zubic_Zadaca_Z14_ZaDobrovoljce()
{
	std::vector <int> vecDatum1;
	std::vector <int> vecDatum2;

	std::string strDatum1;
	std::string strDatum2;

	std::cout << "\n\n\tUnesite prvi datum (formata d, m, g): ";
	while (true)
	{
		getline(std::cin, strDatum1);
		vecDatum1 = korektanStrDatum(strDatum1);		// petlja koja se ponavlja dok se ne unese korektan datum

		if (vecDatum1.size() > 0)
			break;
		
		std::cout << "\n\t\tNekorektan unos, pokusajte ponovo (format d, m, g): ";
	}

	std::cout << "\n\n\tUnesite drugi datum (formata d, m, g): ";
	while (true)
	{
		getline(std::cin, strDatum2);
		vecDatum2 = korektanStrDatum(strDatum2);

		if (vecDatum2.size() > 0)
			break;

		std::cout << "\n\t\tNekorektan unos, pokusajte ponovo (format d, m, g): ";
	}

	int brDana1 = vecDatum1[2] * 365;		// izracunat cu broj dana od pocetka brojanja godina do jednog i drugog datuma,
	int brDana2 = vecDatum2[2] * 365;		// i onda dobit razmak dana izmedju njih tako sto cu ih oduzeti i printati apsolutnu vrijednost
											// za pocetak cu pomnoziti broj godina sa brojem dana u godini
	// sljedece, dodat cu po jedan dan na svaku prijestupnu godinu, svaka cetvrta godina je prijestupna, dakle + broj godina podijeljen
	// sa 4, onda trebam oduzeti svaku prijestupnu godinu koja je preskocena, tj - broj godina podijeljen sa 100, i na kraju trebam
	// ponovo dodati broj prijestupnih godina koje su dijeljive sa 4, 100 i 400, dakle + broj godina podijeljen sa 400
	brDana1 += vecDatum1[2] / 4 - vecDatum1[2] / 100 + vecDatum1[2] / 400;
	brDana2 += vecDatum2[2] / 4 - vecDatum2[2] / 100 + vecDatum2[2] / 400;

	// poslije ovoga trebamo izracunati broj dana od pocetka te godine do tog dana, i, ako je mjesec prosao februar, trebamo
	// dodati 1 ukoliko je prijestupna godina

	int mjeseci[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < vecDatum1[1] - 1; i++)	// od mjeseca oduzimamo 1 zato sto cemo za taj mjesec kasnije dodati dane
	{
		brDana1 += mjeseci[i];
	}
	for (int i = 0; i < vecDatum2[1] - 1; i++)
	{
		brDana2 += mjeseci[i];
	}
	brDana1 += vecDatum1[0];	// dodajemo dane
	brDana2 += vecDatum2[0];

	if (prijestupnaGodina(vecDatum1[2]) && vecDatum1[1] > 2) // ukoliko je prosao februar i prijestupna je godina dodajemo 1 dan
		brDana1++;
	if (prijestupnaGodina(vecDatum2[2]) && vecDatum2[1] > 2)
		brDana2++;

	std::cout << "\n\n\tRazmak izmedju ta dva datuma: " << std::abs(brDana1 - brDana2) << "\n\n\n";

	return; 
}