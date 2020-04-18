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




/*															O linked listama:
	- Eng. termin za trazeno: linked list
	- Svaki objekt linked liste je ili struktura ili klasa.
	- Svi objekti sadrze neku informaciju (u nasem slucaju: ime, prezime i prosjek) i vezu sa sljedecim objektom. Ta veza se uspostavlja
		pomocu pokazivaca.
	- Prvi objekt se zove glava (end. head), on pokazuje na drugi objekt. Drugi objekt pokazuje na treci objekt,
		i tako sve do zadnjeg objekta, koji pokazuje na null vrijednost. Null vrijednost se pise razlicito u razlicitim jezicima,
		u C++u je to nullptr (pokazivac koji je samo deklarisan, on ustvari ne pokazuje ni na sta).

	- Linked liste, u poredjenju sa vektorima, imaju veliku prednost kada je u pitanju pisanje i brisanje elemenata:
		- Linked liste: Da bi ubalici objekt na trecu poziciju, potrebno je samo promjeniti pokazivac druge pozicije da pokazuje na novi
			objekt, i pokazivac novog objekta setati da pokazuje na, prijethodno trecu, sada cetvrtu poziciju.
		- Vektori: Medjutim, da ubacimo objekt na trecu poziciju vektora, potrebno je napraviti novi vektor koji je za 1 veci od trenutnog,
			kopirati prvu, drugu poziciju, ubaciti zeljeni objekt, i onda ubaciti sve ostale objekte koji bi naravno bili na indeksu koji
			je za 1 veci od prijethodnog objekta.
		- Linked liste konkretno operaciju brisanja i pisanja rade u konstantnom vremenu (O(1)), tj. nezavisno o broju elemenata uvijek je potrebna
			ista kolicina vremena da se ubaci objekt na neku poziciju, dok vektori ovu operaciju rade u linearnom vremenu, tj. vise
			elemenata = duze se radi operacija (O(n) kompleksnost).
		- S druge strane, za pronalazenje X objekta, kod vektora mozemo koristiti algoritme kao sto su binary search (O(log n) kompleksnost),
			dok za linked liste ne mozemo koristiti te algoritme, vec moramo krenuti od pocetka liste i ici dok ne dodjemo do zeljenog
			objekta.
*/

struct Cvor
{
	friend class Mreza;		// Ova linija sluzi da dozvoli klasi Mreza da pristupi privatnim varijablama strukture Cvor

private:
	std::string ime_i_prezime;
	double prosjek;
	Cvor* veza;		// svaki objekt strukture Cvor takodjer sadrzi pokazivac na neki drugi objekt strukture Cvor, i ovim putem se uspostavljaju
					// veze izmedju svih objekata strukture Cvor, gdje prvi pokazuje na drugog, drugi na treceg i tako dalje.
public:

	Cvor(std::string ime_i_prezime_P, double prosjek_P)		// Ovo je konstruktor cija je osnova objasnjena na liniji 70, on ce uzeti ime, prezime
		:ime_i_prezime(ime_i_prezime_P), prosjek(prosjek_P), veza(nullptr) {}	// i prosjek koji su dio strukture Cvor, i setat ih na valute
};			// imena, prezimena i prosjeka koji smo proslijedili u konstruktor. (std::string ime_i_prezime_P, double prosjek_P) su varijable
			// koje je konstruktor dobio kao rezultat linije 70, a ime_i_prezime i prosjek su varijable objekta strukture Cvor cije se
			// valute setaju na proslijedjene. Takodjer pokazivac na sljedecu vezu setamo na nullptr.
class Mreza			// Nullptr cemo koristiti da znamo kada smo dosli do kraja linked liste, detaljnije na liniji 86
{					// Ovaj nacin setanja, tj. ime_funkcije(parametar) :varijabla_strukture(varijabla dobijena od parametara) se naziva
private:			// initialization list
	Cvor* glava;

public:
	Mreza() :glava(nullptr) {}


