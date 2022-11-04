// Battleship.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

const int rows = 16;
const int columns = 16;
const int maximumships = 10;
int numberofships = 10;
int board[rows][columns];
int randomrow = rand() % rows;
int randomcolumn = rand() % columns;

enum HitMessage
{
    HIT,
    MISS,
    NEARMISS
};

void Reset()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            board[i][j] = 0;
        }
    }

    numberofships = 10;
    SetUpBoard();
}

void SetUpBoard()
{
    int ships = 0;
    while (ships < maximumships)
    {
        int x = randomrow;
        int y = randomcolumn;
        if (board[x][y] != 1)
        {
            ships++;
            board[x][y] = 1;
        }
    }
}

HitMessage Fire(int x, int y)
{
    if (board[x][y] == 1)
    {
        numberofships--;
        board[x][y] = 0;
        return HIT;
    }

    if (board[x + 1][y] == 1 || board[x - 1][y] == 1)
    {
        return NEARMISS;
    }

    if (board[x][y + 1] == 1 || board[x][y - 1] == 1)
    {
        return NEARMISS;
    }

    else
    {
        return MISS;
    }
}

void Recalculate(HitMessage hm)
{
    if (hm == HIT)
    {

    }

    if (hm == NEARMISS)
    {

    }

    if (hm == MISS)
    {

    }
}

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file