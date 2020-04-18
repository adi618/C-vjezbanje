#include "pch.h"

//Kreirajte strukturni tip podataka koji modelira robu u skladistu za svrhe inventure.Potrebno je
//cuvati informacije o nazivu robe, broju skladista, kolicini robe u skladistu, minimalnoj kolicinu
//(ako je kolicina robe jednaka ili manja od minimalne kolicine, to znaci da treba pozvati
//	dobavljaca da se obezbijede efikasne zalihe robe), jedinicnoj cijeni robe, i imenu dobavljaca.
//	Zatim napisite program koji sa tastature cita podatke o robama u skladistu, a nakon toga stampa
//	izvjestaj koji za svaki artikal prikazuje njegov naziv, broj skladista, kolicinu u skladistu, te ime
//	dobavljača za one artikle cija je kolicina u skladistu manja od dozvoljene kolicine.


struct Artikal {
private:
	std::string naziv;				// Dobar dan profesore, buduci da ste mi u mailu rekli da priznajete svako vlastito rjesenje uz
	int maxBrojArtikala;			// komentare, odlucio sam malo da promjenim program. Ovo je nesto sto konstantno vidjam na internetu
	int brojArtikala;				// pa sam odlucio da probam isprogramirati. U pitanju je koristenje "gettera" i "settera" da se
	int minBrojArtikala;			// obezbjedi da se nekorektni unosi ne unose i da, u vecim projektima, smanji kolicinu koda.
	int cijenaArtikla;				// Ideja gettera i settera jeste da su sve varijable zasticene u private sektoru strukture/klase
	std::string imeDobavljaca;		// te da se njima upravlja samo preko funkcija koje mogu imati odredjene mjere prevencije protiv
									// nekorektnih unosa, kao sto sam ja uradio.
public:
	Artikal() :naziv(""), maxBrojArtikala(0), brojArtikala(0), minBrojArtikala(0), cijenaArtikla(0), imeDobavljaca("") {}
	// Na liniji iznad se nalazi default konstruktor za strukturu Artikal. On se pokrene kada se objekat ove strukture tek napravi,
	// inicijalizira sve njene varijable na 0 ili prazan string. Ovo se radi da se program ne bi crashao u slucaju greske negdje u kodu.

	void unesiNaziv(std::string noviNaziv) { this->naziv = noviNaziv; }			// Setteri
	void unesiMaxBrojArtikala(int noviMaxBrojArtikala)			// Ovaj setter seta unesenu valutu max broja artikala jedino ako je ona
	{															// veca od 0, u suprotnom je seta na nulu.
		if (noviMaxBrojArtikala < 1)
			this->maxBrojArtikala = 1;
		else
			this->maxBrojArtikala = noviMaxBrojArtikala;
	}

	void unesiBrojArtikala(int noviBrojArtikala)				// Ovaj setter seta unesenu valutu broja artikala jedino ako je ona
	{															// manja ili jednaka max broju artikala, posto ne mozemo imati vise
		if (noviBrojArtikala > this->maxBrojArtikala)			// artikala nego sto u skladistu ima.
			this->brojArtikala = this->maxBrojArtikala;
		else
			this->brojArtikala = noviBrojArtikala;
	}

	void unesiMinBrojArtikala(int noviMinBrojArtikala)			// Ovaj setter seta unesenu valutu min broja artikala jedino ako je ona
	{															// manja od max broja.
		if (noviMinBrojArtikala >= this->maxBrojArtikala)
			this->minBrojArtikala = this->maxBrojArtikala - 1;
		else
			this->minBrojArtikala = noviMinBrojArtikala;
	}

	void unesiCijenuArtikla(int novaCijenaArtikla)				// Ovaj setter seta unesenu valutu cijene broja artikala jedino ako je ona
	{															// veca od nule, tj artikal ne moze imati negativnu cijenu ili cijenu
		if (novaCijenaArtikla < 1)								// jednaku nuli
			this->cijenaArtikla = 1;
		else
			this->cijenaArtikla = novaCijenaArtikla;
	}
	void unesiImeDobavljaca(std::string novoImeDobavljaca) { this->imeDobavljaca = novoImeDobavljaca; } // Ovaj setter nema ogranicenja

