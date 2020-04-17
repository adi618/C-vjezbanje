#include "pch.h"



using namespace std;

int matrixElementsSum(vector<vector<int>>matrix)
{
    int sum = 0;

    for (int i = 0; i < matrix[0].size(); i++)
    {
        if (matrix[0][i] != 0)
        {
            sum += matrix[0][i];
        }
    }

    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i - 1][j] == 0)
            {
                matrix[i][j] = 0;
            }
            else
            {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

void matrixElementsSum()
{
    vector<vector<int>>matrix =
                            { { 0,1,1,2 },
                              { 0,5,0,0 },
                              { 2,0,3,3 } };

    cout << matrixElementsSum(matrix);
}