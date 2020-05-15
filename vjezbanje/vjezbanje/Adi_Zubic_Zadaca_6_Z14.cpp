#include "pch.h"


//Zadatak je naci najkraci put(najmanje prijedenih polja) od pocetnog mjesta gdje se nalazi Zenit(M), do njegove kuce
//(K) tako da se gradom krecemo samo «povezanom» cestom(.), a da pritom nemamo «u blizini» prometnu policiju(P).
//Napomene
//- Dvije ceste su «povezane»(tj.polja su susjedna) ako imaju zajednicku stranicu.
//- «U blizini» znaci da cesta kojom prolazimo ne smije imati susjedno polje na kome se nalazi prometna policija.
//- Ne mora postojati jedinstveno minimalno rjesenje puta do kuce.
//- Iz ulaznih podataka uvijek ce se moci dobiti rjesenje.
//Ulazni podaci
//U prvom retku tekstualne datoteke Zenit.in nalaze se dva broja odvojena jednim razmakom, M i N iz opisa zadatka
//(M je broj redaka, a N broj stupaca pravougle mreze grada), za koje vrijedi sljedece : 0 < M, N < 101.
//U sljedecih M redova nalazi se u svakom od njih po N znakova, takoder prethodno opisani.
//Izlazni podaci
//U prvom i jedinom retku tekstualne datoteke Zenit.out potrebno je ispisati minimalni broj polja do kuce(broj polja
//	koja predstavljaju cestu).
//
//	Primjeri
//
//	Zenit.in
//	4 4
//	xPxP
//	M.x.
//	....
//	x..K
//
//	Mile.out
//	4
//
//	Zenit.in
//	5 8
//	PxxxPxxx
//	.x.....K
//	M..xxx.x
//	.x.....x
//	P.x.xxxx
//	Mile.out
//	9

struct CvorGrafa
{
	int i, j;				// struktura u koju cu spasavati 'i' i 'j' indekse ulice na kojoj se nalazim, kao i njenu udaljenost od pocetka
	int udaljenost;
	// ispod je konstruktor + initializer list, jedan za kada saljem u njeg i, j i udaljenost, a drugi je default
	CvorGrafa(int i, int j, int udaljenost) : i(i), j(j), udaljenost(udaljenost) {}		// konstruktor ukoliko zelim samo napraviti
	CvorGrafa() : i(0), j(0), udaljenost(0) {}											// objekat bez inicijalizacije
};


