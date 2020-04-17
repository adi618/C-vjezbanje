#include "pch.h"

//Definirajte strukturu “Cvor” koja sadrzi polje “ime_i_prezime” tipa “string”, zatim polje
//“prosjek” tipa “double” i polje “veza” koje je tipa pokazivac na “Cvor”.Iskoristite ovu strukturu
//u programu koji cita slijed podataka o studentima sa tastature, koji se sastoje od imena i
//prezimena i prosjeka za svakog studenta, sve dok se kao podatak o imenu studenta ne unese
//prazan string(tj.dok se ne pritisne samo ENTER bez ikakvog prethodnog unosa).Program treba
//da uveze te podatke u povezanu listu cvorova, ali koji nakon unosa svake od recenica umece
//cvor na takvo mjesto da lista u svakom trenutku bude sortirana po prosjeku u opadajucem
//redoslijedu kada se posmatra u redoslijedu kako idu veze izmedu cvorova(tj.student sa vecim
//	prosjekom treba da dode ispred studenta sa manjim prosjekom).U slucaju da vise studenata ima
//	isti prosjek, njih treba medusobno poredati po abecedi(preciznije, po poretku ASCII kodova).
//	Na kraju, program treba da ispise podatke o svim studentima u listi, da se uvjerimo da je lista
//	zaista sortirana u skladu sa trazenim specifikacijama.

class Lista {

	struct Cvor
	{
		std::string ime_i_prezime;
		double prosjek;
		Cvor* veza;
	};

	Cvor* glava;
	Cvor* trenutna;
	Cvor* temp;

public:
	Lista()
	{
		glava = nullptr;
		trenutna = nullptr;
		temp = nullptr;
	}

	void noviCvor(std::string novo_ime_i_prezime, double novi_prosjek)
	{
		Cvor* n = new Cvor;
		n->veza = nullptr;
		n->ime_i_prezime = novo_ime_i_prezime;
		n->prosjek = novi_prosjek;

		if (glava != nullptr)
		{
			trenutna = glava;
			while (trenutna->veza != nullptr)
			{
				trenutna = trenutna->veza;
			}
			trenutna->veza = n;
		}
		else
		{
			glava = n;
		}
	}

	void PrintList()
	{
		trenutna = glava;
		while (trenutna != nullptr)
		{
			std::cout << trenutna->veza << std::endl;
			trenutna = trenutna->veza;
		}
	}

};



/*	*Pocnite citati odavdje*  *Ovaj veliki blok teksta ne morate procitat tu sam opisao kako rade linked liste i njihovo poredjenje sa vektorima*

	- Eng. termin za trazeno: linked list
	- Svaki element linked liste je ili struktura ili klasa.
	- Svi elementi sadrze neku informaciju (u nasem slucaju: ime, prezime i prosjek) i vezu sa sljedecim elementom. Ta veza se uspostavlja
		pomocu pokazivaca.
	- Prvi element se zove glava (end. head), on pokazuje na drugi element. Drugi element pokazuje na treci element,
		i tako sve do zadnjeg elementa, koji pokazuje na null vrijednost. Null vrijednost se pise razlicito u razlicitim jezicima,
		u C++u je to nullptr (pokazivac koji je samo deklarisan, on ustvari ne pokazuje ni na sta).

	- Linked liste, u poredjenju sa vektorima, imaju veliku prednost kada je u pitanju pisanje i brisanje elemenata:
		- Linked liste: Da bi ubalici element na trecu poziciju, potrebno je samo promjeniti pokazivac druge pozicije da pokazuje na novi
			element, i pokazivac novog elementa setati da pokazuje na, prijethodno trecu, sada cetvrtu poziciju.
		- Vektori: Medjutim, da ubacimo element na trecu poziciju vektora, potrebno je napraviti novi vektor koji je za 1 veci od trenutnog,
			kopirati prvu, drugu poziciju, ubaciti zeljeni element, i onda ubaciti sve ostale elemente koji bi naravno bili na indeksu koji
			je za 1 veci od prijethodnog elementa.
		- Linked liste konkretno operaciju brisanja i pisanja rade u konstantnom vremenu (O(1)), tj. nezavisno o broju elemenata uvijek je potrebna
			ista kolicina vremena da se ubaci element na neku poziciju, dok vektori ovu operaciju rade u linearnom vremenu, tj. vise
			elemenata = duze se radi operacija (O(n) kompleksnost).
		- S druge strane, za pronalazenje X elementa, kod vektora mozemo koristiti algoritme kao sto su binary search (O(log n) kompleksnost),
			dok za linked liste ne mozemo koristiti te algoritme, vec moramo krenuti od pocetka liste i ici dok ne dodjemo do zeljenog
			elementa.
*/

void Adi_Zubic_Zadaca_5_Z4()
{

	Lista adi;

	adi.noviCvor("jesam", 2.3);
	adi.noviCvor("da", 2.5);
	adi.noviCvor("daaaa", 3.3);
	
	
	adi.PrintList();
	
	
	
	
	//std::string ime_i_prezime;
	//double prosjek;

	//std::cout << "\n\n\tMolimo unesite ime i prezime studenta, ukoliko zelite prekinuti unos samo pritisnite ENTER:\n\t\t";
	//getline(std::cin, ime_i_prezime);





	//while (ime_i_prezime != "")
	//{
	//	std::cout << "\n\tMolimo unesite prosjecnu ocjenu: ";
	//	std::cin >> prosjek;


	//	std::cout << "\n\n\tMolimo unesite ime studenta, ukoliko zelite prekinuti unos samo pritisnite ENTER:\n\t\t";
	//	getline(std::cin, ime_i_prezime);
	//}


}