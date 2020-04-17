#include "pch.h"

using namespace std;
void ManipulacijaStringovaVjezbanje()
{
	char recenica[100];
	cout << "Unesi neku recenicu: ";
	cin >> recenica;
	cout << "Unesena recenica glasi: \n" << recenica;

	strcpy_s(recenica, "gsdsdffsd  asd sa");
	cout << "\nUnesena recenica glasi: \n" << recenica;

	strcat_s(recenica, " danke danke");
	cout << "\nUnesena recenica glasi: \n" << recenica;



	cout << "\n\n\n" << strcmp(recenica, "eeeeeeeeee") << "\n\n\n";

	int i = 0;

	while (recenica[i] != 0)
	{
		recenica[i] = toupper(recenica[i]);
		i++;
	}
	cout << "\nUnesena recenica glasi: \n" << recenica;

	cout << "\n\n\n\n\n";


	//Napisite program koji prvo trazi da se sa tastature unese
	//	recenica, a zatim ispisuje svaku rijec te recenice u posebnom
	//	redu, kao i informaciju koliko ta recenica ima slova(ne
	//		racunajuci interpunkcijske znakove) i rijeci.Obratite paznju
	//	da rijeci recenice mogu biti razdvojene sa vise od jednog
	//	razmaka, kao i da se na samom pocetku i na samom kraju
	//	recenice mogu takoder nalaziti razmaci.
}