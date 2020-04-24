#include "pch.h"


//Napraviti sljedeci program : Korisnik unosi cijele pozitivne brojeve putem tastature, ili nulu za kraj unosa.
//Ukoliko se unese negativan broj, on se ignorise.Nakon sto korisnik unese nulu, unosi se broj n(maksima
//	lno 10).Program ispisuje broj brojeva koji pri dijeljenju sa n daju ostatke 0, 1, 2, 3..., n­1.
//	Na primjer, recimo da je korisnik unio broj 4. Broj 16 pri dijeljenju sa brojem 4 daje ostatak 0. Treba naci
//	ukupan broj takvih brojeva x za koje vazi x % 4 = 0. Isti postupak ponoviti za ostatke 1, 2 i 3.
//	Primjer : 5 1 2 16 4 17 5 4 8 - 5 21 78 2 0 Unesite broj n : 4 Brojeva sa ostatkom 0 : 4 Brojeva sa ostatkom
//	1 : 5 Brojeva sa ostatkom 2 : 3 Brojeva sa ostatkom 3 : 0




void Adi_Zubic_Zadaca_Z15_ZaDobrovoljce()
{
	std::vector <int> arr;
	int n, broj;
	std::cout << "\n\n\tUnesite brojeve (negativni se ne racunaju, unesite 0 za prekid unosa):\n";

	while (true)
	{
		std::cout << "\t\t";
		std::cin >> n;

		if (n >= 0)
			if (n == 0)			// petlja za unos pozitivnih brojeva koja se breaka ako je uneseni broj 0
				break;
			else
				arr.push_back(n);
	}
	std::cout << "\n\n\tUnesite broj: ";
	while (true)
	{
		std::cin >> broj;
		if (broj > 0 && broj < 11)
			break;
		std::cout << "\n\t\tNekorektan unos, pokusajte ponovo (1 - 10): ";
	}
	std::cout << "\n\n\tBrojevi dijeljivi sa " << broj << ":\n\n\t\t";

	for (int num : arr)
	{
		if (num % broj == 0)			// uspisuje sve brojeve niza koji su dijeljivi sa brojem varijable broj
			std::cout << num << "  ";
	}
	std::cout << "\n\n";
}