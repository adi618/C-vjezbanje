#include "pch.h"


//Odrediti broj minimalnih pokrivajucih stabala datog povezanog tezinskog grafa u kome se ni jedna tezina grane ne
//ponavlja vise od 4 puta.
//Ulaz:
//(Ulazni podaci se nalaze u datoteci stabla.in) U prvom redu ulaza su zapisani brojevi N i M(0 < N, M < 5x104
//), broj
//cvorova i broj grana datog grafa.U svakom od narednih M redova zapisana su tri cjela broja A, B i W(0 , A, B < N + 1, 0 <
//	W + 1 < 230), koji oznacavaju da izmedu cvorova A i B postoji grana tezine W.
//	Izlaz :
//	(Izlazne podatke upisati u datoteku stabla.out) U izlaznu datoteku ispisati ostatak trazenog broja minimalnih
//	pokrivajucih stabala datog grafa koji se dobija pri djeljenju sa 1000003.
//Primjer 1:
//stabla.in stabla.out
//3 4
//1 2 6
//1 2 6
//2 3 6
//3 1 6
//3 3 8
//
//5
//
//Objasnjenje.
//Sve grane su iste tezine, izmedu cvorova 1 i 2 postoje dvije grane, a postoji i grana kojoj su oba kraja u cvoru 3.
//
//Primjer 2:
//stabla.in
//
//stabla.o
//ut
//
//6 8
//1 2 1
//2 3 2
//3 4 3
//4 5 3
//5 6 2
//6 1 1
//2 6 1
//3 5 3


class Edge
{
	friend class Graph;
private:
	int vertex1, vertex2;
	int weight;					// klasa u koju cu spasavat informacije grana, vertex1 je izvor grane, vertex2 je destinacija, ali, posto je
	int index;					// undirected graph, to dvoje je interchangable
	// posto cemo sortirati ove grane po njihovoj tezini, index nam sluzi da pratimo njihovu orginalnu poziciju
public:
	Edge(int x, int y, int w, int i) : vertex1(x), vertex2(y), weight(w), index(i) {}
};		// konstruktor za inicijalizaciju grane


class DisjointSet
{
private:
	std::vector <int> sets;					// Ovo je disjoint set (takodjer se zove union-find) data struktura
	std::vector <int> rank;					// Set se moze prevesti u skup, a disjoint bi znacilo da nije sastavljen, sto se odnosi
											// samo na trenutak kada je tek inicijaliziran, kasnije cemo ga spajati u jedan
public:										// Takodjer se zove union-find struktura zato sto su to dvije osnovne funkcije disjoint seta: union i find
	DisjointSet(int numOfVertices)			// funkcija union se kod mene zove merge zato sto je union keyword u c++u. Ona sluzi da spoji dva seta (cvorova u ovom slucaju)
	{										// find sluzi da nadjemo kojem setu pripada koji cvor
		sets.resize(numOfVertices);			// Disjoint set se koristi za detekciju ciklusa u grafu, u mom slucaju, naci cu da li je ciklus prisutan koristeci
		rank.resize(numOfVertices);			// find funkciju, ako jeste necu spojiti te setove (setove cvorova), a ako to spajanje nece rezultirati u ciklusu,
		for (int i = 0; i < numOfVertices; i++)		// spojit cu ih koristeci union funkciju (kod mene se zove merge)
		{
			sets[i] = i;	
		}
	}

