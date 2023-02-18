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
    int nRow, nCol;
    int rockRow, rockCol;
    vector<vector<char>> kBoard;
    vector<pair<int, int>> zombiePos;
    int alive = 0;

    char objects[] = {'^', 'v', '<', '>', 'h', 'p', 'r', ' ', ' ', ' ', ' ','s'};
    char objectsNoSpace[] = {'^', 'v', '<', '>', 'h', 'p', 'r','s'};

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

    bool changeArrow(int row, int col, char dir)
    {
        if (dir != '^' && dir != 'v' && dir != '<' && dir != '>')
        {
            return false;
        }

        if (kBoard[row][col] == '^' || kBoard[row][col] == 'v' 
         || kBoard[row][col] == '<' || kBoard[row][col] == '>')
        {
            kBoard[row][col] = dir;
            return true;
        }
        else
        {
            return false;
        }
    }

    void deleteEntity(int row, int col)
    {
        kBoard[row][col] = ' ';
    } 

    void SetCoordinates(int &row, int &col, int num)
    {
        row = zombiePos[num].first;
        col = zombiePos[num].second;
    }

    void resetTrail()
    {
        for(int i = 0; i < kRows; ++i)
        {
            for(int j = 0; j < kColumns; ++j)
            {
                if(kBoard[i][j] == '.')
                {
                    int randomObj = rand() % 7;
                    kBoard[i][j] = objectsNoSpace[randomObj];
                }
            }
        }
    }

    void rock(char chosen)
    {
        kBoard[rockRow][rockCol] = chosen;
    }
    

    char Movement(int &row, int& col, int addRow, int addCol, bool arrow)
    {
        int finalRow = row + addRow;
        int finalCol = col + addCol;

        if (kBoard[finalRow][finalCol] == ' ')
        {
            kBoard[finalRow][finalCol] = kBoard[row][col];

            if(arrow == false)
            {
                kBoard[row][col] = ' ';
            }
            else
            {
                kBoard[row][col] = '.';
            }

            row += addRow;
            col += addCol;
            return 'a'; //'a' means empty space
        }
        else if (kBoard[finalRow][finalCol] == 'r')
        {
            rockRow = finalRow;
            rockCol = finalCol;
            return 'r';
        }
        else if(kBoard[finalRow][finalCol] == '1'
             || kBoard[finalRow][finalCol] == '2'
             || kBoard[finalRow][finalCol] == '3'
             || kBoard[finalRow][finalCol] == '4'
             || kBoard[finalRow][finalCol] == '5'
             || kBoard[finalRow][finalCol] == '6'
             || kBoard[finalRow][finalCol] == '7'
             || kBoard[finalRow][finalCol] == '8'
             || kBoard[finalRow][finalCol] == '9')
        {
            return kBoard[finalRow][finalCol];
        }
        else
        {
            int tempObj = kBoard[row + addRow][col + addCol];

            kBoard[row + addRow][col + addCol] = kBoard[row][col];

            if(arrow == false)
            {
                kBoard[row][col] = ' ';
            }
            else
            {
                kBoard[row][col] = '.';
            }

            row += addRow;
            col += addCol;
            return tempObj;
        }
    }

    void ZombieMovement(int& row, int& col, int addRow, int addCol)
    {
        if (kBoard[row + addRow][col + addCol] != 'A' && kBoard[row + addRow][col + addCol] != '1' && kBoard[row + addRow][col + addCol] != '2'
        && kBoard[row + addRow][col + addCol] != '3' && kBoard[row + addRow][col + addCol] != '4' && kBoard[row + addRow][col + addCol] != '5'
        && kBoard[row + addRow][col + addCol] != '6' && kBoard[row + addRow][col + addCol] != '7' && kBoard[row + addRow][col + addCol] != '8'
        && kBoard[row + addRow][col + addCol] != '9')
        {
            kBoard[row + addRow][col + addCol] = kBoard[row][col];
            kBoard[row][col] = ' ';
            row += addRow;
            col += addCol;
        }
    }

    char Up(int &row, int &col, int entity, bool arrow)
    {
        if (entity == 0) // 0 means Alien, 1 means Zombies
        {
            if (kBoard[row][col] != kBoard[0][col])
            {
                char obj = Movement(row, col, -1, 0, arrow);
                return obj;
            }
            else
            {
                return 'b'; //'b' means border blocking
            }
        }
        else
        {
            if (kBoard[row][col] != kBoard[0][col])
            {
                ZombieMovement(row, col, -1, 0);
                return 'c';
            }
            else
            {
                return 'd';
            }
            return 'd';
        }
    }

    char Down(int &row, int &col, int entity, bool arrow)
    {
        if (entity == 0)
        {
            if (kBoard[row][col] != kBoard[kRows - 1][col])
            {
                char obj = Movement(row, col, 1, 0, arrow);
                return obj;
            }
            else
            {
                return 'b';
            }
        }
        else
        {
            if (kBoard[row][col] != kBoard[kRows - 1][col])
            {
                ZombieMovement(row, col, 1, 0);
                return 'c';
            }
            else
            {
                return 'd';
            }
            return 'd';
        }
    }

    char Left(int &row, int &col, int entity, bool arrow)
    {
        if (entity == 0)
        {
            if (kBoard[row][col] != kBoard[row][0])
            {
                char obj = Movement(row, col, 0, -1, arrow);
                return obj;
            }
            else
            {
                return 'b';
            }
        }
        else
        {
            if (kBoard[row][col] != kBoard[row][0])
            {
                ZombieMovement(row, col, 0, -1);
                return 'c';
            }
            else
            {
                return 'd';
            }
            return 'd';
        }
    }

    char Right(int &row, int &col, int entity, bool arrow)
    {
        if (entity == 0)
        {
            if (kBoard[row][col] != kBoard[row][kColumns - 1])
            {
                char obj = Movement(row, col, 0, 1, arrow);
                return obj;
            }
            else
            {
                return 'b';
            }
        }
        else
        {
            if (kBoard[row][col] != kBoard[row][kColumns - 1])
            {
                ZombieMovement(row, col, 0, 1);
                return 'c';
            }
            else
            {
                return 'd';
            }
            return 'd';
        }
    }

    void CreateGameBoard(int &alienRow, int &alienCol)
    {

        
        char entities[kZombies];

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

        // random_shuffle(&entities[0], &entities[kZombies - 1]); --IGNORE THIS

        // INSERT ENTITY INTO RANDOM CELLS:

        kBoard[(kRows / 2)][(kColumns / 2)] = 'A';
        alienRow = kRows / 2;
        alienCol = kColumns / 2;

        for (int i = 0; i < kZombies; i++)
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
        int numOfObjects = 12;

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

        do
        {
            nRow = rand() % kRows;
            nCol = rand() % kColumns;
        }    
        while (kBoard[nRow][nCol] == 'A' || kBoard[nRow][nCol] == '1' || kBoard[nRow][nCol] == '2' || kBoard[nRow][nCol] == '3' || kBoard[nRow][nCol] == '4' || kBoard[nRow][nCol] == '5' || kBoard[nRow][nCol] == '6' ||kBoard[nRow][nCol] == '7' || kBoard[nRow][nCol] == '8' || kBoard[nRow][nCol] == '9');
       
        kBoard[nRow][nCol] = 'n';
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
