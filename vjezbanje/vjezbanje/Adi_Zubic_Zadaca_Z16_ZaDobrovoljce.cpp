#include "pch.h"


//Laa - Laa i Po igraju igru.Laa - Laa zamisli broj X, a Po mora naci najveci neparni broj Y koji dijeli X.Kako je Laa - Laa
//ipak nesto starija, ona malo bolje poznaje svijet brojki pa zamislja prevelike brojeve, ali zato Po ima dobre starije
//prijatelje koji ce mu pomoci!!!
//Ulazni podaci
//Putem tastature unosi se jedan prirodan broj X s maksimalno 9 cifara.
//Izlazni podaci
//Na zaslon je potrebno ispisati broj Y, odnosno najveci neparni djelitelj broja X.


int najveciNeparniDijelitelj(int n)
{
	if (n % 2 == 1)		// ako je uneseni broj neparan, vracamo taj broj posto je dijeljiv sam sa sobom.
		return n;		// naravno mozemo samo obrisati ovaj if ako zelimo da program vrati najveci neparni dijelitelj
						// koji nije taj isti broj.
	//for (int i = n / 2; i > 0; i -= 2)		// prvobitno sam uradio ovako zadatak, jednostavna petlja koja samo vrati
	//{											// prvi broj koji dijeli n.
	//	if (n % i == 0)
	//	{
	//		std::cout << i << "\n\n\n";		// ova petlja pocinje od n polovina zato sto brojevi veci od n / 2 sigurno ne
	//		break;							// mogu podijeliti n, i onda smanjuje i za 2 dok ne dodje do trazenog broja.
	//	}									// Petlja ispod dijeli broj sa 2 dok ne dobije broj koji je neparan.
	//}

	while (true)		
	{
		n /= 2;
		if (n % 2 == 1 || n == 1)
			return n;
	}
}


void Adi_Zubic_Zadaca_Z16_ZaDobrovoljce()
{
	long long n;	// iako int ima dovoljno mjesta da spasi 9 cifara, opet sam stavio long long ukoliko korisnik slucajno unese broj
	std::cout << "\n\n\tUnesite broj sa do 10 cifara: ";	// veci od 2.5 milijardi
	while (true)
	{
		std::cin >> n;
		if (n < 1000000000 && n > 0)
			break;
		std::cout << "\n\t\tNekorektan unos, unesite broj sa barem 1 cifrom i max 10 cifara: ";
	}

	std::cout << "\n\n\tNajveci neparni broj koji dijeli uneseni broj jeste: " << najveciNeparniDijelitelj(n) << "\n\n";
}