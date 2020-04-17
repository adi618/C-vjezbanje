#include "pch.h"



using namespace std;

bool prime(int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int backwards(int n)
{
	int backwards = 0;

	while (n > 0)
	{
		backwards = backwards * 10 + n % 10;
		n /= 10;
	}

	return backwards;
}

string backwardsPrime(long long start, long long end)
{
	string s;

	for (int i = start; i < end; i++)
	{
		int a = backwards(i);

		if (prime(i) && prime(a) && i != a)
		{
			s += to_string(i);
			s += ' ';
		}
	}

	return s;
}

void backwardsPrime()
{
	long long a = 70000;
	long long b = 70245;

	cout << backwardsPrime(a, b);
}
