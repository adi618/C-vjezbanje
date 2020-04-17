#include "pch.h"

/*Napisati program koji trazi od korisnika da unese spisak rijeci
(broj rijeci se prethodno unosi sa tastature), a zatim ispisuje na
ekran prvu i poslednju rijec iz spiska po abecednom poretku,
kao i popis svih unesenih rijeci, ali bez ispisivanja duplikata(tj.
	bez ispisivanja rijeci koje su se vec jednom ispisale).Program
	realizirati koristenjem vektora stringova, odnosno vektora ciji
	su elementi tipa “string”.*/

void Adi_Zubic_Zadaca_4()
{
	int n;
	std::string temp;	// deklaracija stringa u koji cemo stavljati individualne rijeci

	std::cout << "\n\n\tUnesite broj rijeci: ";
	std::cin >> n;

	std::vector<std::string> nizRijeci;		// deklaracija vektora tipa string pod nazivom nizRijeci
	// ukoliko samo deklarisemo vektor, njegova velicina je 0.
	// ako zelimo dodati element (funkcija .push_back()), program mora napraviti novi vektor u memoriji, koji je za 1 veci od proslog,
	// tako da se napravi mjesta u vektoru za spasavanje novog elementa

	nizRijeci.reserve(n);		// optimizacije radi, ukoliko prije unosenja elemenata vec znamo otprilike koliko ce elemenata biti u vektoru,
	// mozemo koristiti komandu .reserve(), koja odmah napravi vektor velicine broja u zagradama. Ovako se ne moraju svaki
	// put, pri dodavanju elementa, kopirati trenutni elementi u novi vektor velicine proslog + 1
	
	// ne moramo koristiti funkciju .reserve(), isto se moze postici pisanjem: std::vector<std::string> nizRijeci(n);
	// gdje je n upravo broj reservacija koje se naprave pri deklaraciji

	for (int i = 0; i < n; i++)		// petlja za unos rijeci, ide do broja rijeci koji korisnik unese
	{
		std::cout << "\t\tUnesite " << i + 1 << ". rijec: ";
		std::cin >> temp;				// rijec koju korisnik unese se spasava u temp
		nizRijeci.push_back(temp);		// temp (ta rijec) se stavlja u vektor nizRijeci
	}

		// Bubble Sort algoritam za sortiranje rijeci
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (nizRijeci[j] > nizRijeci[j + 1])
			{
				temp = nizRijeci[j];
				nizRijeci[j] = nizRijeci[j + 1];
				nizRijeci[j + 1] = temp;
			}
		}
	}

	if (n > 0)	// ukoliko je n vece od nula, ispisujemo prvu [0] i zadnju [n - 1] rijec. Ovaj if osigurava da se program nece
				// crashovati ukoliko korisnik unese broj manji od 1. Npr: Ako korisnik unese 0, program bi se crashovao
	{			// zato sto indeks na poziciji [n - 1] ne bi bio validan. (-1 nije validan indeks u C++u)
		std::cout << "\n\n\tPrva rijec: " << nizRijeci[0] << "\n\tZadnja rijec: " << nizRijeci[n - 1] << std::endl;
		std::cout << std::endl << "\n\tIspis rijeci: " << std::endl;
	}			// optimizacije radi bi mogli staviti ovaj if na pocetak programa, ali radi lakseg razumijevanja sam ga ja ovdje stavio

	
	nizRijeci.push_back("");						// u vektor ubacujemo prazan string zato sto cemo u sljedecoj petlji ispisivati
	for (int i = 0, j = 1; i < n; i++)				// rijeci indeksa [i] koje su razlicite rijecima indeksa [i + 1], zbog ovog i + 1 moramo
	{												// dodati jednu rijec. Ukoliko je ne dodamo, u zadnjem ciklusu i ce biti za 1 manje od n,
		if ((nizRijeci[i] != nizRijeci[i + 1]))		// tako da dodavanjem 1 ce i biti n, sto znaci da je i za 1 vece od zadnjeg indeksa vektora
		{											// tako da se program crashuje (zadnji indeks je n - 1)
			std::cout << "\t\t" << j << ". rijec: " << nizRijeci[i] << std::endl;
			j++;		// j koristimo kao counter za rijec koju ispisujemo. J je prvobitno 1, dakle prva rijec, inkrementiramo j
		}				// svaki put kada ispisemo rijec, tako da je j uvijek jednaka rednom broju rijeci koju ispisujemo.
	}

	std::cout << "\n\n\n";
}