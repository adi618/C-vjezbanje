#include "pch.h"


class Knjiga
{
private:
	int evidencijskiBr;
	std::string naslov;
	int clanskiBr;
	int brDanaNaCitanju;

public:
	Knjiga(int EB, std::string naslov)
		: evidencijskiBr(EB), naslov(naslov), clanskiBr(0), brDanaNaCitanju(0) {}	// konstruktor + initializer list

	int vratiEvidencijskiBr() { return evidencijskiBr; }		// funkcije koje vracaju vrijednosti privatnih 
	std::string vratiNaslov() { return naslov; }
	int vratiClanskiBrCitaoca() { return clanskiBr; }
	int vratiBrDanaNaCitanju() { return brDanaNaCitanju; }

	void proglasiZaduzenom(int clanskiBr)
	{
		this->clanskiBr = clanskiBr;	// setanje clanskog broja klase na clanski broj parametra
		brDanaNaCitanju = 0;
	}

	void proglasiRazduzenom()
	{
		clanskiBr = 0;
	}

	bool zaduzena()
	{
		return clanskiBr;		// vraca false ako je clanskiBr 0, u suprotnom true, tj vraca stanje zaduzenosti
	}

	virtual std::ostream& ipisiInfo(std::ostream& out)
	{	// virual nam omogucava da overridamo ovu metodu u nekim drugim klasama koje naslijede od ove klase
		out << "\n\tEvidencijski broj: " << evidencijskiBr << "  Naslov: " << naslov;
		return out;		// u zadatku je preciznod definisano da moramo u parametru ove funkcije proslijediti std::ostream po referenci (sto sam i uradio).
	}	// za (subjektivno) ljepsi kod, mozemo overloadat operator << da radi isto

	// virtual detaljnije objasnjenje: ukoliko imamo pointer na
	// objekat klase B, koja je naslijedila elemente glavne klase A, i pozovemo metodu koja se nalazi i u A i u B, 
	// pozvana metoda ce biti ona koja je unutar klase A. Dodavanjem keyworda virtual na metodu bazne klase (A) kazemo programu da
	// provjeri da li se ista ta metoda nalazi i u klasi B, i ako se nalazi onda pozovi tu metodu (klase B), a ne metodu klase A
	// Ovaj keyword vrlo blago usporava kompajler zato sto se "behind the scenes" pravi tzv. virtualna tabela (V table),
	// koja prati metode klase B koje je naslijedila od klase A. Ovo zahtijeva dodatnu memoriju kao i vrijeme (za provjeru prije poziva metoda)
	// koja je zanemariva u dalekoj vecini slucajeva (jedino nije ako nam treba apsolutno sva brzina koju mozemo dobiti).

	virtual bool udzbenik()
	{
		return false;
	}

	virtual Knjiga* vratiKopiju()	// ova funkcija nije dio zadatka, dodao sam je da olaksam kopiranje knjiga u copy constructoru
	{								// ona napravi i vrati pokazivac na kopiju
		return new Knjiga(this->vratiEvidencijskiBr(), this->vratiNaslov());
	}
};


class Udzbenik : public Knjiga		// klasa udzbenik koja prima atribute i metode klase knjiga, i na njih dodaje atribut predmet kao i neke metode
{
private:
	std::string predmet;

public:
	Udzbenik(int EB, std::string naslov, std::string predmet)
		: Knjiga(EB, naslov), predmet(predmet) {}	// pozivanje Knjiga konstruktora, i prosirenje koje inicijalizira predmet

	std::string vratiPredmet() { return predmet; }

	std::ostream& ipisiInfo(std::ostream& out)
	{	// ova metoda override-a metodu Knjige istog naziva. Mozemo dodati keyword 'override' iza parametra da oznacimo da je ova funkcija override-ana
		out << "\n\tEvidencijski broj: " << vratiEvidencijskiBr() << "  Naslov: " << vratiNaslov() << "\n\t\tPredmet: " << predmet;
		return out;
	}

	bool udzbenik()
	{
		return true;
	}

	Knjiga* vratiKopiju()
	{		// pravi i vraca pokazivac na kopiju Uzbenika
		return new Udzbenik(this->vratiEvidencijskiBr(), this->vratiNaslov(), this->predmet);
	}
};