	void merge(int vertex1, int vertex2)
	{
		int x = find(vertex1);				// union funkcija, kao parametar je proslijedjen index prvog i drugog cvora koje zelimo spojiti
		int y = find(vertex2);				// u int x spasavamo index seta u kojem se nalazi prvi cvor, a u int y lokaciju drugog cvora
											// Napomena: U ovu funkciju se jedino moze uci ako data dva cvora ne pripadaju istom setu, ovo je zagarantovano
		if (rank[x] > rank[y])				// u ifu koji se nalazi u funkciji Kruskal()
		{
			sets[y] = x;				// ova implementacija disjoint set union funkcije se zove union by rank funkcija
		}								// rank prati ko je glavni cvor kojeg seta. Kao sto smo rekli, x je set prvog cvora, a y drugog, ako su rankovi ta dva cvora jednaki
		else if (rank[x] < rank[y])		// to znaci da oba seta imaju isti broj elemenata. U tom slucaju cu samo rank drugog elementa povecat,
		{								// i set pozicije x pretvorit u y. Ovim pretvaranjem sam oznacio da se x u istom setu kao y, a iteriranjem rank[y] sam povecao rank
			sets[x] = y;				// rank y elementa, i time sam oznacio da je on glavni element seta nastalog spajanjem seta x i seta y
		}							// Ako imamo 2 seta koja sadrze po dva cvora, to znaci da oba seta imaju jedan element ranka 0, a drugi element ranka 1, koji 
		else						// je glavni element tog seta. Spajanjem ova dva, dobit cemo set ciji je glavni element onaj element koji je bio glavni element
		{							// drugog seta, i njegov rank ce se povecati na 2. Takodjer, moguce je analizirati veliki graf a da samo jedna pozicija ranka
			sets[x] = y;			// bude iterirana. To se moze ostvariti tako sto ce se svaka grana dodavati na prvi set koji se napravi, tako da cemo kroz cijeli
			rank[y]++;				// program proci nadodavajuci individualne cvorove na vec postojeci set, i time ce uvijek biti jedan glavni element.
		}	// x i y u dvije linije iznad ove se mogu zamijeniti, rezulat ostaje isti
	}	// objasnjenje prvog i drogo ifa: u prvom ifu, x je glavniji element svog seta od y, tako da sets[y] postaje x, sto znaci da, spajanjem u novi set,
		// x ostaje glavni element, dok se y spaja na njeg. Naravno spajanje y na x znaci da svi cvorovi seta y postaju dio seta x, gdje je glavni element seta x
		// glavni element novonastalog seta. Drugi if je isti kao prvi samo obrnut.

	int find(int vertex)				// Glavni element o kojem sam dosta pricao u komentarima iznad je element koji vraca funkcija find za odredjeni set
	{
		while (vertex != sets[vertex])	// Funkcija prima redni broj cvora (cvor == vertex), ako je cvor isti kao i set pozicije cvor, onda taj broj predstavlja
		{								// glavni element svog seta (ako je sam u setu opet je glavni element).
			vertex = sets[vertex];		// Ako recimo mergamo 5 i 1, s tim da je 1 postane glavni element, i zelimo da nadjemo kojem elementu cvor 5 pripada:
		}								// 5 nije jednako sets[5], tako da sets[5] postaje 1, sljedeca provjera ce biti da li je 1 jednako sets[1], sto je true,
										// tako da vracamo broj 1, a jedan je naravno glavni element tog seta.
		return vertex;		// unutar Kruskalovog algoritma imamo provjeru da li dva razlicita cvora pripadaju istom setu, ako ta dva cvora pripadaju
	}						// istom elementu, onda ce glavni element ta dva seta biti isti, dakle zakljucujemo da pripadaju istom setu.
};


class Graph
{
private:
	std::vector <int> vertices;
	std::vector <Edge> edges;
	int numOfVertices;
	int numOfEdges;

	//		O Kruskalovom algoritmu:
	// Ideja je da sortiramo grane po tezini, rezultat ce naravno biti da je najmanja grana prva, sve ostale su vece.
	// Uzimamo redom grane koje nece formirati ciklus, formiranje ciklusa pratimo preko disjoint set strukture.
	// Disjoint set struktura je, u pocetku, sacinjena od N broja indeksa koji predtavljaju indekse cvorova, gdje je N ukupan broj cvorova.
	// Kada uzmemo granu, ukoliko spajanje njenih setova cvorova nece napraviti ciklus, spojit cemo ta dva seta. npr ako u strukturi imamo 4 cvora
	// cvor 1, 2, 3 i 4, oni su, u pocetku, svi individualni cvorovi, nakon spajanja prve grane (neka bude izmedju 2 i 4) dobicemo sljedeci rezultat:
	// cvor 2 i 4 ce biti spojeni u jedan set, i preostala dva cvora (seta) ce biti 1 i 3. Neka je sljedeca grana izmedju 1 i 2: cvor 1, 2, 4 su spojeni, cvor 3 je sam.
	// sljedeca grana ako je izmedju 1 i 2, mozemo primjetiti da cemo dobiti ciklus spajanjem tih cvorova, zato sto se oni nalaze u istom setu, tako da
	// preskacemo ovu granu, to radimo dokle god ne spojimo sve setove
	// Napomena: setovi su skupovi cvorova

public:
	int Kruskal()
	{
		for (int i = 0; i < numOfEdges; i++)
		{
			for (int j = 0; j < numOfEdges - 1; j++)
			{
				if (edges[j].weight > edges[j + 1].weight)			// prvi korak Kruskalovog algoritma je da su grane sortirane po njihovoj tezini
					std::swap(edges[j], edges[j + 1]);		// bubble sort za sortiranje, u slucaju vecih inputa, ovo je prva stvar koja bi se trebala
			}										// promijeniti (u merge sort/quick sort ili, posto sortiramo integere tezina, mozda radix ili counting sort?)
		}

		DisjointSet* Dset = new DisjointSet(numOfVertices);	// inicijaliziramo disjoint set(Dset) sa brojem cvorova, Dset je objasnjen u komentarima pored njegove klase
		int vertex1, vertex2, weight;
		int joined = 0;
		int rezult = 0;

		std::cout << "\n\n\tRedoslijed cvorova koji je Kruskalog algoritam uzeo:\n";

		for (int i = 0; i < numOfEdges; i++)		// petlja koja pretrazuje sve grane, tako da ide do broja grana
		{
			vertex1 = edges[i].vertex1;							// spasavamo informacije posmatranog cvora u temp varijable, vertex1, vertex2, weight
			vertex2 = edges[i].vertex2;
			weight = edges[i].weight;

			if (Dset->find(vertex1) != Dset->find(vertex2))		// Ukoliko ta dva cvora nisu u istom Dsetu, spajamo ih
			{
				rezult += edges[i].weight;		// posto smo ih spojili, to znaci da ce njihova grana biti dio finalnog rezultata, tako da tezinu te grane
				std::cout << "\t\t   " << edges[i].index + 1 << "\n\t\t   |\n\t\t   V\n";		// dodajemo na varijablu rezult.
				joined++;		// varijablu joined povecavamo zato sto smo spojili dva cvora
				Dset->merge(vertex1, vertex2);	// ovo je funkcija koja spaja te disjoint setove, objasnjena kod disjoint set klase
			}	// preko indexa pratimo orginalnu poziciju cvorova, bez njeg bi izgubili tu informaciju pri sortiranju grana
			if (joined == numOfVertices)	// kada varijabla joined bude jednaka broju cvorova, to znaci da smo spojili sve cvorove te mozemo prekinuti petlju
				break;
		}
		std::cout << "\t\tnullptr";
		std::cout << "\n\n\tSuma tezina grana ovog minimalnog pokrivajuceg drveta: " << rezult;

		delete Dset;

		return rezult;
	}