	std::string ispisiNaziv() { return this->naziv; }						// Getteri
	int ispisiMaxBrojArtikala() { return this->maxBrojArtikala; }			// Oni samo vracaju valutu koja se nalazi u varijablama
	int ispisiBrojArtikala() { return this->brojArtikala; }					// strukture. Bez njih ne mozemo pristupiti tim varijablama
	int ispisiMinBrojArtikala() { return this->minBrojArtikala; }			// izvan funkcije posto su oni private clanovi funkcije.
	int ispisiCijenuArtikla() { return this->cijenaArtikla; }				// (jedino friend (prijateljske) strukture ili klase ove
	std::string ispisiImeDobavljaca() { return this->imeDobavljaca; }		// strukture mogu pristupiti privatnim varijablama)

};


void ispisArtikala(std::vector<Artikal>& vektorArtikala)
{
	system("cls");
	for (int i = 0; i < vektorArtikala.size(); i++)		// Petlja koja se ponavlja za svaki objekat Artikal vektora artikala
	{
		std::cout << "\n\n\t" << i + 1 << ". artikal:"							// Ove funkcije su sve dio strukture Artikal, i detaljnije
			<< "\n\tNaziv artikla: " << vektorArtikala[i].ispisiNaziv()			// su objasnjene u komentarima unutar strukture
			<< "\n\tMax broj artikala u skladistu: " << vektorArtikala[i].ispisiMaxBrojArtikala()
			<< "\n\tBroj artikala u skladistu: " << vektorArtikala[i].ispisiBrojArtikala()
			<< "\n\tMin broj artikala u skladistu: " << vektorArtikala[i].ispisiMinBrojArtikala()
			<< "\n\tCijena artikla: " << vektorArtikala[i].ispisiCijenuArtikla();
		if (vektorArtikala[i].ispisiBrojArtikala() < vektorArtikala[i].ispisiMinBrojArtikala())
			std::cout << "\n\tIme dobavljaca artikla (broj artikala je manji od min u skladistu): " << vektorArtikala[i].ispisiNaziv();
		std::cout << "\n\n\t";	// provjerava da li je broj artikala manji od min potrebnog broja u skladistu, ako jeste ispisuje ime dobavljaca
	}
}


void unosArtikala(std::vector<Artikal>& vektorArtikala)
{
	Artikal artikal;
	std::string stringTemp;		// Ove 3 varijable su sve pomocne (temp/trenutacne) varijable koje sluze samo da unesem stringove, brojeve i 
	int intTemp;				// da unesem objekt u vektor.

	system("cls");
	std::cout << "\n\n\tMolimo unesite naziv artikla: ";
	std::cin.ignore();
	getline(std::cin, stringTemp);
	artikal.unesiNaziv(stringTemp);						// Sve ove funkcije su dio strukture, unutar strukture su detaljnije objasnjene

	std::cout << "\n\tMolimo unesite max kolicinu mjesta u skladistu za uneseni artikal: ";
	std::cin >> intTemp;
	artikal.unesiMaxBrojArtikala(intTemp);

	std::cout << "\n\tMolimo unesite broj artikala u skladistu: ";
	std::cin >> intTemp;
	artikal.unesiBrojArtikala(intTemp);

	std::cout << "\n\tMolimo unesite min kolicinu mjesta u skladistu za uneseni artikal: ";
	std::cin >> intTemp;
	artikal.unesiMinBrojArtikala(intTemp);

	std::cout << "\n\tMolimo unesite cijenu artikla: ";
	std::cin >> intTemp;
	artikal.unesiCijenuArtikla(intTemp);

	std::cout << "\n\tMolimo unesite naziv dobavljaca: ";
	std::cin.ignore();
	getline(std::cin, stringTemp);
	artikal.unesiImeDobavljaca(stringTemp);

	std::cout << "\n\n\t";

	vektorArtikala.push_back(artikal);
}

