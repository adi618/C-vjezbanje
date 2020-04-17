#include "pch.h"



using namespace std;

struct Bolnica
{
	char naziv[30];
	char grad[30];
	int brZaposlenih;
};

struct Odjel
{
	Bolnica bolnica;
	char naziv[30];
	float cijenaPoDanu;
};

struct Pacijent
{
	char imePrezime[30];
	Odjel odjel;
	int godiste;
	bool osiguran;
};

Pacijent unosPacijenta()
{
	Pacijent p;

	cout << "\n\n\tUnesite ime i prezime pacijenta: ";
	cin.getline(p.imePrezime, 30);

	cout << "\tUnesite naziv bolnice u kojoj je pacijent: ";
	cin.getline(p.odjel.bolnica.naziv, 30);

	cout << "\tUnesite grad u kojem je bolnica: ";
	cin >> p.odjel.bolnica.grad;

	cout << "\tUnesite broj zaposlenih u bolnici: ";
	cin >> p.odjel.bolnica.brZaposlenih;

	cout << "\tUnesite naziv odjela na kojem je pacijent: ";
	cin >> p.odjel.naziv;

	cout << "\tUnesite cijenu lezanja jednog dana na odjelu: ";
	cin >> p.odjel.cijenaPoDanu;

	cout << "\tUnesite godiste pacijenta: ";
	cin >> p.godiste;

	cout << "\tDa li je pacijent osiguran:\n\t\t0 = NE\n\t\t1 = DA\n\tOdabir: ";
	cin >> p.osiguran;

	return p;
}

void ispisPacijenta(Pacijent p)
{
	cout << "\n-----------------------------------------------------------------------------------------------\n";
	cout << "\n\tPodaci o pacijentu:";
	cout << "\n\tIme i prezime: " << p.imePrezime;
	cout << "\n\tBolnica: " << p.odjel.bolnica.naziv << " iz grada " << p.odjel.bolnica.grad << ". (" << p.odjel.bolnica.brZaposlenih << " zaposlenih)";
	cout << "\n\tOdjel: " << p.odjel.naziv << " - " << p.odjel.cijenaPoDanu << " po danu.";
	cout << "\n\tGodina: " << (2020 - p.godiste);
	cout << "\n\tOsiguran: " << ((p.osiguran) ? "DA" : "NE");
}

float cijena(Odjel o, int brDana)
{
	if (brDana == 1)
		return o.cijenaPoDanu;

	o.cijenaPoDanu = o.cijenaPoDanu * 0.95;

	return cijena(o, brDana - 1);
}

void Bolnica()
{
	Pacijent p;
	Odjel o;

	int brDana;

	p = unosPacijenta();
	ispisPacijenta(p);

	o.cijenaPoDanu = p.odjel.cijenaPoDanu;

	cout << "\n\n-----------------------------------------------------------------------------------------------\n";
	cout << "\n\tUnesite za koji dan zelite provjeriti cijenu: ";
	cin >> brDana;
	cout << "\tCijena " << brDana << ". dana iznosi: " << cijena(o, brDana) << " KM\n\n\n\n";
}