void Adi_Zubic_Zadaca_6_Z14()
{
	std::ifstream file("Zenit.in.txt");

	if (file.is_open())
	{
		int visina;
		int sirina;

		file >> visina;
		file >> sirina;		// znamo da je prvi broj visina matrice, a drugi sirina, pa ih odmah spasavam u int visina i int sirina


		std::vector <std::vector <char>> matrica;		// vektor vektora charova, tj. matrica simbola za ostatak teksta iz ucitane datoteke
		for (int i = 0; i < visina; i++)
		{
			std::string strTemp;
			file >> strTemp;				// u strTemp ucitavamo red iz file-a
			std::vector <char> temp;
			for (int j = 0; j < sirina; j++)
			{
				temp.push_back(strTemp[j]);		// ucitani red pushamo u vektor temp
			}
			matrica.push_back(temp);		// vektor temp pushamo u vektor vektora, i tako dobijemo matricu simbola
		}

		file.close(); // zavrsili smo sa fileom, tako da ga mozemo zatvoriti

		for (int i = 0; i < visina; i++)			// u ovoj duploj petlji cemo proci kroz matricu, za svaki simbol matrice cemo provjeriti
		{											// da li se tu nalazi 'P', tj. policija, ako da, susjedne tacke cemo pretvoriti u 'x'
			for (int j = 0; j < sirina; j++)		// zato sto ne smijemo ici na te tacke radi susjednog 'P', pa sam odlucio da je najlakse
			{										// da ih odmah pretvorim u 'x'
				if (matrica[i][j] == 'P')
				{														// Ako je posmatrani simbol == 'P', onda:
					// slovo direktno iznad
					if (i > 0 and matrica[i - 1][j] == '.')				// taj simbol pretvaramo u 'x' ukoliko je on '.' i ukoliko i nije 0
						matrica[i - 1][j] = 'x';						// Ukoliko je i == 0 i probamo promijeniti simbol iznad u '.'
																		// program ce se crashovati zato sto ta memorijska lokacija ne pripada
					// direktno dole									// nama, tj. lokacija indeksa i - 1 i j ne pripada nama ukoliko je i == 0
					if (i < visina - 1 and matrica[i + 1][j] == '.')
						matrica[i + 1][j] = 'x';						// takodjer je vrlo vazno da provjerimo da li se tu nalazi tacka,
																		// bez ove provjere bi se 'M' ili 'K' pretvorili u 'x' kada bi se 
					// desno											// oni nasli pored 'P'
					if (j < sirina - 1 and matrica[i][j + 1] == '.')
						matrica[i][j + 1] = 'x';

					// lijevo
					if (j > 0 and matrica[i][j - 1] == '.')
						matrica[i][j - 1] = 'x';						// ja koliko sam shvatio, zadatak trazi da ne uzimamo u obzir
																		// tacke koje su direktno iznad, ispod, lijevo ili desno, a da uzimamo 
					//// gore desno										// u obzir tacke koje su npr: iznad za 1 i desno za 1
					//if (i > 0 and j < sirina - 1 and matrica[i - 1][j + 1] == '.')		// ukoliko sam pogresno shvatio zadatak,
					//	matrica[i - 1][j + 1] = 'x';										// ostavio sam alternativu u komentarima
																							// koja mjenja sljedeca polja u 'x':
					//// gore lijevo																	// gore desno, gore lijevo,
					//if (i > 0 and j > 0 and matrica[i - 1][j - 1] == '.')								// dole desno i dole lijevo.
					//	matrica[i - 1][j - 1] = 'x';

					//// dole desno
					//if (i < visina - 1 and j < sirina - 1 and matrica[i + 1][j + 1] == '.')
					//	matrica[i + 1][j + 1] = 'x';

					//// dole lijevo
					//if (i < visina - 1 and j > 0 and matrica[i + 1][j - 1] == '.')
					//	matrica[i + 1][j - 1] = 'x';
				}
			}
		}

		int redPocetka = 0;
		int kolonaPocetka = 0;	// ovdje cemo spasiti 'i' i 'j' indekse lokacije od koje pocinjemo traziti najkraci put, tj. od lokacije
								// na kojoj se nalazi 'M'

		std::map <std::pair<int, int>, bool> mozePosjetiti;		// std::map, built in funkcija, u "<>" zagrade pisemo dvija tipa, prvi tip (u mom slucaju std::pair)
		// oznacava tip kljuca, a drugi tip (u mom slucaju bool) oznacava tip valute koja se nalazi na lokaciji kljuca.
		// std::map je ordered, takodjer imamo std::unordered_map (hash map funkcija), std::set i std::unordered_set koji imaju samo kljuc, nemaju valutu,
		// mogao sam njih koristiti umjesto mape, i ukoliko unutar seta imam kljuc, to je ekvivalent trenutnom false, a ukoliko nema kljuca to je ekvivalent
		// trenutnom true. Provjera kljuca se u C++20 moze provjeriti funkcijom .contains(x), a u ranijim sa .count(x), dodavanje u set se vrsi preko .insert(x)

		// u mom slucaju, kljuc je std::pair, sto je built in funkcija koja nam omogucava da spojomo dva razlicita ili ista tipa podatka, u mom slucaju oba su int

		// naravno mogli smo ovo isto uraditi preko dinamicki alocirane matrice ili preko vektorske implementacije matrice,
		// ali meni licno ovo ljepse izgleda i manje koda zauzima
		for (int i = 0; i < visina; i++)
		{
			for (int j = 0; j < sirina; j++)
			{
				if (matrica[i][j] == 'M')
				{
					redPocetka = i;										// ovu matricu koristimo da nadjemo pocetak, tj. 'M'
					kolonaPocetka = j;
					mozePosjetiti[std::make_pair(i, j)] = false;		//gdje god imamo tacku ili 'K' stavicemo da nasa
				}														// mapa bude true, a gdje god imamo bilo koji drugi simbol
				else if (matrica[i][j] == '.' or matrica[i][j] == 'K')	// stavljamo false, zato sto jedimo smijemo posjetiti lokacije
					mozePosjetiti[std::make_pair(i, j)] = true;			// simbola tacke ili 'K'
				else
					mozePosjetiti[std::make_pair(i, j)] = false;
			}
		}

		std::queue <CvorGrafa> redCvorova;					// std::queue, podatkovna struktura tipa FIFO, first in first out, zove se queue
		CvorGrafa pocetak(redPocetka, kolonaPocetka, 0);	// zato sto podsjeca na red u pravom zivotu, osoba koja je prva usla u njega
		redCvorova.push(pocetak);							// jeste ona koja prva izadje. Prednost queue-a je ta sto je dodavanje u 
		CvorGrafa iter;										// queue uvijek O(1) operacija, kao i izbacivanje iz queue-a.
		int rezultat = -1;									// vektor je O(1) ukoliko ima dovoljno alociranog mjesta, u suprotnom je O(n)
															// zato sto mora kopirati sve elemente na drugu lokaciju u memoriji gdje ce imati
															// mjesta da doda novi element.
		// osim queue-a, u kodu iznad pravimo novi objekat strukture CvorGrafa, koji se zove pocetak, to je ustvari lokacija simbola 'M' u matrici
		// taj pocetak stavljamo u queue, i deklarisemo novi cvor koji cemo koristiti da iteriramo kroz matricu, odnosno graf.

		// na 148. liniji smo inicijalizirali rezultat na -1. Ukoliko ne nadjemo nikakav put od M do K, onda cemo vratiti -1, tj gresku,
		// a ukoliko nadjemo put, onda cemo duzinu tog puta dodati na rezultat, tj. dodati cemo broj tacaka koje smo presli da dodjemo
		// do rezultata, i takodjer cemo dodati jedan broj kada dodjemo do slova 'K', ova jedinica ce nadoknaditi pocetni broj rezultata (-1)

		// Ovaj algoritam se zove breadth first search, eng. breadth znaci sirina. Dakle ovaj algoritam pretrazuje graf/drvo u sirinu,
		// za razliku od depth first search-a, koji ide u dubinu. Breadth first search (skracenica BFS) prvo analizira sve elemente oko
		// naseg korijena ili pocetka, onda ide ulazi u prvi element koji je analizirao, analizira njegove konekcije, ako ne nadje rezultat,
		// vraca se, zbog ovog vracanja nam je potreban red, prvi koji je usao u red ce prvi izaci iz njeg, sto znaci da ako korijen ima 5
		// konekcija, on ce prvo analizirati tih 5 konekcija, pa onda tek konekcije tih konekcija, do rezultata.
		// (ukoliko je npr binarno drvo BFS prvo analizira lijevu granu, pa desnu, pa konekcije lijeve, pa desne, pa konekcije konekcija lijeve itd.)

		while (redCvorova.size() > 0)				// dokle god nas red ima elemenata ponavljamo petlju, ako nestane elemenata u redu
		{											// a nismo nasli rezultat, znaci da ne postoji put od 'M' do 'K'
			iter = redCvorova.front();	// ovdje uzimamo element na pocetku reda, dakle onaj koji je najstariji u redu
			redCvorova.pop();			// ovdje uklanjamo taj element koji smo iznad uzeli
			// u nekim jezicima, kao sto su javascript, ova kombinacija .front() i .pop() se moze zamijeniti sa .dequeue(), a .push() sa .enqueue()

			if (matrica[iter.i][iter.j] == 'K')					// ako je na indeksima posmatranog elementa 'K', onda smo dosli do kraja
			{													// vracamo rezultat + udaljenost 'K' od pocetka.
				rezultat += iter.udaljenost;					// rezultat + udaljenost je detaljnije objasnjena na liniji gdje sam deklarisao rezultat
				break;
			}

			// gore																	// pomocu 'iter.i > 0' provjeravamo da li je
			if (iter.i > 0 && mozePosjetiti[std::make_pair(iter.i - 1, iter.j)])	// mjesto iznad opste dio nase matrice. Ako jest
			{																		// provjeravamo da li mozemo posjetiti tu lokaciju
				CvorGrafa noviCvor(iter.i - 1, iter.j, iter.udaljenost + 1);		// ako mozemo, onda pravimo novi cvor koji
				redCvorova.push(noviCvor);											// inicijaliziramo njegovim indeksima (i - 1) zato sto je to lokacija
				mozePosjetiti[std::make_pair(iter.i - 1, iter.j)] = false;			// indeksa iznad posmatranog cvora, a to je lokacija u koju zelimo
			}																		// otici ukoliko je if ispunjen.
			// buduci da smo posjetili tu lokaciju, ne zelimo je vise podjetiti, tako da bool 'mozePosjetiti' za tu lokaciju setamo na false

			// dole													// kod iznad je sluzio da odemo na lokacije iznad posmatrane, ovaj kod, vrlo slicno
			if (iter.i < visina - 1 && mozePosjetiti[std::make_pair(iter.i + 1, iter.j)])		// sluzi da odemo na lokacije ispod posmatrane
			{																					// ukoliko one zadovoljavaju uslove if-a
				CvorGrafa noviCvor(iter.i + 1, iter.j, iter.udaljenost + 1);
				redCvorova.push(noviCvor);
				mozePosjetiti[std::make_pair(iter.i + 1, iter.j)] = false;
			}

			// desno
			if (iter.j < sirina - 1 && mozePosjetiti[std::make_pair(iter.i, iter.j + 1)])
			{
				CvorGrafa noviCvor(iter.i, iter.j + 1, iter.udaljenost + 1);
				redCvorova.push(noviCvor);
				mozePosjetiti[std::make_pair(iter.i, iter.j + 1)] = false;
			}

			// lijevo
			if (iter.j > 0 && mozePosjetiti[std::make_pair(iter.i, iter.j - 1)])
			{
				CvorGrafa noviCvor(iter.i, iter.j - 1, iter.udaljenost + 1);
				redCvorova.push(noviCvor);
				mozePosjetiti[std::make_pair(iter.i, iter.j - 1)] = false;
			}
		}


		// Algoritam iznad (BFS), (kao i DFS) ima time complexity O(n), tj. linearno vrijeme zato sto u najgorem slucaju mora posjetiti svaki dvor jednom.
		// BFS se moze implementirati iterativno (kako sam ja) i rekurzivno, dok se DFS u vecini slucajeva implementira rekurzivno
		// BFS trosi vise memorije zato sto moramo konstantno pratiti cvorove koje nismo posjetili a koji su na istom nivou kao posmatrani cvor
		// DFS trosi manje memorije od BFS, ali moramo voditi racuna o stack overflow-u. (zbog rekurzivne implementacije, buduci da se pozivi funkcija
		// dodaju na stack)
		// BFS: O(n) space complexity, gdje je n broj cvorova. DFS: O(n) space complexity, gdje je n najdublji cvor (najvise memorije ce se zauzeti dok
		// se dodje do najdubljeg cvora)

		std::ofstream file("Mile.out.txt");	// kada ofstream otvori file, on automatski obrise njegov sadrzaj
		file << rezultat;					// u taj file upisujemo nas rezultat
		file.close();						// zatvaramo file
		std::cout << rezultat;				// ispis rezultata (iako nije trazeno lakse je u konzoli pogledati da li je rezultat tacan nego ici u .txt)
	}
	else
		std::cout << "\n\n\tDatoteka nije pronadjena!";
	std::cout << "\n\n\n";
}
// ranije sam spomenuo da se BFS moze rekurzivno implementirati, evo kako izgleda rekurzivna implementacija BFS za drvo:

//std::vector <int> BreadthFirstSearchRecursive(std::queue <Node*> queue, std::vector <int> result = {})
//{
//	if (queue.empty())										// samo zadace pisem na bosanskom, tako da sam ostavio ovu implementaciju na engleskom
//		return result;										// ovaj BFS pretrazuje drvo brojeva, vraca vektor svih brojeva
//
//	Node* current = queue.front();
//	queue.pop();
//	result.push_back(current->num);
//
//	if (current->left)
//		queue.push(current->left);
//
//	if (current->right)
//		queue.push(current->right);
//
//	return BreadthFirstSearchRecursive(queue, result);
//}