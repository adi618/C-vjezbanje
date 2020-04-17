#include "pch.h"



using namespace std;


template <typename T> vector<T> uniqueInOrder(const vector<T>& iterable)
{

	vector <T> inOrder;
	

	for (int i = 0; i < iterable.size() - 1; i++)
	{
		if (iterable[i] != iterable[i + 1])
		{
			inOrder.push_back(iterable[i]);
		}
	}

	if (iterable[iterable.size() - 1] != iterable[iterable.size() - 2])
	{
		inOrder.push_back(iterable[iterable.size() - 1]);
	}


	return inOrder;
}

vector<char> uniqueInOrder(const string& iterable)
{
	vector <char> inOrder;

	for (int i = 0; i < iterable.size() - 1; i++)
	{
		if (iterable[i] != iterable[i + 1])
		{
			inOrder.push_back(iterable[i]);
		}
	}

	inOrder.push_back(iterable[iterable.size() - 1]);
	

	return inOrder;
}

void uniqueInOrder()
{
	vector <int> integers = { 1,2,2,2,3,5,5,1 };
	string a = "aa";


	vector<char> b = uniqueInOrder(a);


	for (int i = 0; i < b.size(); i++)
	{
		cout << b[i] << "  ";
	}
}