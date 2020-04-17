#include "pch.h"



bool isValidSudoku(std::vector<std::vector<char>> grid)
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int columnSeen[9] = { 0 };
            int rowSeen[9] = { 0 };

            if (grid[i][j] != '.')
            {
                columnSeen[grid[i][j]]++;
            }
            else if (columnSeen[grid[i][j]] > 1)
            {
                return false;
            }




            if (grid[j][i] != '.')
            {
                rowSeen[grid[j][i]]++;
            }
            else if (rowSeen[grid[j][i]] > 1)
            {
                return false;
            }
        }
    }

    return true;
}

void isValidSudoku()
{
    std::vector<std::vector<char>> grid =

    { {'.', '.', '.', '.', '.', '.', '.', '.', '2'},
      {'.', '.', '.', '.', '.', '.', '6', '.', '.'},
      {'.', '.', '1', '4', '.', '.', '8', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '3', '.', '.', '.', '.'},
      {'5', '.', '8', '6', '.', '.', '.', '.', '.'},
      {'.', '9', '.', '.', '.', '.', '4', '.', '.'},
      {'.', '.', '.', '.', '5', '.', '.', '.', '.'} };

    isValidSudoku(grid);
}