#include <iostream>
#include <string>

#pragma once
using namespace std;

void printAlignment(string print, int size, char space = ' ', int direction = 0, bool overflow = true)
{
    int len = print.length();
    int lenSpaceLeft;
    int lenSpaceRight;
    if (!overflow && len > size)
    {
        lenSpaceLeft = 0;
        lenSpaceRight = 0;
        len == size;
    }
    else if (direction == 1)
    {
        lenSpaceLeft = size - len;
        lenSpaceRight = 0;
    }
    else if (direction == -1)
    {
        lenSpaceLeft = 0;
        lenSpaceRight = size - len;
    }
    else
    {
        lenSpaceLeft = (size - len) / 2;
        lenSpaceRight = size - len - lenSpaceLeft;
    }
    for (int i = 0; i < lenSpaceLeft; i++)
        cout << space;
    for (int i = 0; i < len; i++)
        cout << print[i];
    for (int i = 0; i < lenSpaceRight; i++)
        cout << space;
}

void printAlignment(int print, int size, char space = ' ', int direction = 0,bool overflow = true)
{
    string tmp = to_string(print);
    printAlignment(tmp, size, space, direction,overflow);
}



