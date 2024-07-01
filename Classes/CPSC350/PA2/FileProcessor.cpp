#include "FileProcessor.h"
#include <fstream>
#include <string>
#include <iostream>

//FileProcessor.cpp

/*
-Class to deal with IO for the program
-Reads in input file to read in ints relating to the values of variables that are provided by user
-Functionality to write output to a file
-Method that will take cout statements and write them to file (instead of every cout statement in program needing to be converted to io functionality)

*/
FileProcessor::FileProcessor(){
    txtReader.open("input.txt");
    gameWriter.open("output.txt");
}

FileProcessor::~FileProcessor(){
if (txtReader.is_open())
{
        txtReader.close();
}
if (gameWriter.is_open())
{
        gameWriter.close();
}
}

//Reads in lines from the input file as an array of ints
int* FileProcessor::returnArgs(){
    string arg;
    int* args = new int[8];
    int argIndex = 0;
    while (getline(txtReader, arg)){
        args[argIndex] = stoi(arg);
        argIndex++;
    }

    return args;

}


void FileProcessor::win(){
    gameWriter << "You Win!!!" << endl;
    exit(0);
}

void FileProcessor::gameOver(){
    gameWriter << "Game Over!!!" << endl;
    exit(0);
}

//takes string from user (or other class) and inserts it in output file
void FileProcessor::writeToFile(string message){
    gameWriter << message << endl;
}

//prints grid to file
void FileProcessor::printGrid(char** c, int dimensionSize){
    for (int i = 0; i < dimensionSize; i++)
    {
        for (int j = 0; j < dimensionSize; j++)
        {
            gameWriter << c[i][j];
        }
        gameWriter << endl;
    }
}

//source for help in README
//when called, transfers all following cout statements to be printed to output file instead of terminal
void FileProcessor::redirectCoutToFile(){
    coutToFile = cout.rdbuf();
    cout.rdbuf(gameWriter.rdbuf());
}