class Biblioteka
{
private:
	int brKnjiga;
	const int maxBrKnjiga;
	Knjiga** knjige;		// dupli pointer koji ce pokazivati na prvi pointer niza pointera (niza pointera koji pokazuju na objekte klase knjiga)

public:
	Biblioteka(int maxBr)
		: brKnjiga(0), maxBrKnjiga(maxBr), knjige(new Knjiga* [maxBr])
		// initializer list dinamicki alocira maxBr knjiga, kao i seta maxBrKnjiga na taj broj
	{
		for (int i = 0; i < maxBr; i++)		// for petlja koja inicijalizira sve knjige na nullptr
		{
			knjige[i] = nullptr;
		}
	}

	~Biblioteka()
	{
		for (int i = 0; i < brKnjiga; i++)
			delete knjige[i];
		delete[] knjige;
	}

	// copy constructor | duboko kopiranje | konstruktor koji konstruise novi objekt identican objektu parametra
	Biblioteka(const Biblioteka& orginal)	// ne kopira da li je knjiga zaduzena ili nije, ja koliko sam shvatio zadatak ovo ne zeli tako da nisam uradio
		: brKnjiga(orginal.brKnjiga), maxBrKnjiga(orginal.maxBrKnjiga), knjige(new Knjiga* [orginal.maxBrKnjiga])
	{
		for (int i = 0; i < orginal.brKnjiga; i++)	// zadatak ovdje trazi da testiramo da li je knjiga obicna ili udzbenik, ja to nisam uradio zato
		{	// sto u mom rjesenju nema potrebe, buduci da funkcija vratiKopiju vraca kopiju bilo da je obicna knjiga ili udzbenik
			knjige[i] = orginal.knjige[i]->vratiKopiju();
		}
	}

	Biblioteka& operator = (const Biblioteka& temp)	// overloadamo operator '=' da pretvori jednu biblioteku u drugu ukoliko su im kapaciteti isti
	{	// moguce je da sam ovaj dio pogresno shvatio, pretpostavljam da "medjusobna dodjela" znaci samo x = y
		try		// ovaj dio baca exception ukoliko maxBrKnjiga te dvije biblioteke nisu isti
		{
			if (maxBrKnjiga != temp.maxBrKnjiga)
			{
				throw 3213;
			}
			else
			{
				for (int i = 0; i < temp.brKnjiga; i++)
				{
					if (knjige[i] != nullptr)	// ukoliko knjiga[i] nije nullptr to znaci da vec pokazuje na neku knjigu koju trebamo obrisat
						delete knjige[i];

					knjige[i] = temp.knjige[i]->vratiKopiju();	// pravimo kopiju knjige orginala i spasavamo je u objekat lijevo od operatora =
				}
				brKnjiga = temp.brKnjiga;	// nakon kopiranja, updateujemo brKnjiga
			}
		}
		catch (int x)	// hvatamo exception i ispisujemo error, ovdje imamo samo jedan error pa nije potrebno raditi nikakve dalje provjere
		{				// kad bismo imali vise errora (razlicitih brojeva) onda bi ifovima provjeravali koji su brojevi throw-ani i na osnovu toga bi
			std::cout << "\n\n\t\tGreska pri kopiranju biblioteke! (velicine biblioteka nisu iste)\n\n";	// ispisivali odgovarajuce errore
		}
	}

	void kreirajKnjigu(int EB, std::string naslov, std::string predmet = "")
	{		// funkcija koja kreira knjigu, odluci da li ce kreirati obicnu knjigu ili udzbenik na osnovu prisustva predmeta
		if (predmet == "")
			knjige[brKnjiga] = new Knjiga(EB, naslov);
		else
			knjige[brKnjiga] = new Udzbenik(EB, naslov, predmet);
		brKnjiga++;
	}

	Knjiga& vratiKnjigu(int EB)
	{
		try
		{
			for (int i = 0; i < brKnjiga; i++)
			{
				if (knjige[i]->vratiEvidencijskiBr() == EB)
					return *knjige[i];		// ukoliko se ovaj if ispuni nece doci do bacanja izostatka (exception)
			}
			throw 123;		// ako se if ne ispuni u for petlji, bacamo izostatak i ispisujemo error
		}
		catch (int x)	// imamo samo jedan error kao i u ranijem primjeru exception handling-a
		{
			std::cout << "\n\n\t\tGreska pri vracanju knjige! (knjiga nije pronadjena u biblioteci)\n\n";
		}
	}

