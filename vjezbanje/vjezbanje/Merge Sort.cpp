#include "pch.h"


void Merge(std::vector <int> array, int left, int mid, int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int* leftArray = new int[size1];
    int* rightArray = new int[size2];

    for (int i = 0; i < size1; i++)
    {
        leftArray[i] = array[left + i];
    }

    for (int j = 0; j < size2; j++)
    {
        rightArray[j] = array[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < size1 && j < size2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}


void MergeSort(std::vector <int> array, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		MergeSort(array, left, mid);
		MergeSort(array, mid + 1, right);

		Merge(array, left, mid, right);
	}
}


void MergeSort(std::vector <int> array)
{
    MergeSort(array, 0, array.size());
}


void MergeSort()
{
	std::vector <int> array = { 1,5,7,4,3,7,8,4,5,7,3 };
	MergeSort(array);
	return;
}