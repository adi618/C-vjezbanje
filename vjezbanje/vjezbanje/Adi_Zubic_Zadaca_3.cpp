#include "pch.h"




// adresa je validna ukoliko se zavrsava na ".ba" i ukoliko ima tacno jedan karakter '@', prateci ove definicije "@.ba" je validna adresa
// "@@.ba" nije validna adresa jer ima 2 '@'

bool ludoA(char* adresa, int& i) // funkcija koja prima char adresa po pointeru, i int i po referenci
	// int i je poslan u funkciju po referenci iz optimizacijskih razloga, buduci da nam nece vise trebati
{
	int ludoA = 0;		// varijabla u koju spasavamo broj karaktera '@'

	for (i; i > -1; i--)		// iz optimizacijskih razloga smanjujemo brojac 'i', dok on ne bude jednak nuli
		// odlucio sam da smanjujem brojac kako ne bi morao deklarisati novu varijablu unutar for pelje koja bi sluzila kao brojac
	{
		if (*(adresa + i) == '@')		// da li je na memorijskoj lokaciji adresa + i karakter '@'
		{
			ludoA++;		// ukoliko jeste, povecaj var ludoA
		}
	}

	return ludoA == 1;		// vrati rezultat iskara (ludoA == 1), tj. vraca true jedino ako imamo jedno ludoA u adresi
}

int ispravna(char* adresa)
{
	int i = 0;		// brojac za prvu petlju, razlog zasto nije definisan unutar petlje je zato sto ce se kasnije koristiti
					// kao broj karaktera unutar adrese
	
	for (i; i < 50; i++)		// petlja koja ide do maximum broja karaktera adrese (50)
	{
		if (*(adresa + i) == 0)		// prvu memorijsku adresu emaila povecavamo za brojac, ako se na toj lokaciji nalazi 0 izlazimo iz petlje
									// u memoriji je kraj niza oznacen hexadecimanom nulom (takodjer i decimalna nula)
									// tako da kada nadjemo tu nulu to oznacava da je ili kraj niza ili su sljedeci elementi neinicijalizirani
		{
			break;		// prekid iz petlje
		}
	}		// ova petlja se moze zamijeniti sa i = strlen(adresa); strlen je upravo duzina inicijaliziranih karaktera char niza

	int a = strlen(adresa);

	if (*(adresa + --i) != 'a' || *(adresa + --i) != 'b' || *(adresa + --i) != '.') 
		// smanjujemo brojac i provjeravamo da li na tim lokacijama imamo ".ba"
	{
		return 0;		// ukoliko nemamo, return 0
	}

	if (!ludoA(adresa, i))		// funkcija "ludoA" provjerava da li imamo tacno jedan karakter '@' u petlji
		// u ovu funkciju saljemo adresu, i brojac koji je u if iskazu iznas smanjen za 3 broja
		// (zadnja 3 trebaju biti ".ba", tako da ne trebamo provjeravati ima li '@' u tim lokacijama
	{
		return 0;		// ukoliko email nema '@', return 0
	}

	return 1;		// ukoliko je program dosao do ovog trenutka email ima '@' i zavrsava se na ".ba", tako da vracamo 1
}

void Adi_Zubic_Zadaca_3()
{
	char email[50];		// deklaracija varijable (char niz) koja cuva email, max br karaktera je 50
	char* ptr;		// deklarisanje char pointera pod nazivom ptr

	std::cout << "\n\n\n\tUnesite email adresu:\n\n\t\t";		// ispis uputstva
	
	std::cin >> email;		// unos emaila

	ptr = email;		// inicjaliziranje varijable ptr na prvu memorijsku lokaciju char niza email

	std::cout << "\n\n\tUnesena email adresa " << (ispravna(ptr) ? "je " : "nije ") << "validna\n\n\n\n";		// ispis da li je adresa validna ili ne
}