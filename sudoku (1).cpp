#include <iostream>
using namespace std;

bool sudoku(int grid[9][9], int row,int col)
{
    if (row == 9 - 1 && col == 9) { return true; }
    if (col == 9)
    {
        row++;      
        col = 0;
    }

    if (grid[row][col]) { return sudoku(grid, row, col + 1); }

    for (int value = 1; value <= 9; value++)
    {
        try
        {
            for (int i = 0; i < 9; i++)
            {
                if (grid[row][i] == value) { throw false; }
            }

            for (int i = 0; i < 9; i++)
            {
                if (grid[i][col] == value) { throw false; }
            }

            int startingRow = row - (row % 3);
            int startingCol = col - (col % 3);
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (grid[i + startingRow][j + startingCol] == value) { throw false; }
                }
            }

            throw true;
        }
        catch (bool& safe)
        {
            if (safe)
            {
                grid[row][col] = value;

                if (sudoku(grid, row, col + 1)) { return true; }

                grid[row][col] = 0;
            }
        }
    }
    return false;
}

int main()
{
    int grid[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if (!sudoku(grid, 0, 0))
    {
        cout << "Solution does not exist";
        return 0;
    }

    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
            if ((j + 1) % 3 == 0) { cout << "|"; }
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i != 0) { cout << "---------------------\n"; }
    }

	return 0;
}