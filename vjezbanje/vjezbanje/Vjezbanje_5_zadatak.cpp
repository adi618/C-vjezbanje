#include "pch.h"



using namespace std;

bool prost(int n, int i)
{
	if (n < 2)
		return false;

	if (n == 2)
		return true;

	if (n % i == 0)
		return false;

	if (i > n / 2)
		return true;
	else
		return prost(n, i + 1);
}


void Vjezbanje_5_zadatak()
{
	cout << "Ispitati da li je unijeti broj N prost koristeci rekurzivnu funkciju prost.\n";
	cout << "Pronaci sve brojeve - blizance do zadatog broja n. Dva broja su blizanci\n";
	cout << "ako su prosti i razlikuju se za 2.\n\n\n";

	int n;
	cout << "\tUnesite broj: ";
	cin >> n;

	bool Status = prost(n, 2);

	if (Status)
	{
		bool StatusPlus = prost(n + 2, 2);
		bool StatusMinus = prost(n - 2, 2);

		cout << "\n\n\tUneseni broj je prost ";
		if (!StatusPlus && !StatusMinus)
			cout << "i on nema blizanaca\n\n\n";
		else if (StatusPlus && StatusMinus)
			cout << "i on ima dva blizanca, a to su: " << n + 2 << " i " << n - 2 << "\n\n\n";
		else
			cout << "i on ima jednog blizanca, a to je: " << ((StatusPlus) ? n + 2 : n - 2) << "\n\n\n";
	}
	else
		cout << "\n\n\tBroj nije prost, stoga nema blizanaca.\n\n\n";
}