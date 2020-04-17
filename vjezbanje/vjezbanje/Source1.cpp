#include "pch.h"


struct Cvor
{
	friend class Mreza;

private:
	std::string ime_i_prezime;
	double prosjek;
	Cvor* veza;

public:

	Cvor(std::string ime_i_prezime, double prosjek)
		:ime_i_prezime(ime_i_prezime), prosjek(prosjek), veza(nullptr) {}
};

class Mreza
{
private:
	Cvor* glava;
	int velicina;

public:
	Mreza() :glava(nullptr), velicina(0) {}


	void dodajNoviCvor(const std::string& ime_i_prezime, const double& prosjek)
	{
		Cvor* noviCvor = new Cvor(ime_i_prezime, prosjek);

		if (glava == nullptr)
		{
			glava = noviCvor;
		}
		else
		{
			noviCvor->veza = glava;		// staru vezu setamo na glavu, pa glavu na novu vezu, redoslijed je vrlo vazan, obrnut ne bi radio
			glava = noviCvor;
		}
		velicina++;
	}

	void ispisiMrezu()
	{
		Cvor* iteracijskiPtr = glava;

		while (iteracijskiPtr != nullptr)
		{
			std::cout << "\n\tIme i prezime studenta: " << iteracijskiPtr->ime_i_prezime;
			std::cout << "\n\tProsjek studenta: " << iteracijskiPtr->prosjek;

			iteracijskiPtr = iteracijskiPtr->veza;
		}
	}
};


int main()
{
	Mreza* mreza = new Mreza();

	double prosjek;

	std::string ime_i_prezime;



	while (true)
	{
		std::cout << "Unesite ime studenta (da zaustavite ostavite unos prazan):\n\t\t";
		
		getline(std::cin, ime_i_prezime);

		if (ime_i_prezime == "")
			break;

		std::cout << "Unesite prosjek studenta:\n\t\t";
		std::cin >> prosjek;
		std::cin.ignore();

		mreza->dodajNoviCvor(ime_i_prezime, prosjek);
	}

	mreza->ispisiMrezu();

}