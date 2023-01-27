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
    
    char Up(int& row, int& col);
    char Down(int& row, int& col);
    char Left(int& row, int& col);
    char Right(int& row, int& col);
    void CreateGameBoard(int& alienRow, int& alienCol);
    void ShowGameBoard();
    
}

#endif
