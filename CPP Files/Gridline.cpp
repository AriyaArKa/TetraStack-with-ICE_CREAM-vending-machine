
#include "Gridline.h"
#include "blockcolor.h"
#include <bits/stdc++.h>
using namespace std;
Gridline ::Gridline ()
{
    numRows = 30;
    numCols = 16;
    cellSize = 30;
    Implementation();
    colors = GetCellColors();
}

void Gridline ::Implementation()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            Gridcell[row][column] = 0;
        }
    }
}

void Gridline ::Show()
{
    for (int r = 0; r < numRows; r++)
    {
        for (int col = 0; col < numCols; col++)
        {
            cout << Gridcell[r][col] << " ";
        }
        cout << endl;
    }
}

void Gridline ::draw()
{
    for (int r = 0; r < numRows; r++)
    {
        for (int col = 0; col < numCols; col++)
        {
            int cellValue = Gridcell[r][col];
            DrawRectangle(col * cellSize + 11, r * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Gridline ::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true;
}

bool Gridline ::IsCellEmpty(int row, int column)
{
    if (Gridcell[row][column] == 0)
    {
        return true;
    }
    return false;
}

int Gridline ::ClearFullRows()
{
    int completed = 0;
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

bool Gridline ::IsRowFull(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        if (Gridcell[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Gridline ::ClearRow(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        Gridcell[row][column] = 0;
    }
}

void Gridline ::MoveRowDown(int row, int numRows)
{
    for (int column = 0; column < numCols; column++)
    {
        Gridcell[row + numRows][column] = Gridcell[row][column];
        Gridcell[row][column] = 0;
    }
}
