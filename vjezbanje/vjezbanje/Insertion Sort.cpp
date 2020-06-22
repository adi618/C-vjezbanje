#include "pch.h"


void InsertionSort(std::vector <int>& array)		// Time: O(n^2); Space: O(1)
{
    for (int i = 1; i < array.size(); i++) {
        int j = i - 1;
        int x = array[i];

        while (j >= 0 && array[j] > x) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = x;
    }
}



void InsertionSort()
{
	std::vector <int> array = { 1,5,7,4,3,7,8,4,5,7,3 };
    InsertionSort(array);
	return;
}