	void zaduziKnjigu(int EB, int clanskiBr)
	{		// vratiKnjigu vraca objekt knjige proslijedjenog argumenta, na koji pozivamo proglasiZaduzenom metodu (argument je clanskiBr)
		vratiKnjigu(EB).proglasiZaduzenom(clanskiBr);
	}

	void razduziKnjigu(int EB)
	{
		vratiKnjigu(EB).proglasiRazduzenom();
	}

	int vratiCitaoca(int EB)
	{
		return vratiKnjigu(EB).vratiClanskiBrCitaoca();
	}

	void ispisiSlobodneKnjige()
	{
		for (int i = 0; i < brKnjiga; i++)
		{
			if (knjige[i]->vratiClanskiBrCitaoca() == 0)
			{
				knjige[i]->ipisiInfo(std::cout);
			}
		}
	}

	void ispisiZaduzeneKnjige()
	{
		for (int i = 0; i < brKnjiga; i++)
		{
			if (knjige[i]->vratiClanskiBrCitaoca() != 0)
			{
				knjige[i]->ipisiInfo(std::cout);
			}
		}
	}

	void ispisiKnjigeNaCitanjuDuzeOdParametra(int dana)		// ispis knjiga koje su na citanju duze od proslijedjenog broja (int dana)
	{
		for (int i = 0; i < brKnjiga; i++)
		{
			if (knjige[i]->vratiBrDanaNaCitanju() < dana)
			{
				knjige[i]->ipisiInfo(std::cout);
			}
		}
	}

	void sortirajKnjige(int dana)	// bubble sort za sortiranje knjiga po broju dana na cekanju, ako su ta dva broja jednaka onda ih sortiramo
	{								// po naslovu
		for (int i = 0; i < brKnjiga; i++)
		{
			for (int j = 0; j < brKnjiga - 1; j++)
			{
				if (knjige[j]->vratiBrDanaNaCitanju() < knjige[j + 1]->vratiBrDanaNaCitanju())	// provjera broja dana na cekanju
				{
					std::swap(knjige[j], knjige[j + 1]);
				}
				else if (knjige[j]->vratiBrDanaNaCitanju() == knjige[j + 1]->vratiBrDanaNaCitanju())
				{
					if (knjige[j]->vratiNaslov() < knjige[j + 1]->vratiNaslov())	// ako su isti, provjera naslova
					{													// mogli smo ovo staviti u jedan if, ali ovako ljepse izgleda
						std::swap(knjige[j], knjige[j + 1]);
					}
				}
			}
		}
	}
};


