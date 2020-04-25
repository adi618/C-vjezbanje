#include "pch.h"


std::vector<int> sumInSortedArray(std::vector<int>& nums, int target)
{
    int size = nums.size();
    int left = 0;
    int right = size - 1;
    while (left < right)
    {
        if (nums[left] + nums[right] == target)
            return { left, right };
        if (nums[left] + nums[right] < target)
            left++;
        else
            right--;
    }
    return { 0 };
}



void sumInSortedArray()
{
    std::vector <int> arr{ 2,3,4 };
    std::vector <int> arr2{ 2,7,11,15 };
    std::vector <int> arr3 = sumInSortedArray(arr, 6);
    std::vector <int> arr4 = sumInSortedArray(arr2, 9);
    return;
}