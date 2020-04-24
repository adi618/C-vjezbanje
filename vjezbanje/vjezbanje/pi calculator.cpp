#include "pch.h"


// Napisati funkciju koja racuna random broj izmedju 0 i 1. Na osnovu nje izracunati pi broj.


double random()
{
	return (double)rand() / RAND_MAX;
}


void picalculator()
{
	int n = 999999;

	double x, y;
	double distance;
	int insideCircleCount = 0;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		x = random();
		y = random();

		distance = x * x + y * y;

		if (distance < 1)
			insideCircleCount++;
	}
	double pi = (double)insideCircleCount * 4 / n;
	std::cout << "\n\n\tNumber Pi: " << pi << "\n\n\n";
}