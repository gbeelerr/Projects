#ifndef WORLD_H
#define WORLD_H

#include "Level.h"
#include "Mario.h"

class World{

public:
    World();
    //World(Level L, int numLevels);
    World(int numLevels, int dimensionSize, int numLives, int coinPercent, int nothingPercent, int goombaPercent, int koopaPercent, int mushroomPercent);
    virtual ~World();
    void printWorld();
    void playLevels();
    void interact(char item);


private:
    Level* m_levels;
    Mario* m_mario;
    int m_numLevels;
    int m_dimensionSize;
    int m_currLevelIndex;
    int m_lastLevelIndex;
    int totalMoves;
    bool shouldAdvanceMario;
    bool shouldReturnEnemy;
    bool shouldAdvanceLevel;
    void interactWarp();
    void interactBoss();
};

#endif