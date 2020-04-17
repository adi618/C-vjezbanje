#include "pch.h"



using namespace std;

bool almostIncreasingSequence(vector<int>& sequence)
{

    if (sequence.size() < 3)
        return true;

    int canDelete = 0;


    for (int i = 0; i < sequence.size() - 1; i++)
    {
        if (sequence[i] >= sequence[i + 1])
        {
            if (i != 0 && sequence[i + 1] <= sequence[i - 1])
            {
                sequence[i + 1] = sequence[i];
            }
            canDelete++;
        }
    }


    return canDelete < 2;
}


void almostIncreasingSequence()
{
    vector<int>arr{ 1, 3, 5, 3, 6 };

    cout << almostIncreasingSequence(arr);
}