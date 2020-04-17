#include "pch.h"



using namespace std;

//https://www.hackerrank.com/challenges/mark-and-toys/

int maximumToys(vector <int>& prices, int k)
{
	int max = 0;

	// Bubble sort, not fast enough for this challenge.
	for (int i = 0; i < prices.size(); i++)
	{
		for (int j = 0; j < prices.size() - 1; j++)
		{
			if (prices[j] > prices[j + 1])
			{
				swap(prices[j], prices[j + 1]);
			}
		}
	}

	int sum = prices[0];

	while (sum < k)
	{
		max++;
		sum += prices[max];
	}

	return max;
}

void maximumToys()
{
	vector <int> prices = { 1, 12, 5, 111, 200, 1000, 10 };
	int money = 50;

	cout << maximumToys(prices, money);
}