	void input(std::ifstream& file)
	{
		int vertex1;			// funkcija za input, kasnije sam dodao i cout-anje da mozemo pratiti sta se desava u programu
		int vertex2;
		int weight;

		file >> numOfVertices;
		file >> numOfEdges;

		std::cout << "\n\n\tBroj cvorova grafa: " << numOfVertices;
		std::cout << "\n\tBroj grana grafa: " << numOfEdges << "\n";

		for (int i = 0; i < numOfEdges; i++)
		{
			file >> vertex1;
			file >> vertex2;
			file >> weight;

			std::cout << "\n\tGrana " << i + 1 << ":\tCvor " << vertex1 << " <--> " << vertex2 << ", tezina: " << weight;

			vertices.push_back(vertex1 - 1);		// u nas vektor koji prati cvorove saljemo cvor - 1, da bi indeksi isli od 0, ovo ne mora iti ovako, mozemo
			edges.push_back(Edge(vertex1 - 1, vertex2 - 1, weight, i));		// ovdje obrisati -1, ali bi onda morali u disjoint set kontruktoru promijeniti
		}																	// inicijalizaciju da pocinje od indeksa 1. Ovaj nacin je, po mom misljenju, dosta prakticniji
	}
};

		// pisano na engleskom posto prijevodi za termine kao sto su disjoint set nisu bas prakticni (a i generalno ljepse izgleda)
void Adi_Zubic_Zadaca_6_Z15()				// primjeri ovog zadatka sigurno imaju greske, kaze: "U svakom od narednih M redova zapisana su tri cjela broja"
{											// u primjeru 1, dati M je jednak 4, dok je ispod napisano 5 grana, drugi primjer je u redu, M je 8 i 8 grana je napisano
	std::ifstream file("stabla.in.txt");	// takodjer pretpostavljam da su rezultati pogresni, posto, ako se zadatak radi preko Kruskalovog algoritma i disjoint
											// setova, mora da se trazi minimum spanning tree, a minimum spanning tree ova dva primjera je 12 i 9, prvi mora biti
	if (file.is_open())						// 12 zato sto su sve grane izmedju cvorova jednake 6, da bi povezali sve cvorove potrebne su nam dvije grane, tako da 12
	{
		Graph* graph = new Graph;		// dinamicki alocirano u slucaju da je graf prevelik za steka

		graph->input(file);

		int rezultat = graph->Kruskal();

		delete graph;

		file.close();

		std::ofstream file("stabla.out.txt");

		file << rezultat;
	}
	else
		std::cout << "\n\n\tDatoteka nije pronadjena!";
	std::cout << "\n\n\n\n";
}