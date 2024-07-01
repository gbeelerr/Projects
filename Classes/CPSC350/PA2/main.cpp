#include "Mario.h"
#include "Level.h"
#include "World.h"
#include "FileProcessor.h"
#include <iostream>

using namespace std;

int main(){
    srand(time(0));

    FileProcessor f;
    int *args = f.returnArgs();
    for (int i = 0; i < 8; i++)
    {
        cout << args[i] << endl;
    }

    f.redirectCoutToFile();

    int numLevels = args[0];
    int dimensionSize = args[1];
    int numLives = args[2];
    int coinPercent = args[3];
    int nothingPercent = args[4];
    int goombaPercent = args[5];
    int koopaPercent = args[6];
    int mushroomPercent = args[7];
  
   World w(numLevels,dimensionSize,numLives,coinPercent,nothingPercent,goombaPercent,koopaPercent,mushroomPercent);

   w.printWorld();
   for (int i = 0; i < numLevels; ++i){
    w.playLevels();
   }
   
    return 0;
};