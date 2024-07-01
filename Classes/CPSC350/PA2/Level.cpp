#include "Level.h"
#include "Mario.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <random>


using namespace std;
//Level.cpp

/*
Creates visual depiction of Mario simulation in the form of a 2D array, and tracks Mario as he travels through the grid
Member variables:
-m_grid - 2D array of chars, which will be displayed as a grid, and where each char represents an item in the game
-m_dimensionSize - an integer representing the length/width of the 2D array (it will always be a square array)
-m_totalSquares - an integer representation of the total elements in the 2D array. Since length and width are equal, it is dimension size squared
-m_isFinalLevel - a boolean to determine whether the level created is a final level. Final levels do not contain warp pipes
-m_Mario - a Mario object created from Mario.cpp that is inserted in the level
-m_marioPosition - an array of two ints that store an x and y value relative to Mario will be placed on the grid


*/
Level::Level(){
    m_mario = new Mario();  
    m_isFinalLevel = false;
    m_dimensionSize = 10;
    //m_grid = nullptr;
    createGrid();
    m_totalSquares = m_dimensionSize * m_dimensionSize;
    initializeDefaultGrid();
    m_marioPosition = new int[2];
    m_marioPosition[0] = rand() % m_dimensionSize;
    m_marioPosition[1] = rand() % m_dimensionSize;
}


Level::Level(bool isFinalLevel, int lives, int dimensionSize, int coinPercent, int mushroomPercent, int goombaPercent, int koopaPercent, int nothingPercent, Mario* marioPt)
{
    m_isFinalLevel = isFinalLevel;
    m_mario = marioPt;
    //m_grid = nullptr;
    m_dimensionSize = dimensionSize;
    createGrid();
    m_totalSquares = m_dimensionSize * m_dimensionSize;
    if (!((coinPercent + nothingPercent + goombaPercent + koopaPercent + mushroomPercent) == 100)){
        throw logic_error("Percentages of items must add to 100");
    }else{
        int* itemsArr = setItemNums(coinPercent, mushroomPercent, goombaPercent, koopaPercent, nothingPercent);
        setGrid(itemsArr);
       delete[] itemsArr;
    }
    m_marioPosition = new int[2];
    m_marioPosition[0] = rand() % m_dimensionSize;
    m_marioPosition[1] = rand() % m_dimensionSize;
}


Level::~Level()
{
    
    for (int i = 0; i < m_dimensionSize; i++){
       delete[] m_grid[i];
    }
   delete[] m_grid;
   delete[] m_marioPosition;
  
}

//dynamically allocates chars to given size for the 2d array
//-values will start at null - they have not been instantiated yet
void Level::createGrid(){
    m_grid = new char*[m_dimensionSize];
    for (int i = 0; i < m_dimensionSize; ++i)
    {
        m_grid[i] = new char[m_dimensionSize];
    }
}

//creates nxn grid of "empty" (for the purpose of the game) characters (x)
void Level::initializeDefaultGrid(){
    for (int i = 0; i < m_dimensionSize; ++i){
        for(int j = 0; j < m_dimensionSize; ++j){
            m_grid[i][j] = 'x';
        }
    }

}

