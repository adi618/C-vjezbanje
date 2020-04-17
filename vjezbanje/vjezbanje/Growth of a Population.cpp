#include "pch.h"



using namespace std;


int years(int population, double percentage, int newHabitants, int goal)
{
	int years = 0;

	while (population <= goal)
	{
		population += population * (percentage / 100);
		population += newHabitants;
		years++;
	}

	return years;
}

void years()
{
	int population, newHabitants, goal;
	double percentage;
	
	population = 1000;
	
	percentage = 2;

	newHabitants = 50;

	goal = 1200;

	cout << years(population, percentage, newHabitants, goal);
}