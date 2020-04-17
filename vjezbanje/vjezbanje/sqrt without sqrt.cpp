#include "pch.h"



using namespace std;

float Sqrt(int n)
{
	float left = 0, right = n;
	float mid = 0;

	while (left < right)
	{
		mid = left + (right - left) / 2;

		if (mid * mid == n || abs(mid * mid - n) < 0.00001F)
			return mid;

		if (mid * mid > n)
			right = mid;
		else
			left = mid;
	}
	return mid;
}

void Sqrt()
{
	int n;
	cout << "\n\n\tUnesite broj: ";
	cin >> n;

	float sqrt = Sqrt(n);

	if (sqrt == -1)
		cout << "\n\n\tUneseni broj nije kvadrat nekog broja\n\n\n";
	else
		cout << "\n\n\tUneseni broj je kvadrat broja: " << sqrt << "\n\n\n";

}