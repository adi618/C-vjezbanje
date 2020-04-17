#include "pch.h"



using namespace std;

int f1(int a, int* b)
{
	int c = 0;						//u funkciji se deklarise integer c, i inicijalizira na broj 2
	a = 2;							//a je poslano u funkciju po valuti, sto znaci da je napravljena kopija varijable a unutar funkcije
		//njena vrijednost ovdje postaje 2
	* b = 3;						//b je poslana u funkciji po pointeru, sto znaci da su promjene te varijable permanentne
		//b postaje 3 unutar i funkcije i ostatka programa
	c = a + 2;						//c postaje a (2) + 2 tj. 4
	return c;						//returnamo c, tj. 4
	}

int f2(int* p1)
{
	int a;							//deklarisemo a
	p1 = p1 + 2;					//p1 je pointer na memorijsku lokaciju, dodajemo 8 byta na tu memorijsku lokaciju i spasavamo u p1
	a = (*p1) + 2;					//a postaje broj memorijske lokacije p1, na taj broj dodajemo broj 2
	return a;						//vracamo a
		//ukoliko smo u funkciju poslali (&B[0][0] + 1) onda je povratna varijabla 9
		//mem. lokacija prvog elementa => + 4 byta => + 8 byta => 4. lokacija matric B, tj B[1][1], tj broj 7, 7 + 2 = 9

		//ukoliko smo u funkciju poslali (A + 1) onda je povratna varijabla 10
		//A[0] => + 4 byta => + 8 byta => A[3] tj. broj 8, 8 + 2 = 10
	}

void f3(char* p)
{
	* p = '?';						//pokazivac p je char tipa i pokazuje na prvu memorijsku lokaciju char niza rijeka, tj. slovo 'M', koje mjenjamo u '?'
	p++;							//buduci da je char tipa, a char je 1 byte, operator ++ ce dodati 1 byte na mem. lokaciju spasenu u p1
	* p = '?';						//rezultat je druga mem. lokacija, sto je slovo 'i', njeg mijenjamu u '?'
	}

void Adi_Zubic_Zadaca_2()
{
	int A[5] = { 2,4,6,8,10 };		//niz A se deklarise i inicijalizira
	int B[2][2] = { 1,3,5,7 };		//matrica B se deklarise i inicijalizira
	char rijeka[] = "Miljacka";		//niz tipa char rijeka se deklarise i inicijalizira
	int a = 1, b = 1, c = 0;		//integeri a, b i c se deklarisu, a = 1, b = 1, c = 0
	int* p1 = &B[0][0];				//pokazivac p1 se deklarise, memorijska lokacija prvog elementa matrice B se spasava u taj pokazivac
	c = *(A + 1) + (*(p1 + 2));		//(A + 1) znaci da se na memorijsku lokaciju prvog elementa niza A dodaje integer 1
		//niz je tipa integer, integer je 4 byta, tako da su u memoriji razmaci izmedju elemenata niza 4 byta
		//memorijska lokacija prvog elementa niza A + 4 byta je memorijska lokacija drugog elementa niza A, ispred zagrade se nalazi * koja
		//kaze kompajleru da ode na tu memorijsku lokaciju i uzme valutu koja se na njoj nalazi, u ovom slucaju broj 4
		//p1 je pokazivac na prvi element matrice B, dodavanjem int 2 (8 byta) dobijemo memorijsku lokaciju B[1][0]
		//na toj lokaciji se nalazi broj 5, zbir ta dva broja je 9, broj 9 spasavamo u varijablu c
	cout << c;						//ispisujemo broj 9
	c = f1(a, &b);					//varijabla c postaje return vrijednost funkcije f1, u koju saljemo a po valuti, i b po pointeru
	cout << a << b << c;			//ispisujemo a, b i c, tj: 1, 3, 4
	c = f2(&B[0][0] + 1);			//return vrijenost funkcije f2 dodjeljujemo varijabli c, u f2 saljemo memorijsku lokaciju drugog
		//elementa matrice B. objasnjenje: &B[0][0] je prvi element, 1 je integer (4 byta), prva lokacija matrice int tipa
		//plus 4 byta jeste druga lokacija.
	cout << c;						//ispisujemo broj 9
	c = f2(A + 1);					//c postaje return vrijednost f2, u f2 saljemo drugu memorijsku lokaciju niza A, rezultat je 10
	cout << c;						//ispisujemo broj 10
	f3(rijeka);						//funkcija f3 za char rijeka, rezultat: ??ljacka (objasnjenje u komentarima pored funkcije F3)
	cout << rijeka;					//ispisujemo ??ljacka
}