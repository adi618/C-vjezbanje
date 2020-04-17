#include "pch.h"



using namespace std;

struct student
{
	char ime[10];
	char prezime[15];
	int predmet;
	int ocjena;
} studenti[100];

void Adi_Zubic_Zadaca_1()
{
	int n;
	cout << "\n\n\tUnesite koliko zelite studenata unijeti: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "\n\tMolimo unesite podatke " << i + 1 << " studenta: ";

		cout << "\n\n\t\tIme: ";
		cin >> studenti[i].ime;

		cout << "\t\tPrezime: ";
		cin >> studenti[i].prezime;

		cout << "\t\tPredmet: ";
		cin >> studenti[i].predmet;
		while (studenti[i].predmet < 1 || studenti[i].predmet > 10)
		{
			cout << "\t\t\tGreska: Predmet ne postoji, molimo pokusajte ponovo:";
			cin >> studenti[i].predmet;
		}

		cout << "\t\tOcjena: ";
		cin >> studenti[i].ocjena;
		while (studenti[i].ocjena < 5 || studenti[i].ocjena > 10)
		{
			cout << "\t\t\tGreska: Ocjena ne postoji, molimo pokusajte ponovo:";
			cin >> studenti[i].ocjena;
		}
	}

	cout << "\n\n\n\tUneseni studenti: \n";
	for (int i = 0; i < n; i++) {
		cout << "\n\t\t" << studenti[i].ime
			<< setw(40) << studenti[i].prezime
			<< setw(40) << studenti[i].predmet
			<< setw(7) << studenti[i].ocjena;
	}
	cout << "\n\n\n";

	float suma_ocjena = 0;
	float broj_ocjena = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (studenti[j].predmet == i + 1)
			{
				suma_ocjena += studenti[j].ocjena;
				broj_ocjena++;
			}
		}
		if (suma_ocjena != 0)
		{
			cout << "\n\t\tPredmet: " << i + 1 << setw(40)
				<< "Prosjecna ocjena: " << fixed << setprecision(2) << suma_ocjena / broj_ocjena;
			suma_ocjena = 0;
			broj_ocjena = 0;
		}
	}
	cout << "\n\n\n";
}