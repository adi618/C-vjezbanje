#include "pch.h"

//https://leetcode.com/problems/move-zeroes/submissions/

void moveZeroes(std::vector<int>& nums)
{
    std::vector <int> result;
    result.reserve(nums.size());

    int numOfZeros = 0;
    for (const int& num : nums)
    {
        if (num != 0)
            result.push_back(num);
        else
            numOfZeros++;
    }
    for (int i = 0; i < numOfZeros; i++)
        result.push_back(0);

    nums = result;
}



void moveZeroes()
{
    std::vector <int> arr{ 0,0,3,0,2,4 };
    std::vector <int> arr2{ 2,7,11,0,15 };
    moveZeroes(arr);
    moveZeroes(arr2);
    return;
}