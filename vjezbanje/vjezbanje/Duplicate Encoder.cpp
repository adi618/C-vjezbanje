#include "pch.h"



using namespace std;


string duplicate_encoder(string& b)
{
	string a;
	a.resize(b.size());

	for (int unsigned i = 0; i < b.size(); i++)
	{

		if (a[i] == 41 || a[i] == 40)
		{
			continue;
		}

		bool repeating = false;

		for (int unsigned j = i + 1; j < b.size(); j++)
		{

			if (b[i] == b[j])
			{
				a[j] = 41;
				repeating = true;
			}

			if (b[i] > 64 && b[i] < 91)
			{
				if (b[i] + 32 == b[j])
				{
					a[j] = 41;
					repeating = true;
				}
			}

			else if (b[i] > 96 && b[i] < 123)
			{
				if (b[i] - 32 == b[j])
				{
					a[j] = 41;
					repeating = true;
				}
			}

		}

		if (repeating)
		{
			a[i] = 41;
		}
		else
		{
			a[i] = 40;
		}
	}

	return a;
}

void duplicate_encoder()
{
	string a;
	cin >> a;

	cout << duplicate_encoder(a);
}