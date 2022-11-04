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

void SetUpBoard()
{
    int ships = 0;
    while (ships < maximumships)
    {
        int x = rand() % rows;
        int y = rand() % columns;
        if (board[x][y] != 1)
        {
            ships++;
            board[x][y] = 1;
        }
    }
}

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

void Search(int x, int y);

void Fire(int x, int y)
{
    //HIT
    if (board[x][y] == 1)
    {
        numberofships--;
        board[x][y] = 0;
        std::cout << "The computer hit a ship." << std::endl;
    }

    //NEAR MISS
    if (board[x + 1][y] == 1 || board[x - 1][y] == 1)
    {
        std::cout << "The computer almost hit a ship." << std::endl;
        Search(x, y);
    }

    if (board[x][y + 1] == 1 || board[x][y - 1] == 1)
    {
        std::cout << "The computer almost hit a ship." << std::endl;
        Search(x, y);
    }

    if (board[x + 1][y + 1] == 1 || board[x - 1][y - 1] == 1)
    {
        std::cout << "The computer almost hit a ship." << std::endl;
        Search(x, y);
    }

    if (board[x - 1][y + 1] == 1 || board[x + 1][y - 1] == 1)
    {
        std::cout << "The computer almost hit a ship." << std::endl;
        Search(x, y);
    }

    //MISS
    else
    {
        std::cout << "The computer did not hit a ship." << std::endl;
    }
}

void Search(int x, int y)
{
    bool found = false;
    while (found == false)
    {
        if (board[x - 1][y - 1] == 1)
        {
            found = true;
            Fire(x - 1, y - 1);
        }

        if (board[x][y - 1] == 1)
        {
            found = true;
            Fire(x, y - 1);
        }

        if (board[x + 1][y - 1] == 1)
        {
            found = true;
            Fire(x + 1, y - 1);
        }

        if (board[x - 1][y] == 1)
        {
            found = true;
            Fire(x - 1, y);
        }

        if (board[x + 1][y] == 1)
        {
            found = true;
            Fire(x + 1, y);
        }

        if (board[x - 1][y + 1] == 1)
        {
            found = true;
            Fire(x - 1, y + 1);
        }

        if (board[x][y + 1] == 1)
        {
            found = true;
            Fire(x, y + 1);
        }

        if (board[x + 1][y + 1] == 1)
        {
            found = true;
            Fire(x + 1, y + 1);
        }
    }
}

void Game()
{
    while (numberofships > 0)
    {
        int randomrow = rand() % rows;
        int randomcolumn = rand() % columns;
        Fire(randomrow, randomcolumn);
    }

    std::cout << "All of the ships have been found." << std::endl;
}

int main()
{
    Reset();
    Game();
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