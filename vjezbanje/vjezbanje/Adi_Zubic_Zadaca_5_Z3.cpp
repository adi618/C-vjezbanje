#include "pch.h"

//Kreirajte strukturni tip podataka koji modelira robu u skladistu za svrhe inventure.Potrebno je
//cuvati informacije o nazivu robe, broju skladista, kolicini robe u skladistu, minimalnoj kolicinu
//(ako je kolicina robe jednaka ili manja od minimalne kolicine, to znaci da treba pozvati
//	dobavljaca da se obezbijede efikasne zalihe robe), jedinicnoj cijeni robe, i imenu dobavljaca.
//	Zatim napisite program koji sa tastature cita podatke o robama u skladistu, a nakon toga stampa
//	izvjestaj koji za svaki artikal prikazuje njegov naziv, broj skladista, kolicinu u skladistu, te ime
//	dobavljača za one artikle cija je kolicina u skladistu manja od dozvoljene kolicine.

const std::vector<std::string> artikli = { "bicikl", "skije", "lopta", "tene", "kopacke" };

class artikal {
private:
	std::string naziv;
	int maxBrojArtikla;
	int brojArtikla;
	int minBrojArtikla;
	int cijenaArtikla;

public:
	bool unesiNaziv(std::string noviNaziv)
	{
		std::string temp;
		for (char slovo : noviNaziv)
			temp += tolower(slovo);
		noviNaziv = temp;

		bool validan = false;
		for (std::string validanNaziv : artikli)
		{
			if (noviNaziv == validanNaziv)
			{
				this->naziv = noviNaziv;
				validan = true;
				return true;
			}
		}
		return false;
	}
	void unesiMaxBrojArtikla(int noviMaxBrojArtikla) { this->maxBrojArtikla = noviMaxBrojArtikla; }
	void unesiBrojArtikla(int noviBrojArtikla) { this->brojArtikla = noviBrojArtikla; }
	void unesiMinBrojArtikla(int noviMinBrojArtikla) { this->minBrojArtikla = noviMinBrojArtikla; }
	void unesiCijenuArtikla(int novaCijenaArtikla) { this->cijenaArtikla = novaCijenaArtikla; }

	std::string ispisiNaziv() { return this->naziv; }
	int ispisiMaxBrojArtikla() { return this->maxBrojArtikla; }
	int ispisiBrojArtikla() { return this->brojArtikla; }
	int ispisiMinBrojArtikla() { return this->minBrojArtikla; }
	int ispisiCijenuArtikla() { return this->cijenaArtikla; }



	artikal()
	{

	}


};


void Adi_Zubic_Zadaca_5_Z3()
{



}
