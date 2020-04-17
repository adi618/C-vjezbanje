#include "pch.h"



using namespace std;


long long fibo(int num)
{
	if (num < 3) return 1;

	int a = 1, b = 1, c;

	for (int i = 2; i < num; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

long long rekurzivni_fibo(int num)
{
	if (num < 3)
		return 1;

	return rekurzivni_fibo(num - 1) + rekurzivni_fibo(num - 2);
}

long long fib(int num, int a = 0, int b = 1)
{
	if (num == 0)
		return a;

	if (num == 1)
		return b;

	return fib(num - 1, b, a + b);
}
