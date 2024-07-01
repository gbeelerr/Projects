#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include <fstream>

using namespace std;

class FileProcessor
{
public:
    FileProcessor();
    virtual ~FileProcessor();
    void gameOver();
    void win();
    void printGrid(char **grid, int dimesionLength);
    int *returnArgs();
    void writeToFile(string message);
    void redirectCoutToFile();


private:
    ifstream txtReader;
    ofstream gameWriter;
    streambuf* coutToFile;
};

#endif
