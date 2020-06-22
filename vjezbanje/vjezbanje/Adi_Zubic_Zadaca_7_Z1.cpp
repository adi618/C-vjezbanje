#include "pch.h"


//Definirajte klasu “Robot” koja predstavlja zamisljenog robota koji moze da se krece
//kroz koordinatni sistem sa realnim koordinatama i koji moze da gleda u proizvoljnom
//pravcu.Klasa treba da ima sljedeci interfejs :
//void Postavi(double x, double y, double ugao);
//void IdiNaprijed(double pomak);
//void IdiNazad(double pomak);
//void OkreniSeNaijevo(double ugao);
//void OkreniSeNadesno(double ugao);
//double DajPozicijuX() const;
//double DajPozicijuY() const;
//double DajOrjentaciju() const;
//void Ispisi() const;
//Metoda “Postavi” postavlja robot na zadanu poziciju, i usmjerava ga da gleda pod
//zadanim uglom u odnosu na pozitivni smjer ose.Pri tome se ugao zadaje u stepenima
//(to vrijedi i za sve ostale metode u kojima se spominju uglovi).Metoda “IdiNaprijed”
//pomjera robota za zadani iznos dužine u smjeru u kojem robot trenutno gleda, dok
//metoda “IdiNazad” pomjera robota za zadani iznos duzine u smjeru suprotnom od
//smjera u kojem robot trenutno gleda.Metode “OkreniSeNalijevo” i
//“OkreniSeNadesno” obrcu robota za zadani iznos ugla(u stepenima) nalijevo odnosno
//nadesno(tj.u smjeru suprotnom od kazaljke na satu, odnosno u smjeru kazaljke na satu).
//Metode “DajPozicijuX”, “DajPozicijuY” i “DajOrjentaciju” treba da vrate tekucu
//poziciju odnosno ugao pod kojim gleda robot.Metoda “Ispisi” treba da ispiše podatke
//o poziciji i orjentaciji robota na nacin kao u sljedecem primjeru :
//Robot se nalazi na poziciji(3.42, –5.173) i gleda pod uglom 42.5 stepeni u odnosu na x
//osu.
//Napisanu klasu upotrijebite u programu u kojem ce korisnik moci da bira neku od
//dozvoljenih operacija sa robotom, a nakon svake izvršene operacije program treba da
//prikaze tekucu poziciju i orjentaciju(kratke metode dozvoljeno je implementirati
//	odmah unutar deklaracije klase).

const double PI = atan(1) * 4;		// PI se moze izracunati preko atan(1) * 4. Koristim ga u IdiNaprijed metodi

class Robot
{
private:
	double x, y;
	double ugaoPogleda;

public:
	Robot() : x(0), y(0), ugaoPogleda(0) {}		// constructor + initializer list

	void Postavi(double x, double y, double ugao)	// metoda za postavljanje vrijednosti
	{
		this->x = x;		// ukoliko class member ima isto ime kao i parametar (oba su x), mozemo koristiti 'this' da razlikujemo ta dva x-a
		this->y = y;		// this vraca pointer na objekt klase u kojem se metoda nalazi, this->x = x seta x tog objekta na x parametra
		this->ugaoPogleda = ugao;
	}

	void IdiNaprijed(double pomak)		// metoda za pomijeranje robota naprijed
	{
		x += pomak * cos(ugaoPogleda * PI / 180);		// funkcija cos prima radijane, tako da moramo izvrsiti konverziju iz stepeni u radijane
		y += pomak * sin(ugaoPogleda * PI / 180);		// ta konverzija je ugaoPogleda * PI / 180

		balansujUgao();
	}

	void IdiNazad(double pomak)		// metoda IdiNazad samo poziva metodu IdiNaprijed sa negativnom vrijednosti
	{
		IdiNaprijed(-pomak);
	}

	void OkreniSeNaijevo(double ugao)	// okretanje za odredjen ugao
	{
		ugaoPogleda += ugao;

		balansujUgao();
	}

	void OkreniSeNadesno(double ugao)
	{
		ugaoPogleda -= ugao;

		balansujUgao();
	}

	double DajPozicijuX() const
	{
		return x;
	}

	double DajPozicijuY() const
	{
		return y;
	}

	double DajOrjentaciju() const
	{
		return ugaoPogleda;
	}

	void Ispisi() const
	{
		std::cout << "\n\n\tRobot se nalazi na poziciji (" << x << ", " << y << ") i gleda pod uglom " << ugaoPogleda << " stepeni u odnosu na x osu.";
	}

	void balansujUgao()		// metoda koja balansuje ugao ako je veci od 360 stepeni ili manji od 0
	{
		while (ugaoPogleda > 360)
			ugaoPogleda -= 360;

		while (ugaoPogleda < 0)
			ugaoPogleda += 360;
	}
};

void unesiPomak(double& pomak)
{
	std::cout << "\n\t\tUnesite pomak: ";
	std::cin >> pomak;
}					// pomocne funkcije za unos

void unesiUgao(double& ugao)
{
	std::cout << "\n\t\tUnesite ugao: ";
	std::cin >> ugao;
}

void Adi_Zubic_Zadaca_7_Z1()
{
	Robot robot1;

	int odabir;
	double pomak1;
	double pomak2;
	double ugao;

	while (true)
	{
		system("cls");
		robot1.Ispisi();
		std::cout << "\n\n\t\t1 - Postavi"
			<< "\n\t\t2 - IdiNaprijed"
			<< "\n\t\t3 - IdiNazad"
			<< "\n\t\t4 - OkreniSeNaijevo"
			<< "\n\t\t5 - OkreniSeNadesno"
			<< "\n\t\t6 - DajPozicijuX"
			<< "\n\t\t7 - DajPozicijuY"
			<< "\n\t\t8 - DajOrjentaciju"
			<< "\n\t\t9 - Ispisi"
			<< "\n\t\t10 - Exit"
			<< "\n\n\t\tOdabir: ";

		std::cin >> odabir;

		if (odabir == 1)
		{
			unesiPomak(pomak1);
			unesiPomak(pomak2);
			unesiUgao(ugao);
			robot1.Postavi(pomak1, pomak2, ugao);
		}
		else if (odabir == 2)
		{
			unesiPomak(pomak1);
			robot1.IdiNaprijed(pomak1);
		}
		else if (odabir == 3)
		{
			unesiPomak(pomak1);
			robot1.IdiNazad(pomak1);
		}
		else if (odabir == 4)
		{
			unesiUgao(ugao);
			robot1.OkreniSeNaijevo(ugao);
		}
		else if (odabir == 5)
		{
			unesiUgao(ugao);
			robot1.OkreniSeNadesno(ugao);
		}
		else if (odabir == 6)
		{
			std::cout << "\n\tPozicija X: " << robot1.DajPozicijuX();
		}
		else if (odabir == 7)
		{
			std::cout << "\n\tPozicija Y: " << robot1.DajPozicijuY();
		}
		else if (odabir == 8)
		{
			std::cout << "\n\tUgao pogleda: " << robot1.DajOrjentaciju();
		}
		else if (odabir == 9)
		{
			robot1.Ispisi();
		}
		else if (odabir == 10)
		{
			return;
		}
		else
		{
			std::cout << "\n\t\tNekorektan unos!";
		}
		std::cout << "\n\n\t\t";
		system("pause");
	}
}