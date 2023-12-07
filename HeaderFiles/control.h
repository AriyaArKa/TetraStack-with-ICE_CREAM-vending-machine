
#pragma once
#include "Gridline.h"
#include "allblocks.cpp"
#include <bits/stdc++.h>
using namespace std;
class Game
{
    private:
    void MoveBlockLeft();
    void MoveBlockRight();
    Block GetRandomBlock();
    vector<Block> GetAllBlocks();
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    Gridline grid;
    vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Sound rotateSound;
    Sound clearSound;
public:
    Game();
    ~Game();
     void Draw();
     void HandleInput();
    void MoveBlockDown();
    bool gameOver;
    int score;
    Music music;


};