//prints grid to console, with every outside element (an array of chars) printed to a new line
void Level::printGrid(){
    for (int i = 0; i < m_dimensionSize; i++){
        for (int j = 0; j < m_dimensionSize; j++){
            cout << m_grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

//returns pointer to the created array
char** Level::getGrid(){
    return m_grid;
}

//takes the percentages of items passed as parameters, and converts them to a number (based on how many total squares there are)
//returns an array of integers representing number of each element that will be included in array
int* Level::setItemNums(int coinPercent, int mushroomPercent, int goombaPercent, int koopaPercent, int nothingPercent)
{
    int* itemArr = new int[5];
    int totalSquaresUsed=0;

    double coinDecimal = coinPercent * 0.01;
    int numCoins = static_cast<int>(coinDecimal * m_totalSquares);
    totalSquaresUsed += numCoins;
    itemArr[0] = numCoins;

    double mushroomDecimal = mushroomPercent * 0.01;
    int numMushrooms = static_cast<int>(mushroomDecimal * m_totalSquares);
    totalSquaresUsed += numMushrooms;
    itemArr[1] = numMushrooms;

    double goombaDecimal = goombaPercent * 0.01;
    int numGoombas = static_cast<int>(goombaDecimal * m_totalSquares);
    totalSquaresUsed += numGoombas;
    itemArr[2] = numGoombas;

    double koopaDecimal = koopaPercent * 0.01;
    int numKoopas = static_cast<int>(koopaDecimal * m_totalSquares);
    totalSquaresUsed += numKoopas;
    itemArr[3] = numKoopas;

    int numNothingSquares = m_totalSquares - totalSquaresUsed;
    totalSquaresUsed += numNothingSquares;
    itemArr[4] = numNothingSquares;

    return itemArr;
   
}

//takes the array of the number of items alloted as a parameter. Returns void but calls a method that takes a 1d char array of shuffled items
//goes one by one (item) to insert all the characters (c = coin, m = mushroom, g = goomba, k = koopa, x = empty square) in the grid corresponding to the items
//once they are all inserted, uses random seeding with std::mt19937 and std::shuffle to randomize location of items 
//then one boss ('B') and if it isnt the last level, one warp ('W') randomly on the grid (there is a check to make sure they dont end up on the same position)

void Level::setGrid(int* itemNums){

    int remainingCoins = itemNums[0];
    int remainingMushroom = itemNums[1];
    int remainingGoombas = itemNums[2];
    int remainingKoopas = itemNums[3];
    int remainingEmpty = itemNums[4];

    char* itemArrInOneD = new char[m_totalSquares];
    for (int i = 0 ; i < m_totalSquares; i++){
        if (remainingCoins > 0){
            itemArrInOneD[i] = 'c';
            remainingCoins --;
        }else if (remainingMushroom > 0){
            itemArrInOneD[i] = 'm';
            remainingMushroom --;
        }else if (remainingGoombas > 0){
            itemArrInOneD[i] = 'g';
            remainingGoombas--;
        }else if (remainingKoopas > 0){
            itemArrInOneD[i] = 'k';
            remainingKoopas--;
        }else{
            itemArrInOneD[i] = 'x';
        }
    }
    random_device randy;
    mt19937 gen(randy());
    shuffle(itemArrInOneD,itemArrInOneD + m_totalSquares, randy);

    //place boss anywhere between 0 - len-1
    int bossLocation = rand() % m_totalSquares;
    itemArrInOneD[bossLocation] = 'B';

    //place warp anywhere besides where boss is (assuming not last level)
    if (m_isFinalLevel == false){
        int warpLocation = -1; //would throw out of bounds on itemArrInOneD[warpLocation] 
        while ((warpLocation == bossLocation) || (warpLocation == -1)){
            warpLocation = rand() % m_totalSquares;
        }
        itemArrInOneD[warpLocation] = 'W';
    }
    
    layGrid(itemArrInOneD);
   delete[] itemArrInOneD;
}

//takes one dimension array of all the items, and divides it into increments of dimension size to input into the 2d char array (member variable)
void Level::layGrid(char* itemArr){
    int indexCount = 0;
    for (int i = 0; i < m_dimensionSize; i++ ){
        for (int j = 0; j < m_dimensionSize; j++){
            m_grid[i][j] = itemArr[indexCount];
            indexCount ++;
        }
    }
}


//takes parameters for x and y grid coordinates as int and single char to mutate the 2d grid at that coordinate to the new char
void Level::changeGridVal(int x, int y, char inputChar){
    m_grid[y][x] = inputChar;
}

//takes parameters for x and y grid coordinates as ints, and changes that char value to 'x' (empty)
void Level::emptyGridVal(int x, int y){
    m_grid[y][x] = 'x';
}



//takes the location of Mario's coordinates, and actually places a textual representation of him 'H' on the level grid
void Level::placeMario(){
    m_grid[m_marioPosition[1]][m_marioPosition[0]] = 'H';
}

//calls Mario's function that chooses a direction randomly and changes Mario's position by one in that direction
//functionality for wrapping accross map so Mario can always move in any direction
void Level::moveMario(){
    int moveDir = m_mario->move();
    //edge cases for wrap
    //if the movement is left, and mario is at pos (m_grid[x][0]), then new position would be m_grid[x][dimensionSize - 1]
    //if the movement is right, and mario is at pos  (m_grid[x][dimensionSize - 1]), then new position would be m_grid[x][0]
    //if the movement is up, and mario is at pos (m_grid[0][x]), then new position would be m_grid[dimensionSize-1][x]
    //if the movement is down, and mario is at m_grid[dimensionSize - 1][x] then new position would be m_grid[0][x]
    switch (moveDir){
        case 0: //left
        cout << " Next: LEFT" << endl;
        if (m_marioPosition[0] == 0)
        {
            m_marioPosition[0] = m_dimensionSize - 1;
           // cout << "wrapped left";
            }else{
                m_marioPosition[0] --;
              //  cout << "went left";
            }
            break;

        case 1: //right
            cout << " Next: RIGHT" << endl;
            if(m_marioPosition[0] == (m_dimensionSize - 1)){
                m_marioPosition[0] = 0;
              //  cout << "wrapped right";
            }else{
                m_marioPosition[0] ++;
               // cout << "went right";
            }
            break;

        case 2: //up
            cout << " Next: UP" << endl;
            if (m_marioPosition[1] == 0){
                m_marioPosition[1] = m_dimensionSize - 1;
               // cout << "wrapped up";
            }else{
                m_marioPosition[1] --;
               // cout << "went up";
            }
            break;


        case 3: //down
            cout << " Next: DOWN" << endl;
            if (m_marioPosition[1] == (m_dimensionSize - 1)){
                m_marioPosition[1] = 0;
                //cout << "wrapped down";
            }else{
                m_marioPosition[1] ++;
              //  cout << "went down";
            }
            break;


        default:
            cout << "error";
            break;
    }
}

//accessor
int Level::getDimensionSize(){
    return m_dimensionSize;
}

//accessor
char Level::getCurrentChar(){
    return m_grid[m_marioPosition[1]][m_marioPosition[0]];
}

//accessor
Mario* Level::getMario(){
    return m_mario;
}

// accessor
bool Level::isFinalLevel()
{
    return m_isFinalLevel;
}

// mutator
void Level::setFinalLevel(bool isFinalLevel)
{
    m_isFinalLevel = isFinalLevel;
}

// accessor
int *Level::returnCurrGridVal()
{
    return m_marioPosition;
}

// mutator
void Level::setMarioPosition(int x, int y)
{
    m_marioPosition[0] = x;
    m_marioPosition[1] = y;
}
