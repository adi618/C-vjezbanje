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

	//Cvor(std::string novoIme)
	//{
	//	this->ime_i_prezime = novoIme;
	//	std::cout << "\n\tMolimo unesite prosjecnu ocjenu: ";
	//	std::cin >> this->prosjek;

	//	std::cout << "\n\n\tMolimo unesite ime i prezime studenta, ukoliko zelite prekinuti unos pritisnite ENTER bez unosa:\n\t\t";
	//	getline(std::cin, this->ime_i_prezime);
	//}

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