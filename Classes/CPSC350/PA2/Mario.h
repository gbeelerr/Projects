#ifndef MARIO_H
#define MARIO_H

#include "FileProcessor.h"

class Mario{

public:
Mario();
Mario(int lives);
virtual ~Mario();
int getLives();
int getCoins();
int getPowerLevel();
void setLives(int lives);
void setCoins(int coins);
void setPower(int power);
void interactCoin();
void interactMushroom();
bool interactGoomba();
bool interactKoopa();
bool shouldAdvance();
int move(); //returns a number for which direction is chosen for Mario to move



private:
int m_lives;
int m_coins;
int m_powerLevel;
int consecutiveEnemies;
void updateCoins();
void beatsEnemy();
void defeatedByEnemy();

};

#endif