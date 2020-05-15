#include "pch.h"


//Napisati program u kome se citaju podaci o proizvodima u jednoj prodavnici auto - djelova iz postojece
//datoteke proizvodi.txt i kreira niz struktura tipa proizvod(naziv, proizvodac, cjena, kolicina), a zatim
//stampa :
//-ukupan broj proizvoda u datoteci,
//-ukupna vrijednost svih proizvoda u prodavnici,
//-spisak proizvoda cija je kolicina 0,
//-broj proizvoda koje proizvodi FIAT,
//-spisak proizvoda sortiranih po cjeni.


struct proizvod
{
	std::string naziv;
	std::string proizvodac;
	int cijena;
	int kolicina;
};


void selectionSortProizvoda(std::vector <proizvod>& proizvodi)	// Selection Sort: O(n^2) time complexity, O(1) space complexity, 
{																// ovaj algoritam se uglavnom ne koristi u pravom svijetu posto
	int min;													// uvijek ima bolja alternativa, uglavnom se koristi za edukativne
	for (int i = 0; i < proizvodi.size(); i++)					// svrhe. Radi na principu da se za svaki element prodje kroz petlju
	{															// jos jednom gdje ce se naci najmanji element. onda se element[i] zamjenjuje
		min = i;												// sa min elementom (moze se pratiti min element, a moze se pratiti i 
		for (int j = i + 1; j < proizvodi.size(); j++)			// index min elementa (sto sam ja uradio)), i tako sortiramo elemente.
		{
			if (proizvodi[min].cijena > proizvodi[j].cijena)
				min = j;
		}
		std::swap(proizvodi[i], proizvodi[min]);
	}
}


void Adi_Zubic_Zadaca_6_Z1()
{
	std::ifstream file("proizvodi.txt");	// otvaramo file

	if (file.is_open())		// provjera da li je file otvoren
	{
		proizvod temp;
		std::vector <proizvod> proizvodi;
		int ukupnaVrijednost = 0;
		int kolicinaNula = 0;
		int kolicinaFIATa = 0;

		while (file >> temp.naziv)		// petlja koja ucitava datoteku u temp vrijednost koju kasnije stavljamo u vektor
		{
			file >> temp.proizvodac;
			file >> temp.cijena;
			file >> temp.kolicina;
			ukupnaVrijednost += (temp.cijena * temp.kolicina);	// odmah racunamo koliko ukupno kostaju svi proizvodi,
			if (temp.kolicina == 0)								// koliko proizvoda ima kolicinu nula i koliko proizvoda ima
				kolicinaNula++;									// proizvodjaca "FIAT"
			if (temp.proizvodac == "FIAT")
				kolicinaFIATa++;
			proizvodi.push_back(temp);
		}
		file.close();		// zatvaramo file

		std::cout << "\n\n\tDatoteka je pronadjena!";
		std::cout << "\n\n\tUkupan broj individualnih proizvoda: " << proizvodi.size();	// ispisujemo velicinu, kao i ostale podatke
		std::cout << "\n\n\tUkupana vrijednost svih proizvoda: " << ukupnaVrijednost;
		std::cout << "\n\n\tBroj proizvoda cija je kolicina nula: " << kolicinaNula;
		std::cout << "\n\n\tBroj proizvoda ciji je proizvodjac \"FIAT\": " << kolicinaFIATa;
		std::cout << "\n\n\tProizvodi sortirani po cijeni:";
		selectionSortProizvoda(proizvodi);	// algoritam za sortiranje koji je objasnjen u komentarima pored samoga algoritma
		for (const proizvod& proiz : proizvodi)	// petlja koja iterira vektor proizvodi. Da ne bi bespotrebno pravili kopije svakog
		{										// proizvoda proslijedio sam iterator po referenci, a da ga slucajno ne bih promijenio kada
			std::cout << "\n\n\t\t\tNaziv proizvoda: " << proiz.naziv;			// ne trebam, stavio sam da je const (ovo je jedino vazno
			std::cout << "\n\t\t\tNaziv proizvodjaca: " << proiz.proizvodac;	// kod velikih projekata, za ove male zadatke nije).
			std::cout << "\n\t\t\tCijena proizvoda: " << proiz.cijena;
			std::cout << "\n\t\t\tKolicina proizvoda: " << proiz.kolicina;
		}
	}
	else
		std::cout << "\n\n\tDatoteka \"proizvodi.txt\" nije pronadjena!";
	std::cout << "\n\n\n\n";
}