#include <iostream>
#include "..\func\printAlignment.cpp"

using namespace std;

#pragma once
template <typename T>
class Table
{
private:
    static const char angleTopLeft = 201;     // ╔
    static const char angleBottomLeft = 200;  // ╚
    static const char angleTopRight = 187;    // ╗
    static const char angleBottomRight = 188; // ╝
    static const char lineHorizontal = 205;   // ═
    static const char lineVertical = 186;     // ║
    static const char threeWayRight = 204;    // ╠
    static const char threeWayLeft = 185;     // ╣
    static const char threeWayTop = 202;      // ╩
    static const char threeWayBottom = 203;   // ╦
    static const char fourWay = 206;          // ╬
    int row = 1;
    int column = 1;
    int height = 1;
    int width = 1;
    int textAlign = 0;
    bool overflow = false;
    bool is = false;
    T **cells;

    void repeat(char c, int n)
    {
        for (int i = 0; i < n; i++)
            cout << c;
    }

    void create()
    {
        if (is)
            destroy();
        cells = new T *[row];
        for (int i = 0; i < row; i++)
            cells[i] = new T[column];
        is = true;
    }
    void destroy()
    {
        for (int i = 0; i < row; i++)
            delete[] cells[i];
        delete[] cells;
        is = false;
    }

public:
    Table() {}
    Table(int row, int column)
    {
        this->row = row;
        this->column = column;
        create();
    }

    ~Table()
    {
        destroy();
    }

    void Create(int row, int column)
    {
        this->row = row;
        this->column = column;
        create();
    }

    void Show()
    {

        cout << angleTopLeft;
        repeat(lineHorizontal, width);
        for (int i = 0; i < column - 1; i++)
        {
            cout << threeWayBottom;
            repeat(lineHorizontal, width);
        }
        cout << angleTopRight;
        cout << "\n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < height; j++)
            {
                cout << lineVertical;
                if (j == (int)height / 2)
                {
                    printAlignment(cells[i][0], width, ' ', textAlign, overflow);
                }
                else
                    repeat(' ', width);
                for (int k = 0; k < column - 1; k++)
                {
                    cout << lineVertical;
                    if (j == (int)height / 2)
                    {
                        printAlignment(cells[i][k + 1], width, ' ', textAlign, overflow);
                    }
                    else
                        repeat(' ', width);
                }
                cout << lineVertical;
                cout << "\n";
            }
            if (i < row - 1)
            {
                cout << threeWayRight;
                repeat(lineHorizontal, width);
                for (int j = 0; j < column - 1; j++)
                {
                    cout << fourWay;
                    repeat(lineHorizontal, width);
                }
                cout << threeWayLeft;
                cout << "\n";
            }
        }
        cout << angleBottomLeft;
        repeat(lineHorizontal, width);
        for (int i = 0; i < column - 1; i++)
        {
            cout << threeWayTop;
            repeat(lineHorizontal, width);
        }
        cout << angleBottomRight;
        cout << "\n";
    }

    int HeightCell()
    {
        return this->height;
    }
    void HeightCell(int height)
    {
        if (height > 0)
            this->height = height;
    }

    int WidthCell()
    {
        return this->width;
    }
    void WidthCell(int width)
    {
        if (width > 0)
            this->width = width;
    }

    int TextAlign()
    {
        return textAlign;
    }
    void TextAlign(int textAlign)
    {
        this->textAlign = textAlign;
    }

    bool Overflow()
    {
        return overflow;
    }
    void Overflow(bool overflow)
    {
        this->overflow = overflow;
    }

    T Cells(int i, int j)
    {
        return cells[i][j];
    }
    void Cells(int i, int j, T val)
    {
        this->cells[i][j] = val;
    }
};