#include "pch.h"


int commonCharacterCount2(std::vector<std::string> s)
{
    int common = 0;
    int** alphabet = new int* [s.size()];

    for (int i = 0; i < s.size(); i++)
    {
        alphabet[i] = new int[26];
    }

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            *(alphabet[i] + j) = 0;
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            *(alphabet[i] + (s[i][j] - 'a')) += 1;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        int temp = INT_MAX;
        for (int j = 0; j < s.size(); j++)
        {
            if (*(alphabet[j] + i) < temp)
                temp = *(alphabet[j] + i);
        }
        common += temp;
    }

    for (int i = 0; i < s.size(); i++)
    {
        delete[] alphabet[i];
    }

    delete[] alphabet;

    return common;
}

void commonCharacterCount2()
{
    std::vector<std::string> s =   { "aabcc",
                                     "adcaa",
                                     "ddddddbbbbbabbd" };

    std::cout << commonCharacterCount2(s);

}