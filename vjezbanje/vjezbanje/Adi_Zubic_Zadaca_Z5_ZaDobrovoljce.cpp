#include "pch.h"


//Ispitati da li je unijeti broj N prost koristeci rekurzivnu funkciju prost.Pronaci sve brojeve - blizance do
//zadatog broja n.Dva broja su blizanci ako su prosti i razlikuju se za 2.


class Timer
{
private:
	std::chrono::time_point <std::chrono::high_resolution_clock> start_point;

public:
	Timer()		// Ovo je klasa koju sam koristio za mjerenje vremena za razlicite implementacije funkcije prost. Radi na principu
	{			// da ima konstruktor (linija 16) koji zapocne da broji vrijeme kada se objekat funkcije Timer kreira, kao i
		start_point = std::chrono::high_resolution_clock::now();	// dekonstruktor (linija 19), koji stopira brojanje vremena,
	}			// izracuna i ispise rezultat kada objekat bude obrisan. U ovom slucaju se objekat brise kada se program zavrsi
				// buduci da tad kreirana klasa izadje iz scopea. Naravno mozemo je kreirati u nekom scopeu ako zelimo da se brojanje
	~Timer()	// vremena zavrsi prije kraja programa.
	{
		auto end_point = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast <std::chrono::microseconds>(start_point).time_since_epoch().count();
		auto stop = std::chrono::time_point_cast <std::chrono::microseconds>(end_point).time_since_epoch().count();

		std::cout << "\t\t" << (stop - start) * 0.001 << " miliseconds.\n\n";
	}
};


bool prost(int n, int i = 3)
{
	if (n < 2)			// Ukoliko je uneseni broj manji od 2 vracamo false
		return false;

	if (n == 2)			// Ukoliko je 2 vracamo true
		return true;

	if (n % 2 == 0)		// 2 je jedini paran broj koji je prost, ukoliko je n == 2, program nece doci do ove linije zato sto ce 13. linija
		return false;	// vratiti true i time prekinuti funkciju. Tako da, ukoliko je broj dijeljiv sa 2 mozemo odmah vratiti false.
						// Nije potrebno dalje provjeravati.

	if (i > sqrt(n))	// i povecavamo do sqrt(n), zato sto, ako pogledamo sve brojeve koji dijele n, primjetit cemo da su brojevi
		return true;	// iznad sqrt(n) samo obrnute verzije brojeva napisanih ispod sqrt(n), tako da nema potrebe provjeravati
						// dijeljivost za brojeve vece od sqrt(n).

	if (n % i == 0)		// Ukoliko je dijeljiv sa i onda vracamo false, a i cemo povecavati u buducim ponavljanjima funkcije
		return false;

	return prost(n, i + 2);		// Ako je funkcija dosla do ove linije, ponavljamo s tim da povecavamo i za 2. Razlog povecavanja sa 2
}								// jeste taj da je bespotrebno provjeravati da li su parni brojevi prosti buduci da smo u ranijem
								// if-u vec izbaciji sve parne brojeve (koji su veci od 2)
		// Klasu Timer koju vidite iznad koda ove funkcije koristim da vidim da li je ova implementacija funkcije prost zaista brza.
		// Rezultat: za unos 20000, optimizovana verzija funkcije prost je bila ~75ms brza, gdje je optimizovanoj verziji bilo potrebno
		// 700ms - 850ms, a malo manje optimizovanoj 750ms - 950ms. (malo manje optimizovana verzija je ona gdje i pocinje od 2,
		// inkrementira se za 1, i nema if-a koji provjerava parnost)
void Adi_Zubic_Zadaca_Z5_ZaDobrovoljce()
{
	int n;
	std::cout << "\n\n\tUnesite broj: ";
	std::cin >> n;

	std::cout << "\n\tBrojevi blizanci do unesenog broja:\n";

	Timer timer;
	for (int i = 0; i < n - 1; i++)
	{
		if (prost(i) && prost(i + 2))
			std::cout << "\n\tBroj " << i << " i " << i + 2 << " su blizanci";
	}
	std::cout << "\n\n";
}