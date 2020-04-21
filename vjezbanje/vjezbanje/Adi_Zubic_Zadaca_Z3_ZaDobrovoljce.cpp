#include "pch.h"

//Napisati rekurzivnu funkciju koja prikazuje dekadne cifre datog cjelog broja.Napisati rekurzivnu
//funkciju koja prikazuje dekadne cifre datog cjelog broja u obrnutom poretku.

 
void ispisiDekadneCifreBroja(int n)         // Ukoliko unesemo broj 123, funkcija se ponavlja 3 puta prije returnanja. Prvi put broj 123
{                                           // ulazi u funkciju, pa 12, pa 1, pa 0. 0 naravno samo returna, tako da se vracamo na funkciju
    if (n == 0)                             // u koju je bio poslan broj 1. 1 % 10 je 1, ispisujemo 1, nakon toga se nastavlja funkcija
        return;                             // u koju smo poslali broj 12, ispisuje se broj 2 (12 % 10), i za kraj se nastavlja 
    ispisiDekadneCifreBroja(n / 10);        // funkcija koju smo prvobitno pozvali, tj. ona u koju smo poslali broj 123, i ispisuje se broj 3.
    std::cout << n % 10 << "  ";
}

void ispisiDekadneCifreBrojaObrnuto(int n)  // Ova rekurzija je malo jednostavnija od one iznad, ispisujemo n % 10, sto bi bila zadnja cifra,
{                                           // zatim dijelimo n na 10 i ponovo pozivano funkciju, ispisujemo predzadnju cifru. Ako je 
    if (n == 0)                             // prvobitno uneseni broj 123, onda bi ta cifra bila 2, i nakon jos jedne rekurzije ispisujemo 1.
        return;
    std::cout << n % 10 << "  ";
    ispisiDekadneCifreBrojaObrnuto(n / 10);
}


void Adi_Zubic_Zadaca_Z3_ZaDobrovoljce()
{
    int n;
    std::cout << "\n\n\tUnesite broj: ";
    std::cin >> n;


    std::cout << "\n\n\tDekadne cifre unesenog broja:  ";
    ispisiDekadneCifreBroja(n);

    std::cout << "\n\n\tObrnute dekadne cifre unesenog broja:  ";
    ispisiDekadneCifreBrojaObrnuto(n);

    std::cout << "\n\n";
}
