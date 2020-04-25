#include "pch.h"

//https://leetcode.com/problems/two-sum/submissions/


std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
        for (int j = 0; j < nums.size(); j++)
            if (nums[i] + nums[j] == target)
                return { i,j };

    return { 0 };
}



void twoSum()
{
    std::vector <int> arr{ 3,2,4 };
    std::vector <int> arr2{ 2,7,11,15 };
    std::vector <int> arr3 = twoSum(arr, 6);
    std::vector <int> arr4 = twoSum(arr2, 9);
    return;
}