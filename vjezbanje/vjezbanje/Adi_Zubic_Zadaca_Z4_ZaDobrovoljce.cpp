#include "pch.h"

//Napisati rekurzivnu funkciju kojom se izracunava najmanji zajednicki sadrzalac dva prirodna broja tako
//sto se maksimumu dva broja dodaje 1 u svakom rekurzivnom pozivu.


		// PRVI NACIN
int temp(int a, int b, int maks)
{
	if (maks % a == 0 && maks % b == 0)		// ukoliko je max dijeljiv sa a i b vracamo maks, u suprotnom nastavljamo rekurziju
		return maks;						// sa a, b i maks + 1

	return temp(a, b, maks + 1);
}

int najveciZajednickiSadrzalac(int a, int b)	// ovu funkciju sam koristio samo da nadjem maks izmedju a i b.
{
	int maks = std::max(a, b);
												
	return temp(a, b, maks);					// naravno mogli smo uraditi trazeno sa samo jednom funkcijom,
}												// primjer ispod:

		// DRUGI NACIN
int najveciZajednickiSadrzalac2(int a, int b, int maks = 0, bool reset = true)	// kada je bool reset true, funkcija reseta maks
{														// bool reset je implicitno true, false je ako eksplicitno kazemo da ce biti false
	if (reset)											// eksplicitno cemo kazati da bude false u rekurzivnim pozivima, posto zelimo da
		maks = std::max(a, b);							// se maks povecava, ne zelimo da se reseta nakon svake rekurzije, to bi dovelo
														// do beskonacne petlje (rekurzije).
	if (maks % a == 0 && maks % b == 0)
		return maks;

	return najveciZajednickiSadrzalac2(a, b, maks + 1, false);
}

void Adi_Zubic_Zadaca_Z4_ZaDobrovoljce()
{
	int a, b;
	
	std::cout << "\n\n\tUnesite prvi broj: ";
	std::cin >> a;	
	
	std::cout << "\n\tUnesite drugi broj: ";
	std::cin >> b;

	if (a == 0 && b == 0)	// ako se unese broj 2 onda se program crashuje posto se ne moze dijeliti sa nulom.
	{						// tako da ovaj if samo igra ulogu preventisanja crasha.
		std::cout << "\n\n\tNajveci zajednicki sadrzalac: 0\n\n\n";
	}

	std::cout << "\n\n\tNajveci zajednicki sadrzalac koristeci prvu funkciju: " << najveciZajednickiSadrzalac(a, b);
	std::cout << "\n\n\tNajveci zajednicki sadrzalac koristeci drugu funkciju: " << najveciZajednickiSadrzalac2(a, b) << "\n\n\n";
}