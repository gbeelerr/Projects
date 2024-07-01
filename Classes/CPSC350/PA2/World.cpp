#include "World.h"
#include "Level.h"
#include "Mario.h"
#include "FileProcessor.h"
#include <string>
#include <iostream>

using namespace std;
//World.cpp
//World houses the bulk of the game, including the gameloop
//also contains a chunk of the game logic

//Member variables
/*

-Level* m_levels: An array of levels in which Mario must traverse through to beat the game
-Mario* m_mario: The Mario object pointer that is passed through each level
-int m_numLevels: an integer representing total number of levels Mario must play to win
-m_dimensionSize - an integer representing the length/width of each 2D array in m_levels
-int m_currLevelIndex - an integer representing the current level (starts at 0 but adjusted in print statements)
-int m_lastLevelIndex - integer representing the final level index in the world
-int totalMoves - increments for every move Mario makes in the world until the game is finished (won or lost)
-bool shouldAdvanceMario - true when Mario will not stay put for the next move
-bool shouldAdvanceLevel - true when Mario defeats a boss or hits a warp

*/

World::World()
{
    totalMoves = 0;
    m_levels = new Level[3];
    m_numLevels = 3;
    m_currLevelIndex = 0;
    m_lastLevelIndex = 2;
    m_dimensionSize = m_levels->getDimensionSize();
    shouldAdvanceMario = false;
    shouldAdvanceLevel = false;
    shouldReturnEnemy = false;
    m_mario = m_levels->getMario();
    //cout << "finished def";
}

/*World::World(Level L, int numLevels)
{
    m_numLevels = numLevels;
    m_lastLevelIndex = numLevels - 1;
    m_levels = new Level[numLevels];
    for (int i = 0; i < numLevels; i++)
    {
        m_levels[i] = L;
    }
    m_mario = L.getMario();
}
*/

//overloaded constructor given all the information that is read from the file
World::World(int numLevels, int dimensionSize, int numLives, int coinPercent, int nothingPercent, int goombaPercent, int koopaPercent, int mushroomPercent)
{
    m_dimensionSize = dimensionSize;
    shouldAdvanceMario = false;
    shouldAdvanceLevel = false;
    shouldReturnEnemy=false;
    totalMoves = 0;
   m_numLevels = numLevels;
   m_currLevelIndex = 0;
   m_lastLevelIndex = numLevels - 1;
   m_levels = new Level[numLevels];
   m_mario = new Mario(numLives);
   for (int i = 0; i < numLevels; i++)
   {
       if (i == m_lastLevelIndex)
       {
           new (&m_levels[i]) Level(true, numLives, dimensionSize, coinPercent, nothingPercent, goombaPercent, koopaPercent, mushroomPercent, m_mario);
       }
       else
       {
           new (& m_levels[i]) Level(false, numLives, dimensionSize, coinPercent, nothingPercent, goombaPercent, koopaPercent, mushroomPercent, m_mario);
        }
    }
    
}

World::~World()
{
   delete[] m_levels;
   delete m_mario;
}

void World::printWorld()
{
    for (int i = 0; i < m_numLevels; i++)
    {
        m_levels[i].printGrid();
        cout << endl;
    }
}

//main gameloop
//each loop is one level 
void World::playLevels()
{
    shouldAdvanceLevel = false;
    if (m_currLevelIndex != 0){
        m_levels[m_currLevelIndex].setMarioPosition(rand() % m_dimensionSize, rand() % m_dimensionSize );
    }

    while (shouldAdvanceLevel == false)
    {
        totalMoves ++;

        // read char mario is now on
        // put mario on grid
        // interact with item
        // determine if mario should move
        // move mario (if applicable)
        //current level status print (before move)
        cout << "Level: " << m_currLevelIndex + 1 << " "; //adjusts level so it starts on level 1
        int *tempPos = new int[2];
        int* gridVal = m_levels[m_currLevelIndex].returnCurrGridVal();
        tempPos[0] = gridVal[0];
        tempPos[1] = gridVal[1];
        cout << "Position: (" << tempPos[0] << "," << tempPos[1] << ") " ;
        char tempChar = m_levels[m_currLevelIndex].getCurrentChar();
        cout << " char: " << tempChar << " ";
        m_levels[m_currLevelIndex].placeMario();
        cout << "Power: PL" << m_mario->getPowerLevel() << " ";
        interact(tempChar);
        cout << " Lives: " << m_mario->getLives();
        cout << " Coins: " << m_mario->getCoins();
        if(shouldAdvanceMario == true){
            m_levels[m_currLevelIndex].moveMario();
            m_levels[m_currLevelIndex].printGrid();
            if (shouldReturnEnemy == true){
                m_levels[m_currLevelIndex].changeGridVal(tempPos[0],tempPos[1],tempChar);
            }else{
            m_levels[m_currLevelIndex].emptyGridVal(tempPos[0], tempPos[1]);
            }
        }else{
            cout << " Next: STAY PUT" << endl;
            m_levels[m_currLevelIndex].printGrid();
            m_levels[m_currLevelIndex].changeGridVal(tempPos[0],tempPos[1], tempChar);
        }
        shouldAdvanceMario = false;
        shouldReturnEnemy = false;
       delete[] tempPos;
    }
    
}


