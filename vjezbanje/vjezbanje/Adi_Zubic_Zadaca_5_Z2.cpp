#include "pch.h"

//Napisite genericku funkciju koja prima 4 parametra od kojih prva dva omeduju jedan blok
//podataka a druga dva drugi blok podataka.Ovi parametri mogu biti bilo pokazivaci bilo iteratori,
//pri cemu su prva dva istog tipa i druga dva takoder istog tipa, ali tipovi prva dva parametra i
//druga dva parametra ne moraju biti isti.Ova funkcija treba da pronade da li se drugi blok nalazi
//kao podblok u prvom bloku(npr.blok{ 3, 5, 2 } nalazi se kao podblok u bloku{ 1, 7, 3, 5, 2, 6 }).
//Ukoliko se nalazi, funkcija kao rezultat vraća pokazivac / iterator na mjesto u prvom bloku na
//kojem se drugi blok nalazi kao podblok.Ukoliko se trazeni blok nalazi na vise mjesta kao
//podblok u prvom bloku, treba vratiti mjesto njegovog prvog pronalaska.Konacno, ukoliko
//traženi blok nije naden kao podblok u prvom bloku, treba vratiti pokazivac / iterator koji pokazuje
//tacno iza kraja prvog bloka.Napisite i kratki isjecak programa u kojem cete demonstrirati kako
//se koristi napisana funkcija na dva fiksna niza stringova


int Adi_Zubic_Zadaca_5_Z2(int* A_start, int* A_end, int* B_start, int* B_end)
{
	int duzinaA = (reinterpret_cast<std::uintptr_t>(A_end) - reinterpret_cast<std::uintptr_t>(A_start) + sizeof(*A_start));
	duzinaA = duzinaA / sizeof(*A_start);

	// Uzimamo pokazivace A_end i A_start, koji su u hexadecimalnim vrijednostima,
	// pretvaramo ih u njihove int vrijednosti. Ako od kraja oduzmemo pocetak i dodamo 1, dobijemo
	// duzinu niza, naravno, posto je integer niz, vazno je da jedinica koju dodajemo bude velicine int-a

	int duzinaB = (reinterpret_cast<std::uintptr_t>(B_end) - reinterpret_cast<std::uintptr_t>(B_start) + sizeof(*B_start));
	duzinaB = duzinaB / sizeof(*B_start);

	// Nalazimo duzinu niza B koristeci istu metodu kao i za niz A.

	// Naravno, mogli smo naci duzinu nizova preko for petlje, tj: napravimo kopiju pointera start, i iteriramo taj pointer
	// dokle god on nije jednak end pointeru, i za kraj dodamo jedinicu, kao i kod vec koristenog metoda.
	// Rezultat bi bio isti (dobili bi duzinu niza), ali ja sam koristio ovu metodu zato sto pretpostavljam da je optimizacijski
	// bolje konvertovati hexadecimalnu vrijednost u decimalnu, oduzeti i podijeliti, nego iterirati kroz oba niza individualno 
	// dok ne dodjemo do kraja.

	if (duzinaB > duzinaA)
		return -1;

	// Ukoliko je niz B veci od niza A onda niz B sigurno nije podniz A, vracamo -1

	for (int i = 0; i < duzinaA - duzinaB + 1; i++)
	{
		int j = 0;	// j deklarisemo i setamo na 0, razlog:
					// da poslije druge petlje mozemo provjeriti da li se ona zavrsila,
					// ovo takodjer sluzi da reseta j za svaku iteraciju i.

		for (j; j < duzinaB; j++)		// j povecavamo za duzinu niza B
		{
			if (*(A_start + i + j) != *(B_start + j))	// Prva iteracija ove petlje ce biti
			{											// niz A indeksa [i] != prvi broj niza B.
				break;									// Svaki sljedeci se povecati ova dva za 1
			}											// i ukoliko se petlja zavrsi bez breakanja
		}												// to znaci da je j onoliko veliko koliko i 
		if (j == duzinaB)								// duzina niza B, tako da u ovoj liniji
			return i;									// vracamo indeks.
	}


	return -1;		// vracamo -1 za situacije gdje niz B nije unutar niza A
}/*
	Ovu istu metodu mozemo koristiti i za pretrazivanje stringova.
	Niz cuva elemente tipa integer, a string bi cuvao elementer tipa char, tako da jedino sto bi trebali
	promjeniti unutar funkcije jeste parametre (promjeniti int* u char*), i sizeof(int) za mjerenje
	duzine zamijeniti sa sizeof(char).

	strstr() je funkcija koja daje isti rezultat kao ovdje opisani algoritam.
	To je built in funkcija C++a.
*/




