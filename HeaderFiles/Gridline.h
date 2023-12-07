#pragma once
#include <vector>
#include <raylib.h>
#include <bits/stdc++.h>
using namespace std;

class Gridline
{
    private:
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
    int numRows;
    int numCols;
    int cellSize;
    vector<Color> colors;
public:
    Gridline ();
    void Implementation();
    void Show();
    void draw();
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int ClearFullRows();
    int Gridcell[40][30];


};