//determines how the program interprets what Mario is supposed to do when he encounters an item (or any space in general)
void World::interact(char item)
{
    bool beatGoomba = false;
    bool beatKoopa = false;
    
    switch (item)
    {
    case 'c': //interact with coin using method from Mario.cpp. Mario should advance after collecting coin
        m_mario->interactCoin();
        shouldAdvanceMario = true;
        break;
    case 'g': //interact with goomba using method from Mario.cpp. interactGoomba returns a boolean based on whether Mario won or not. Mario will only advance if defeating goomba
        beatGoomba = m_mario->interactGoomba();
         if (beatGoomba == false)
         {
          shouldReturnEnemy = true;
        }
            shouldAdvanceMario = true;
            break;
    case 'k':
        beatKoopa = m_mario->interactKoopa(); // interact with koopa using method from Mario.cpp. interactKoopa returns a boolean based on whether Mario won or not. Mario will only advance if defeating koopa
         if (beatKoopa == false)
         {
            shouldReturnEnemy = true;
         }
        shouldAdvanceMario = true;
        break;
    case 'm': //interact with mushroom using method from Mario.cpp. Should advance after collecting
        m_mario->interactMushroom();
        shouldAdvanceMario = true;
        break;
    case 'B': //interact with Boss using interactBoss() method. Result is determined based on logic from that methof
        interactBoss();
        break;
    case 'W': //interact with warp using interactWarp(), which will send Mario to the next level
        interactWarp();
        break;

    case 'x': //interact with 'x' by simply advancing
        cout << "The position is empty";
        shouldAdvanceMario = true;
        
        break;
    default: //
        break;
    }
}

//warp instantly sends Mario to the next level
void World::interactWarp()
{
    cout << "Mario warped";
    m_currLevelIndex++;
    shouldAdvanceLevel = true;
    shouldAdvanceMario = true;
}

//Boss logic:
//50% chance Mario wins

//If he wins:
//If it was the last level - Mario wins the game
//If not, Mario will advance to next level index

//If he is defeater:
//If Mario power level was at 2, he keeps his lives but power goes to 0
//If Mario doesnt have PL2, he loses a life
//Mario will stay in the same position and fight again
//If Mario didn't have a life left to lose, the game is over and Mario loses - Game Over

void World::interactBoss()
{
    int bossWins = rand() % 2;
    if (bossWins == 0)
    {
        // boss wins
        cout << "Mario fought boss and lost ";
        if (m_mario->getPowerLevel() == 2)
        {
            m_mario->setPower(0);
            shouldAdvanceMario = false;
        }
        else if (m_mario->getLives() > 1)
        {
            m_mario->setLives(m_mario->getLives() - 1); //decrement lives by one
            m_mario->setPower(0); //set power to 0
            shouldAdvanceMario = false;
        }
        else //mario had one life left, now has 0
        {
            
            cout << " Game Over "  << "Total Moves: " << totalMoves;
            exit(EXIT_FAILURE);
        }
    }
    else //mario wins
    {
        cout << " Mario defeated boss! ";
        if (m_currLevelIndex == m_lastLevelIndex) //if its the last level, beating the boss results in mario beating the game
        {
            cout << " Mario Wins " << "Total Moves: " << totalMoves;
            exit(EXIT_SUCCESS);
        }
        else //mario advances to next level
        {
            cout << "Mario advancing...";
            m_currLevelIndex++;
            shouldAdvanceLevel = true;
            shouldAdvanceMario = true;
            
        }
    }
}

