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
    
    void SetCoordinates(int& row, int& col);
    char Up(int& row, int& col, int entity);
    char Down(int& row, int& col, int entity);
    char Left(int& row, int& col, int entity);
    char Right(int& row, int& col, int entity);
    void CreateGameBoard(int& alienRow, int& alienCol);
    void ShowGameBoard();
    
}

#endif