void promjenaInformacijeArtikla(std::vector<Artikal>& vektorArtikala)
{
	int i;								// varijabla i prati unos korisnika za redni broj artikla koji korisnik zeli promjeniti
	std::string stringTemp;
	int intTemp;

	ispisArtikala(vektorArtikala);
	
	std::cout << "Unesite redni broj artikla ciju informaciju zelite promjeniti: ";
	std::cin >> i;
	while (i - 1 < 0 || i > vektorArtikala.size())		// petlja koja provjerava da li je unijeti redni broj validan.
	{
		std::cout << "\n\t\tArtikal tog rednog broja nije pronadjen, molimo pokusajte ponovo: ";
		std::cin >> i;
	}
	i--;

	int odabir;
	std::cout << "\n\tMolimo unesite sta zelite promjeniti:\n"
		<< "\n\t1 - Naziv; 2 - Max broj, 3 - Trenutni broj, 4 - Min broj, 5 - Cijena, 6 - Ime dobavljaca" 
		<< "\n\t\tOdabir:";			// Unos odabira za ono sto korisnik zeli da unese
	std::cin >> odabir;				// Zavisno o odabiru korisnika, pozivamo razlicite funkcije za editovanje vrijednosti
									// artikla zeljenog rednog broja.
	if (odabir == 1)
	{
		std::cout << "\n\n\tMolimo unesite novi naziv artikla: ";
		std::cin.ignore();
		getline(std::cin, stringTemp);
		vektorArtikala[i].unesiNaziv(stringTemp);
	}

	if (odabir == 2)
	{
		std::cout << "\n\tMolimo unesite novu max kolicinu mjesta u skladistu za uneseni artikal: ";
		std::cin >> intTemp;
		vektorArtikala[i].unesiMaxBrojArtikala(intTemp);
	}

	if (odabir == 3)
	{
		std::cout << "\n\tMolimo unesite novi broj artikala u skladistu: ";
		std::cin >> intTemp;
		vektorArtikala[i].unesiBrojArtikala(intTemp);
	}

	if (odabir == 4)
	{
		std::cout << "\n\tMolimo unesite novu min kolicinu mjesta u skladistu za uneseni artikal: ";
		std::cin >> intTemp;
		vektorArtikala[i].unesiMinBrojArtikala(intTemp);
	}

	if (odabir == 5)
	{
		std::cout << "\n\tMolimo unesite novu cijenu artikla: ";
		std::cin >> intTemp;
		vektorArtikala[i].unesiCijenuArtikla(intTemp);
	}

	if (odabir == 6)
	{
		std::cout << "\n\tMolimo unesite novi naziv dobavljaca: ";
		std::cin.ignore();
		getline(std::cin, stringTemp);
		vektorArtikala[i].unesiImeDobavljaca(stringTemp);
	}

	std::cout << "\n\n\t";
}

void Adi_Zubic_Zadaca_5_Z3()
{
	int num;								// Broj za odabir korisnika
	std::vector<Artikal> vektorArtikala;	// vektor strukture Artikal

	while (true)
	{
		system("pause");	// Pauziranje konzole kao i brisanje sve sa nje.
		system("cls");
		std::cout << "\n\n\tMolimo unesite opciju koju zelite:\n"
			<< "\n\t1 - Ispis svih artikala"
			<< "\n\t2 - Unos za novi artikal"
			<< "\n\t3 - Promjena informacija o zeljenom artiklu"
			<< "\n\t10 - Izlaz"
			<< "\n\n\t\tOdabir: ";

		std::cin >> num;

		while (num != 1 && num != 2 && num != 3 && num != 10)				// Petlja koja osigurava da je unijet korektan unos
		{
			std::cout << "\n\t\t\tNekorektan odabir, pokusajte ponovo: ";
			std::cin >> num;
		}
			

		if (num == 1)
		{
			ispisArtikala(vektorArtikala);			// Poziv funkcija za svaku od opcija.
		}

		if (num == 2)
		{
			unosArtikala(vektorArtikala);
		}

		if (num == 3)
		{
			if (vektorArtikala.size() == 0)		// Ukoliko je vektor prazan, preskacemo ovu opciju, buduci da nema unesenih artikala
				std::cout << "\n\n\tTrenutno nema artikala u vektoru.\n\n\t";			// koji bi se mogli promjeniti
			else
				promjenaInformacijeArtikla(vektorArtikala);
		}

		if (num == 10)								// Izlaz ukoliko je uneseni broj 10
			break;
	}
}
