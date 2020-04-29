#include "pch.h"


void InsertionSort(std::vector <int>& array)		// Time: O(n^2); Space: O(1)
{
    for (int i = 1; i < array.size(); i++) {
        int j = i - 1;

        while (j >= 0 && array[j] > array[i]) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = array[i];
    }
}



void InsertionSort()
{
	std::vector <int> array = { 1,5,7,4,3,7,8,4,5,7,3 };
    InsertionSort(array);
	return;
}