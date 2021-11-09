#include <iostream>
#include "..\class\table.cpp"

using namespace std;

#pragma once
class Game
{
private:
    int size = 4;
    int score = 0;
    Table<int> table;

public:
    Game()
    {
    }
    ~Game() {}
    bool Create()
    {
        table.HeightCell(3);
        table.WidthCell(9);
        table.Overflow(false);
        table.TextAlign(0);
        table.Create(size, size);
    }
    bool Start()
    {
    }
    bool Restart()
    {
    }
    bool End()
    {
    }
    bool Left()
    {
    }
    bool Right()
    {
    }
    bool Top()
    {
    }
    bool Bottom()
    {
    }
    bool GameOver()
    {
    }
};