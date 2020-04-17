#include "pch.h"



using namespace std;

void countSwaps(vector<int> a) {


    int numSwaps = 0;


    for (int i = 0; i < a.size(); i++)
    {

        for (int j = 0; j < a.size() - 1; j++)
        {

            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                numSwaps++;
            }
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "  ";
    }
}

void countSwaps()
{
    vector <int> array;

    array = { -1, 150, 190, 170, -1, -1, 160, 180 };

    countSwaps(array);
}