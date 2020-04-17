#include "pch.h"


int arrayMaxConsecutiveSum(std::vector<int> inputArray, int k)
{
    int max = 0;

    for (int i = 0; i < k; i++)
    {
        max += inputArray[i];
    }

    int current = max;

    for (int i = 0; i < inputArray.size() - k + 1; i++)
    {
        current += inputArray[i + k] - inputArray[i];

        if (current > max)
        {
            max = current;
        }
    }

    return max;
}



void arrayMaxConsecutiveSum()
{
    std::vector<int>nesta = { 2, 3, 5, 1, 6 };
    std::cout << arrayMaxConsecutiveSum(nesta, 3);
}