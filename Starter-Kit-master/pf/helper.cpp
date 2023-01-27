#include "helper.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

namespace pf
{
    int kRows = 5;
    int kColumns = 11;
    int alienRow, alienCol;
    vector<vector<char>> kBoard;
    vector<pair<int, int>> zombiePos;
    

    int kZombies = 1;

    int ClearScreen()
    {
#if defined(_WIN32)
        return std::system("cls");
#elif defined(__linux__) || defined(__APPLE__)
        return std::system("clear");
#endif
    }

    int Pause()
    {
#if defined(_WIN32)
        return std::system("pause");
#elif defined(__linux__) || defined(__APPLE__)
        return std::system(R"(read -p "Press any key to continue . . . " dummy)");
#endif
    }

    void Up(int& row, int& col)
    {
        kBoard[row - 1][col] = kBoard[row][col];
        kBoard[row][col] = ' ';
        row -= 1;
    }

    void Down(int& row, int& col)
    {
        kBoard[row + 1][col] = kBoard[row][col];
        kBoard[row][col] = ' ';
        row += 1;
    }

    void Left(int& row, int& col)
    {
        kBoard[row][col - 1] = kBoard[row][col];
        kBoard[row][col] = ' ';
        col -= 1;
    }

    void Right(int& row, int& col)
    {
        kBoard[row][col + 1] = kBoard[row][col];
        kBoard[row][col] = ' ';
        col += 1;
    }

    
    void CreateGameBoard(int& alienRow, int& alienCol)
    {

        char objects[] = {'^', 'v', '<', '>', 'h', 'p', 'r', ' ', ' ', ' ', ' '};
        char entities[kZombies - 1] = {};

        kBoard.resize(kRows); // resize Y or ROWS
        for (int i = 0; i < kRows; ++i)
        {
            kBoard[i].resize(kColumns); // resize X or COLUMNS
        }

        // IMPLEMENT GAME ENTITIES (ALIEN & ZOMBIES):
        for (int i = 0; i < kZombies; ++i)
        {
            entities[i] = (i + 1) + '0';
        }

        //random_shuffle(&entities[0], &entities[kZombies - 1]); --IGNORE THIS

        // INSERT ENTITY INTO RANDOM CELLS:

        kBoard[(kRows / 2)][(kColumns / 2)] = 'A';
        alienRow = kRows / 2;
        alienCol = kColumns / 2;

        for (int i = 0; i < kZombies + 1; i++)
        {
            int random_row = rand() % kRows;
            int random_column = rand() % kColumns;

            if (kBoard[random_row][random_column] != 0)
            {
                i -= 1;
                continue;
            }
            else
            {
                kBoard[random_row][random_column] = entities[i];
                zombiePos.push_back({random_row, random_column});
            }
        }

        // INSERT GAME OBJECTS INTO BOARD:
        int numOfObjects = 11;

        for (int row = 0; row < kRows; ++row)
        {
            for (int col = 0; col < kColumns; ++col)
            {
                int random_number = rand() % numOfObjects;

                if (kBoard[row][col] == 0)
                {
                    kBoard[row][col] = objects[random_number];
                }
                else
                {
                    continue;
                }
            }
        }
    }

    void ShowGameBoard()
    {

        cout << "    ";
        cout << ".: Alien vs Zombie :." << endl;
        // EACH ROW:
        for (int row = 0; row < kRows; ++row)
        {
            // UPPER BORDER:
            cout << "   ";
            for (int col = 0; col < kColumns; ++col)
            {
                cout << "+-";
            }
            cout << "+" << endl;

            // ROW NUMBER:
            cout << " ";
            cout << setw(2) << (kRows - row);

            // CELL CONTENT & LEFT/RIGHT BORDERS:
            for (int col = 0; col < kColumns; ++col)
            {
                cout << "|" << kBoard[row][col];
            }
            cout << "|" << endl;
        }

        // LAST ROW'S LOWER BORDER:
        cout << "   ";
        for (int col = 0; col < kColumns; ++col)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << endl;

        cout << "   ";

        // COLUMN NUMBERS:

        // TOP NUMBER(2nd Digit):
        for (int col = 0; col < kColumns; ++col)
        {
            // START DISPLAYING AT COLUMN INDEX 11:
            int num = (col + 1) / 10;
            cout << " ";
            if (num == 0)
                cout << " ";
            else
                cout << num;
        }

        cout << endl;
        cout << "   ";

        // BOTTOM NUMBER(1st Digit):
        for (int col = 0; col < kColumns; ++col)
        {
            // RESETS TO 0 AT 10:
            cout << " " << (col + 1) % 10;
        }
        cout << endl
             << endl;
    }

}