#ifndef PF_HELPER_H
#define PF_HELPER_H
#include <vector>

namespace pf
{
    extern int kRows;
    extern int kColumns;
    extern int kZombies;
    extern int alienRow;
    extern int alienCol;
    extern std::vector<std::vector<char>> kBoard;
 
    int ClearScreen();
    int Pause();
    
    bool changeArrow(int row, int col, char dir);
    void deleteEntity(int row, int col);
    void resetTrail();
    void rock(char chosen);
    void SetCoordinates(int& row, int& col, int num);
    char Up(int& row, int& col, int entity, bool arrow);
    char Down(int& row, int& col, int entity, bool arrow);
    char Left(int& row, int& col, int entity, bool arrow);
    char Right(int& row, int& col, int entity, bool arrow);
    void CreateGameBoard(int& alienRow, int& alienCol);
    void ShowGameBoard();
    
}

#endif
