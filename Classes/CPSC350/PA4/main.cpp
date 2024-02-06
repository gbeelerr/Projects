#include "PalindromeFinder.h"
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        PalindromeFinder p(argv[1]);
        p.analyzeForPalindromes();
    }
    else
    {
        cout << "Enter a valid file input in command line argument" << endl;
        return 0;
    }

    return 0;
}