/*									*Pocnite citati odavdje*
Ideja algoritma:
	-Prolaziti kroz niz A, kada se nadje broj koji je jednak prvom broju niza B, zapoceti drugu petlju,
		duzine niza B, koja ce provjeriti da li je niz B jednak tom dijelu niza A, ukoliko jeste, vracamo i.
	-Posmatrajuci niz A: druga petlja pocinje od broja i, a ide do i + (duzina niza B)

	-Odmah mozemo zakljuciti da ne smijemo proci kroz cijeli niz A, zato sto:
		-ako je niz B duzine 3, kada bi zapoceli drugu petlju, program bi poredio memorijske lokacije
			izvan A, sto u npr. visual studiu izaziva crash, a u nekim drugim nepredvidljiv rezultat
				(nepredvidljiv rezultat zato sto bi program onda poredio ono sto se nalazilo u tim
				memorijskim lokacijama prije pokretanja programa, ili bi poredio neke druge varijable
				programa koje su se igrom slucaja tu nasle)
		-cak i kada ovo ne bi izazvalo bug, opet je bespotrebno traziti podniz pocevsi od npr. zadnjeg
			elementa niza A, buduci da se niz B (npr. velicina 3) ne moze smjestiti u taj dio niza A.
	-Ova implementacija bi bila O(n*m) kompleksna.
*/
void Adi_Zubic_Zadaca_5_Z2()
{
	std::vector<int> nizA;		// Deklaracija vektora A i vektora B; vektori su (skoro) nizovi,
	std::vector<int> nizB;		// tako da cu im se, zbog kraceg naziva i vece logike, u ostatku
								// zadatka obracati kao nizovima

	int temp;
	std::cout << "\n\n\tMolimo unesite brojeve niza A (unesite '-1' da zaustavite unos):\n\t\t";
	while (true)				// while true petlja unutar koje imamo if koji sluzi da je prekine
	{
		std::cin >> temp;			// unosimo broj
		nizA.push_back(temp);		// broj stavljamo u vektor/niz
		std::cout << "\t\t";
		if (temp == -1)				// izlazimo iz petlje kada korisnik unese -1
			break;
	}
			// ispod radimo isto za niz B
	std::cout << "\n\n\tMolimo unesite brojeve niza B (unesite '-1' da zaustavite unos):\n\t\t";
	while (true)
	{
		std::cin >> temp;
		nizB.push_back(temp);
		std::cout << "\t\t";
		if (temp == -1)
			break;
	}

	// Ispisujemo niz A, zatim B
	std::cout << "\n\n\tNiz A: ";
	for (int i : nizA)
	{
		std::cout << i << " ";
	}
	std::cout << "\n\tNiz B: ";
	for (int i : nizB)
	{
		std::cout << i << " ";
	}

	// rezultat funkcije spasavamo u int rezultat (linija 150).
	// Mozemo primjetiti da u funkciju saljemo prvu memorijsku lokaciju niza A (i B), kao i 
	// zadnju memorijsku lokaciju niza A (i B). Zadnju mem. lokaciju smo dobili tako sto smo od duzine
	// oduzeli 1. Ukoliko je duzina 0, to znaci da ce rezultat (.size() - 1) biti -1, sto naravno nije
	// validan indeks u C++u. Da bi izbjegli ovaj bug ne smijemo zapoceti funkciju.
	// Ja cu ovo uraditi tako sto cu ispisati da je niz B podniz A ukoliko je duzina niza B 0.
	// (niz duzine 0 je uvijek podniz drugog niza X duzine).
	// Poslije toga cu ispisati da B nije podniz niza A ukoliko je niz A duzine 0.
	// (Ako je duzina niza A == 0, onda B nije podniz niza A; osim ako je i duzina niza B == 0, a
	// naravno ta situacija je rijesena u if-u linije 137)
	if (nizB.size() == 0)
	{	// prazan niz je uvijek podniz nekog drugog, ja sam stavio da ispise da taj podniz (B) pocinje
		// od indeksa 0 (indeksa 0 niza A).
		std::cout << "\n\n\tNiz B je podniz niza A, i on, unutar niza A, pocinje od indeksa: 0";
		return;
	}
	if (nizA.size() == 0)
	{	// U suprotnom, 
		std::cout << "\n\n\tNiz B je podniz niza A, i on, unutar niza A, pocinje od indeksa: 0";
		return;
	}


	int rezultat = Adi_Zubic_Zadaca_5_Z2(&nizA[0], &nizA[nizA.size() - 1], &nizB[0], &nizB[nizB.size() - 1]);

	// Funkcija vraca broj -1 ukoliko se niz B ne nalazi u nizu A
	// ukoliko se to desi, ispisujemo da se niz B ne nalazi u nizu A
	if (rezultat < 0)
	{
		std::cout << "\n\n\tNiz B nije podniz niza A. :(";
	}
	else			// U suprotnom, ispisujemo rezultat.
	{
		std::cout << "\n\n\tNiz B je podniz niza A, i on, unutar niza A, pocinje od indeksa: "
			<< rezultat;
	}
	std::cout << "\n\n\n";
}