#ifndef PF_HELPER_H
#define PF_HELPER_H

namespace pf
{
    extern int kRows;
    extern int kColumns;
    extern int kZombies;
    extern int alienRow;
    extern int alienCol;
 
    int ClearScreen();
    int Pause();

    void Up(int& row, int& col);
    void Down(int& row, int& col);
    void Left(int& row, int& col);
    void Right(int& row, int& col);
    void CreateGameBoard(int& alienRow, int& alienCol);
    void ShowGameBoard();
    
}

#endif