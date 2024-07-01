#ifndef LEVEL_H
#define LEVEL_H

#include "Mario.h"

class Level{

public:

    Level();
    Level(bool isFinalLevel, int lives, int dimensionSize, int coinPercent, int nothingPercent, int goombaPercent, int koopaPercent, int mushroomPercent, Mario* marioPointer);
    virtual ~Level();
    void printGrid();
    char** getGrid();
    void setFinalLevel(bool isFinalLevel);
    bool isFinalLevel();
    void setMarioPosition(int posx, int posy);
    void placeMario();
    void changeGridVal(int posx, int posy, char input);
    void emptyGridVal(int x, int y);
    int* returnCurrGridVal();
    void moveMario();
    int getDimensionSize();
    char getCurrentChar();
    Mario* getMario();

private:

    char** m_grid;
    int m_dimensionSize;
    int m_totalSquares;
    void initializeDefaultGrid();
    void createGrid();
    int* setItemNums(int coinPercent, int nothingPercent, int goombaPercent, int koopaPercent, int mushroomPercent);
    void setGrid(int* itemNums);
    void layGrid(char* itemArr);
    bool m_isFinalLevel;
    Mario* m_mario;
    int* m_marioPosition;
};

#endif