#include "pch.h"



using namespace std;

void okreni(char* p)
{
	int counter = 0;

	for (int i = 0; i < 20; i++)
	{
		if (*(p + i) > 0 && *(p + i) < 127)
			counter++;
	}

	for (int i = 0; i < counter / 2; i++)
	{
		char temp = *(p + i);
		*(p + i) = *(p + counter - 1 - i);
		*(p + counter - 1 - i) = temp;
	}
}

void Zadatak_4()
{
	char rijec[20];

	cin.getline(rijec, 20);

	char* ptr = rijec;

	okreni(ptr);
	
	cout << rijec;
}