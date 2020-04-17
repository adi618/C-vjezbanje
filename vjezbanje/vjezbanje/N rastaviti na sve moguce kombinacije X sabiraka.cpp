#include "pch.h"



using namespace std;

void PrikaziRastavuNaSabirke(int n, int k)
{
	static int niz[100], indeks = 0;

	if (k == 1)
	{
		for (int i = 0; i < indeks; i++) cout << niz[i] << "+";

		cout << n << endl;
	}
	else
		for (int i = 1; i <= n + 1 - k; i++)
		{
			niz[indeks++] = i;

			PrikaziRastavuNaSabirke(n - i, k - 1);

			indeks--;
		}
}

void PrikaziRastavuNaSabirke()
{
	int a, b;

	cin >> a >> b;

	PrikaziRastavuNaSabirke(a, b);
}