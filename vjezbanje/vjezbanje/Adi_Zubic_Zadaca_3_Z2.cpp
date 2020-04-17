#include "pch.h"

/*Napisite program koji trazi od korisnika da unese niz recenica, pri cemu se broj recenica
prethodno unosi sa tastature.Za svaku unesenu recenicu dinamicki alocirajte prostor,
uz vodenje evidencije o adresi svake alocirane recenice u dinamickom nizu pokazivaca
na pocetke svake od recenica.Nakon toga, treba ispisati unesene recenice sortirane u
abecedni poredak(odnosno u poredak po ASCII kodovima).Sortiranje obavite rucno,
bilo kojim postupkom koji Vam je poznat(drugim rijecima, nemojte koristiti gotove
	funkcije za sortiranje, poput funkcije "sort„ iz biblioteke "algorithm".*/

void Adi_Zubic_Zadaca_3_Z2()
{
	int n;
	
	std::cout << "\n\n\tMolimo unesite koliko zelite recenica unijeti: ";
	std::cin >> n;
	std::cout << "\n";

	// Double pointer, dakle na memorijskoj lokaciji je zapisana memorijska lokacija koja onda pokazuje
	// na memorijsku lokaciju, na ovoj memorijskoj lokaciji se nalazi prvi karakter nase recenice.
	char** recenice = new char* [n];

	for (int i = 0; i < n; i++)
	{
		// Od memorijske lokacije recenie[i] dalje alociramo 100 memorijskih mjesta za karaktere nase recenice.
		// Buduci da ovo alociranje nije izvrseno na stack-u, nego na heap-u, ove recenice u memoriji nece biti spremljene jedna pored druge,
		// nego ce biti na lokacijama u ramu koje su u momentu deklaracije bile dostupne.
		recenice[i] = new char[100];
	}

	// Petlja ispod nam upravlja u koju recenicu upisujemo karaktere, indeks 0 je prva recenica, i tako sve do unesenog broja n.
	for (int i = 0; i < n; i++)
	{
		std::cout << "\n\tMolimo unesite " << i + 1 << ". recenicu (kraj recenice molimo oznacite tackom, uzvicnikom ili upitnikom):\n\t\t";

		// Petlja ispod nam sluzi da u recenicu indeksa [i] upisujemo karaktere, max karaktera po recenici je 100.
		for (int j = 0; j < 100; j++)
		{
			// Ukoliko je i = 2: recenice[i] je prva memorijska lokacija trece unesene recenice, na nju prvobitno dodajemo j = 0,
			// ovo je memorijska lokacija prvog karaktera nase trece recenice, dodavanjem j = 1 dobijemo mem. lokaciju
			// drugog karaktera nase trece recenice.
			std::cin.get(*(recenice[i] + j));

			// Ukoliko korisnik unese tacku, uzvicnik ili upitnik, to je kraj recenice te zaustavljamo unos
			if (*(recenice[i] + j) == '.' || *(recenice[i] + j) == '!' || *(recenice[i] + j) == '?')
			{
				break;
			}
		}
	}

	// Ja sam izabrao Bubble Sort algoritam za sortiranje, Vi ste nam dali primjer Merge Sort-a i Quick Sort-a u prezentacijama
	// tako da sam mogao koristiti i te, ali, buduci da nisu u pitanju ogromi brojevi, izabrao sam da uradim preko Bubble Sort-a
	// zato sto je dosta jednostavniji za iskodirati.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			// Buduci da trebamo po abecedi svrstati recenice, za sortiranje gledamo prvo slovo recenice, zato smo
			// recenice na poziciji j depointerovali, tj. napisali smo zvjezdicu ispred memorijske lokacije.

			// Potrebno je porediti prvo slovo, a u if-u se porede druge mem. lokacije, ovo je zato sto kada koristimo
			// cin.get() za unos karaktera, prvi karakter jeste '\n', zelimo njega ignorisati i porediti prvo slovo, sto uradimo
			// poredjenjem druge memorijske lokacije umjesto prve.
			if (*(recenice[j] + 1) > *(recenice[j + 1] + 1))
			{
				// Kada swapamo recenice, zelimo swapati cijele recenice, to se moze uraditi tako sto samo swapamo pointere
				// kao sto je uradjeno ispod.
				// Kada bismo napisali std::swap(*recenice[j], *recenice[j + 1]);
				// onda bi program swapao samo prvi karakter recenica, a ne cijele recenice.
				char* temp = recenice[j];
				recenice[j] = recenice[j + 1];
				recenice[j + 1] = temp;
			}
		}
	}

	// Ispod su petlje za ispis, rade na isti princip kao i petlje za upis, prva petlja prolazi kroz recenice, dok druga
	// prolazi kroz slova tih recenica i ispisuje ih.
	for (int i = 0; i < n; i++)
	{
		std::cout << "\n\n\t" << i + 1 << ". recenica po abecednom redoslijedu prvog slova:";
		for (int j = 0; j < 100; j++)
		{
			std::cout << *(recenice[i] + j);
			
			// Linija ispod je tu radi estetike, nije potrebna za izvrsavanje programa, a takodjer znatno usporava program
			// zato sto se ovaj if uslov ispituje n*100 puta.
			if (j == 0)
				std::cout << "\t\t";

			if (*(recenice[i] + j) == '.' || *(recenice[i] + j) == '!' || *(recenice[i] + j) == '?')
			{
				break;
			}
		}
		delete[] recenice[i];
	}

	// Buduci da je sve ovo dinamicki alocirani, tj. deklarirano na heapu, ta memorija se nece sama obrisati pa mi to moramo uraditi
	// Petlja sluzi da obrise sve individualne recenie, dok delete[] recenice brise alociranu memoriju na kojoj su bile
	// spremljene adrese individualnih recenica.

	delete[] recenice;

	std::cout << "\n\n\n";
}