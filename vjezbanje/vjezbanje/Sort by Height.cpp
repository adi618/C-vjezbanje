#include "pch.h"




std::vector<int> sortByHeight(std::vector<int>& a) {

    std::vector<int> temp;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == -1)
        {
            temp.push_back(i);
        }
    }

    for (int i = temp.size() - 1; i > -1; i--)
    {
        a.erase(a.begin() + temp[i]);
    }

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size() - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
            }
        }
    }

    for (int i = 0; i < temp.size(); i++)
    {
        a.insert(a.begin() + temp[i], -1);
    }

    return a;
}



void sortByHeight()
{
    std::vector<int> a = { -1, 150, 190, 170, -1, -1, 160, 180 };

    sortByHeight(a);

    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << "  ";

    }
}