void Adi_Zubic_Zadaca_7_Z2()
{
	std::ifstream temp("knjige.txt");
	std::string red;
	int brKnjiga = 0;

	if (!temp.is_open())	// ako datoteka nije uspjesno otvorena izlazimo iz programa
	{
		std::cout << "\n\n\tDatoteka \"knjige.txt\" nije pronadjena!\n\n\n";
		return;
	}

	while (getline(temp, red))		// Prvobitno ne znamo koliko se knjiga nalazi u datoteci, tako da imamo par opcija. Mozemo alocirati neku kolicinu
	{								// koja bi predstavljala max broj ucitanih knjiga, ne bi se moglo vise ucitavati. Ovaj pristup je los zato sto trosi
		if (red[0] != 'U')			// dosta memorije i ima limit. Drugi pristup bi bio da, kad god nema vise mjesta u alociranom prostoru, prosirimo
			brKnjiga++;				// alocirani prostor tako sto bi, na drugoj lokaciji u memoriji alocirali nesto vise prostora, kopirali nase knjige
	}								// i obrisali orginal. Ovaj pristup koriste vektori i stringovi.
	//Ja sam uzeo pristup gdje prodjem kroz datoteku, izracunam broj knjiga, i toliko knjiga alociram. Ovo racunanje uradim u while petlji iznad
	temp.close();
	std::ifstream file("knjige.txt");

	Biblioteka biblioteka(brKnjiga);	// pravimo novi objekt biblioteke

	for (int i = 0; i < brKnjiga; i++)
	{
		int redniBrKaraktera = 0;	// broj koji prati indeks karaktera koji posmatramo
		int EB = 0;					// broj u koji cemo spasiti evidencijski broj
		std::string strEB = "";		// string u koji cemo spasiti EB u char formi, i kasnije konvertovat u integer formu i spasiti u EB
		std::string naslov = "";	// string za naslov
		getline(file, red);			// uzimamo red iz datoteke
		bool udzbenik = red[0] == 'U';	// bool udzbenik je true ukoliko je prvi karakter tog reda 'U'

		if (udzbenik)	// ukoliko je udzbenik, onda skipamo prvi karakter, posto je na njegovoj poziciji 'U', a zelimo da bude prvi broj evidencijskog broja
			redniBrKaraktera++;

		while (isdigit(red[redniBrKaraktera]))
		{
			strEB += red[redniBrKaraktera];	// u string strEB spasavamo nas evidencijski broj
			redniBrKaraktera++;
		}
		EB = stoi(strEB);	// strEB konvertujemo u int preko stoi funkcije i spasavamo u EB

		for (redniBrKaraktera++; redniBrKaraktera < red.size(); redniBrKaraktera++)
		{
			naslov += red[redniBrKaraktera];	// prepisivanje ostatka naslova u string naslov
		}

		if (udzbenik)
		{
			getline(file, red);	// ukoliko je udzbenik, uzimamo jos jedan red koji predstavlja predmet
			biblioteka.kreirajKnjigu(EB, naslov, red);
		}
		else
		{
			biblioteka.kreirajKnjigu(EB, naslov);
		}
	}

	std::ifstream zaduzenja("zaduzenja.txt");

	if (!zaduzenja.is_open())		// ako datoteka zaduzenja.txt nije pronadjena, ispisujemo isto i nastavljamo program.
	{								// mozemo nastaviti program zato sto ova datoteka nije mandatorna za rad programa
		std::cout << "\n\n\tDatoteka \"zaduzenja.txt\" nije pronadjena!\n\n\n";
	}

	while (getline(zaduzenja, red))
	{
		std::string strTemp = "";	// isti princip kao i za datoteku knjige.txt
		int EB = 0;
		int i = 0;
		while (isdigit(red[i]))
		{
			strTemp += red[i];
			i++;
		}	// nakon ove petlje i je indeks zareza
		EB = stoi(strTemp);
		// inkrementiramo ga da bude indeks prvog broja clanskog broja citaoca
		i++;
		strTemp = "";		// resetamo strTemp
		while (isdigit(red[i]))
		{
			strTemp += red[i];
			i++;
		}

		int clanskiBr = stoi(strTemp);
		biblioteka.zaduziKnjigu(EB, clanskiBr);
	}

	std::cout << "\n\n\tSlobodne knjige u biblioteci:\n";
	biblioteka.ispisiSlobodneKnjige();

	std::cout << "\n\n\tZaduzene knjige u biblioteci:\n";
	biblioteka.ispisiZaduzeneKnjige();

	// iznad je trazeni zadatak, a ispod sam ostavio zakomentarisane testne funkcije za neke od implementiranih metoda


	//std::cout << "\n\n\n\n";
	//Biblioteka testKopije(4);	// ova kopija ce baciti exception
	//testKopije = biblioteka;

	//testKopije.ispisiSlobodneKnjige();
	//testKopije.ispisiZaduzeneKnjige();


	//std::cout << "\n\n\n\n";
	//Biblioteka testKopije2(3);	// ova kopija nece baciti exception
	//testKopije2.kreirajKnjigu(23, "naslov knjige koji ce biti obrisan i zamijenjen naslovom knjige iz objekta biblioteke");
	//testKopije2.kreirajKnjigu(233, "naslov2", "predmet");
	//testKopije2 = biblioteka;

	//testKopije2.ispisiSlobodneKnjige();
	//testKopije2.ispisiZaduzeneKnjige();


	//std::cout << "\n\n\n\n";
	//Biblioteka copyConstructorTest(biblioteka);		// test funkcija za copy constructor

	//copyConstructorTest.ispisiSlobodneKnjige();
	//copyConstructorTest.ispisiZaduzeneKnjige();

	std::cout << "\n\n\n";
}