#include "pch.h"


bool areSimilar(std::vector<int> a, std::vector<int> b)
{
    std::unordered_map <int, int> map1;
    std::unordered_map <int, int> map2;

    for (const int& num : a)
        if (map1[num])
            map1[num]++;
        else
            map1[num] = 1;

    for (const int& num : b)
        if (map2[num])
            map2[num]++;
        else
            map2[num] = 1;

    for (const int& num : a)
        if (map1[num] != map2[num])
            return false;

    for (const int& num : b)
        if (map1[num] != map2[num])
            return false;

    return true;
}