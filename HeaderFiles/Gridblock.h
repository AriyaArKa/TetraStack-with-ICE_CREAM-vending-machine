#pragma once
#include <vector>
#include <map>
#include "blockposition.h"
#include "blockcolor.h"
#include <bits/stdc++.h>
using namespace std;

class Block
{
    private:
    int cellSize;
    int rotationState;
    vector<Color> colors;
    int rowOffset;
    int columnOffset;

public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int columns);
    vector<Position> GetCellPositions();
     void Rotate();
     virtual void UndoRotation();
    int id;
    map<int,vector<Position>> cells;


};
