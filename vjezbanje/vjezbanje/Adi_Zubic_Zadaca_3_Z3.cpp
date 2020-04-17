#include "pch.h"

/*Napisite program koji od korisnika trazi da sa tastature unese recenicu, a koji ce zatim
ispisati unesenu recenicu bez prve rijeci te recenice.Unesena recenica se smjesta u
klasicni niz znakova(dakle, ne u promjenljivu tipa “string”).Za realizaciju zadatka
koristiti iskljucivo pokazivacku aritmetiku.Nije dozvoljena upotreba funkcija iz
biblioteka “cstring” niti “string”, kao ni upotreba indeksiranja(ukljucujuci i njegovu
	trivijalnu simulaciju koja podrazumijeva pisanje “* (a + n)” umjesto “a[n]”).*/

void Adi_Zubic_Zadaca_3_Z3()
{
	// Deklaracija niza za cuvanje recenice, i boola koji prati da li je prva rijec u recenici prosla ili ne.
	char recenica[100];
	bool prvaRijec = true;

	// Unos recenice.
	std::cout << "\n\n\tMolimo unesite recenicu:\n\t\t";
	std::cin.getline(recenica, 100);

	// Deklaracija pokazivaca ptr i inicijaliziranje samoga na prvu memorijsku lokaciju char niza recenica.
	char* ptr = recenica;

	std::cout << "\n\n\tUnesena recenica bez prve rijeci:\n\t\t";

	// Dokle god char na lokaciji pointera nije nula, petlja se nastavlja
	// U memoriji 0 oznacava kraj niza, tako da se petlja ponavlja dok ne dodje do kraja niza
	while (*ptr != 0)
	{
		// Ukoliko nadjemo razmak (dakle nije vise prva rijec, nego druga) setamo prvaRijec na false, da bi se ostale rijeci
		// onda ispisale.
		// Drugi dio if-a je prvaRijec, zato sto zelimo ono unutar if-a da se izvrsi samo jednom, tj. kada nadjemo prvi razmak.
		if (*ptr == ' ' && prvaRijec)
		{
			prvaRijec = false;

			// Kada nadjemo razmak, ne zelimo da se taj isti ispise, tako da povecavamo ptr.
			ptr++;
		}

		// Ukoliko je prvaRijec false, ispisujemo recenicu.
		if (!prvaRijec)
		{
			std::cout << *ptr;
		}

		// Ptr drzi memorijsku lokaciju prvog elementa niza, povecavanjem pomjeramo pointer na drugu memorijsku lokaciju
		// i tako sve povecavamo ptr dok se na njegovoj lokaciji ne nadje 0
		ptr++;
	}

	std::cout << "\n\n\n";
}