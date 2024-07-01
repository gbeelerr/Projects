#include "Mario.h"
#include "FileProcessor.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Mario object:
/*
-character in the game, carried (through pointers) through Levels and also World
-member variables
    -m_lives = Total lives Mario currently has. User defines how much he starts with, and then interactions through the game determine if that number increases or decreases
    -m_coins = total coins mario has collected. If Mario reaches 20 coins, his coins are reset and he recieves one extra life
    -m_powerLevel = Starts at 0, and maxes at 2. When Mario collects a mushroom, he recieves an increase in power. Instead of lives lost, enemies will take away power level first
    -consecutiveEnemies = Tracks how many enemies Mario has defeated on the same life. If this number reaches 7, Mario recieves an extra life and the number resets
*/
Mario::Mario(){
    m_coins = 0;
    m_powerLevel = 0;
    m_lives = 3;
   
}

Mario::Mario(int lives){
    m_coins = 0;
    m_powerLevel = 0;
    m_lives = lives;
    
}

Mario::~Mario(){
    
}

int Mario::getLives(){
    return m_lives;
}
int Mario::getCoins(){
    return m_coins;
}
int Mario::getPowerLevel(){
    return m_powerLevel;
}
void Mario::setLives(int lives){
    m_lives = lives;
}

void Mario::setCoins(int coins)
{
    m_coins = coins;
}

void Mario::setPower(int power)
{
    m_powerLevel = power;
}


//if mario interacts with a coin, it will be printed, coins will increase, and a function will check if 20 coins have been reached
void Mario::interactCoin(){
    cout << "Mario collected a coin";
    m_coins ++;
    updateCoins();
}

//as long as the power is not already 2, interactMushroom will increase Mario's power level by 1
void Mario::interactMushroom(){
    cout << "Mario ate a mushroom";
    if (m_powerLevel < 2){
        m_powerLevel ++;
    }
}

//returns boolean representation of whether or not Mario defeated Goomba
//If the randomly generated number is 0,2,3, or 4, Mario wins
    //if its 1, Goomba wins
//This creates an 80% probability of Mario defeating Goomba each interaction
bool Mario::interactGoomba()
{
    int goombaWins = rand() % 5;
    if (goombaWins != 1){
        cout << "Mario fought a goomba and won" ;
        beatsEnemy();
        return true;
    }else{
        cout << "Mario fought a goomba and lost" ;
        defeatedByEnemy();
        return false;
    }

}

// returns boolean representation of whether or not Mario defeated Koopa
// If the randomly generated number is 0 or 1,  Mario wins
// If its 2, Koopa wins
// This creates roughly 65% probability of Mario defeating Koopa each interaction
bool Mario::interactKoopa()
{
    int koopaWins = rand() % 3;
    if(koopaWins != 2){
        cout << "Mario fought a koopa and won" ;
        beatsEnemy();
        return true;
    }else{
        cout << "Mario fought a koopa and lost";
        defeatedByEnemy();
        return false;
    }
}


//Adds life if coin count has reached 20 when called
//Coins resets to 0 after
void Mario::updateCoins(){
    if (m_coins == 20){
        m_lives ++;
        m_coins = 0;
        cout << " (20 coins --> 1-UP) ";
    }
}

//when Mario beats Goomba or Koopa, consecutive enemies is incremented
//if that number reaches 7 without a life being lost, mario recieves an extra life
void Mario::beatsEnemy(){
    consecutiveEnemies++;
    if (consecutiveEnemies == 7){
        m_lives++;
        consecutiveEnemies = 0;
        cout << " (7 consecutive enemies --> 1-UP) " ;
    }
}

//When Mario is defeated by Goomba or Koopa
//if PL-1 or PL-2, then power is decremented
//if PL-0, and Mario has more than one life left, lives is decremented by one
//if he was on his last life, the game is over, and an exit() statement is called to break out of any loops that were going when this method was called
void Mario::defeatedByEnemy(){
    if(m_powerLevel > 0){
        m_powerLevel --;
    }else{
        if(m_lives > 1){
            m_lives --;
            consecutiveEnemies = 0;
        }else{
            cout<< " Game over ";
            exit(0);
        }
    }
}




//chose a number 0-3 randomly which correlates to a direction
/*
0 - left
1 - right
2 - up
3 - down
*/

int Mario::move(){
    return (rand() % 4);

}