	void dodajNoviCvor(const std::string& ime_i_prezime, const double& prosjek)	// Ovo je funkcija u koju smo poslali ime, prezime i prosjek 
	{																			// (po const referenci jer ih ne planiram mijenjati)		

		Cvor* noviCvor = new Cvor(ime_i_prezime, prosjek);		// Novi objekt strukture Cvor. Struktura Cvor sadrzi konstruktor, tj.
				// sadrzi funkciju koja se pokrece samo onda kada se novi objekat napravi. Taj konstruktor ce primiti varijable koje smo
				// stavili u zagrade, tj. ime_i_prezime, prosjek. Na liniji 53 detaljnije objasnjeno
		
		if (glava == nullptr)	// Ukoliko je glava nullptr, to znaci da je lista prazna, te glavu pretvaramo u novi objekat, tj. objekat
		{						// koji je korisnik upravo unio. Ovaj if ce se izvrsiti samo jednom, buduci da glava nece biti jednaka
			glava = noviCvor;	// nullptr za svaki sljedeci objekt.
		}
		else
		{
			Cvor* trenutna = glava;			// Ako smo dosli do ovog koda, to znaci da imamo bar jedan objekat unutar nase liste,
			Cvor* prijethodna = nullptr;	// tako da prijethodnu setamo na nullptr, dok trenutnu setamo na glavu. Drugim rijecima:
					// glava je prvi objekt, a prijethodna je nullptr buduci da nemamo prijethodne jer je trenutna ustvari prva.
					// Kasnije u kodu cemo iterirati i jednu i drugu, efekat koji cemo dobiti jeste da ce trenutna uvijek biti objekt koji
					// trenutno analiziramo, a prijethodna onaj prije njega.

			while (trenutna != nullptr)						// Uloga ove petlje je da zaustavi kod na dijelu gdje trebamo ubaciti uneseni
			{												// objekt. Provjera unutar while petlje sluzi da zaustavi kod kada dodjemo do
				if (trenutna->prosjek < noviCvor->prosjek)	// kraja petlje, jer ako dodjemo do tog dijela, tu trebamo ubaciti objekt.
					break;	// Ovaj if sluzi da zaustavi petlju prije nego sto je kraj liste, vec kada dodjemo na dio gdje zelimo
							// ubaciti objekt da odrzimo sortiranje veceg prosjeka ka manjem.
				else if (trenutna->prosjek == noviCvor->prosjek && trenutna->ime_i_prezime > noviCvor->ime_i_prezime)	// Ovaj ovdje if
					break;	// koristim da zaustavim petlju kada su prosjeci jednaki i kada je ime_i_prezime trenutnog cvora alfabetski
							// vece od novog cvora. Naravno, mogli smo smjestiti sve ove uslove u uslov unutar while-a
				// ali sam ja rad lakseg razumijevanja ovako to uradio.

				prijethodna = trenutna;		// Ove dvije linije nam sluze da iteriramo kroz listu, tj. ako nismo dosli do dijela gdje
				trenutna = trenutna->veza;	// zelimo ubaciti nas objekat onda nastavljamo dalje kroz listu, tako sto pomjeramo
			}								// prijethodnu na trenutnu, trenutnu na sljedecu.

			if (trenutna == glava)			// Ovaj if (i else ispod njeg) nam sluze da ubacimo objekt na lokaciju koju je while petlja
			{								// iznad odlucila. Konkretno, ako se taj objekat treba ubaciti na pocetak, to znaci da trebamo
				noviCvor->veza = glava;		// updateovat glavu. noviCvor pokazujemo na glavu, a glava postaje noviCvor. Dakle upravo smo
				glava = noviCvor;			// glavu promjenili na noviCvor, a glava je onda postala drugi objekt linked liste.
			}									
												// Dio ispod je objasnjenje za zamjenu unutar else-a
			else								// Konkretno kako zamjena radi: imamo listu npr: 22, 18, 15; zelimo ubaciti broj 17 u listu,
			{									// preko iznad while petlje smo prosli preko brojeva 22 i 18, i dosli smo do broja koji je
				noviCvor->veza = trenutna;		// manji od zadnje unesenog broja. Zadnje uneseni broj je spasen u noviCvor. Ono sto je 
				prijethodna->veza = noviCvor;	// potrebno uraditi jeste uzeti vezu objekta noviCvor, postaviti je na trenutni element (15)
			}									// i onda vezu prijethodne postaviti na taj noviCvor. Rezultat 22 -> 18 -> 17 -> 15.
		}
	}

	void ispisiMrezu()
	{
		Cvor* iteracijskiPtr = glava;		// Pravimo novi Cvor i postavljamo ga na glavu, tj. na pocetak liste.

		while (iteracijskiPtr != nullptr)	// nullptr oznacava kraj liste, tako da ova petlja se nastavlja dok ne dodjemo do kraja
		{
			std::cout << "\n\tIme i prezime studenta: " << iteracijskiPtr->ime_i_prezime;	// ispisujemo ime i prezime
			std::cout << "\n\tProsjek studenta: " << iteracijskiPtr->prosjek;				// ispisujemo prosjek

			iteracijskiPtr = iteracijskiPtr->veza;		// objekt koji posmatramo pretvaramo u objekt na koji on pokazuje. Taj objekt
		}												// je sljedeci objekt liste osim ako nema vise objekata, u kojem slucaju
	}													// onda pokazuje na nullptr. (nullptr kao posljedica 54. linije gdje je
};														// veza po setana na nullptr cim se napravi)


void Adi_Zubic_Zadaca_5_Z4()
{
	double prosjek;
	std::string ime_i_prezime;

	Mreza* mreza = new Mreza();		// Pravimo novi objekt klase Mreza

	while (true)
	{
		std::cout << "Unesite ime studenta (da zaustavite ostavite unos prazan):\n\t\t";

		getline(std::cin, ime_i_prezime);	// Unosimo string za ime i prezime

		if (ime_i_prezime == "")			// Kada korisnik unese praznu liniju prekidamo petlju, tj. unos
			break;

		std::cout << "Unesite prosjek studenta:\n\t\t";
		std::cin >> prosjek;
		std::cin.ignore();

		mreza->dodajNoviCvor(ime_i_prezime, prosjek);		// dodajNoviCvor je funkcija unutar klase mreza,
	}														// u nju saljemo ime i prezime i prosjek.
	

	mreza->ispisiMrezu();	// i na kraju pozivamo funkciju ispisiMrezu koja je dio klase mreza, detaljnije objasnjenje pored same funkcije
}

