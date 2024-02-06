// PalindromeFinder.cpp
//  - Richard Graedon Beeler
//  - 2423448
//  - beeler @chapman.edu
//  - cpsc350 - 02
//  - PA4 - Genetic Palindromes
//  - 11 / 1 / 2023

#include "DNASeq.h"
#include "PalindromeFinder.h"
#include "DblList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

PalindromeFinder::PalindromeFinder(string inputFile)
{
    if (!reader.is_open())
    {
        try
        {
            reader.open(inputFile);
        }
        catch (...)
        {
            cerr << "Error opening file" << endl;
            exit(0);
        }
    }
}

PalindromeFinder::~PalindromeFinder()
{
    if (reader.is_open())
    {
        reader.close();
    }
}

void PalindromeFinder::analyzeForPalindromes()
{
    string line;
    // if (getline(reader, line))
    while (getline(reader, line))
    {
        if (line == "END")
        {
            return;
        }

        DNASeq dnaSequence = makeDNASeq(line);
        dnaSequence.printSequence();
        if (dnaSequence.isValidSequence())
        {
            bool lineIsPalindrome = isPalindrome(dnaSequence);
            if (lineIsPalindrome)
            {
                cout << " is genetic palindrome" << endl;
            }
            else
            {
                cout << " is not genetic palindrome" << endl;
            }
            cout << "Substring palindromes: " << endl;
            checkSubstringsForPalindromes(dnaSequence);
            cout << endl;
        }
        else
        {
            cout << " is not valid DNA sequence" << endl;
            cout << endl;
        }
    }
}

DNASeq PalindromeFinder::makeDNASeq(string line)
{
    char *lineToCharString = const_cast<char *>(line.c_str());
    DNASeq d(lineToCharString);
    return d;
}

bool PalindromeFinder::isPalindrome(DNASeq d)
{
    return d.isGeneticPalindrome();
}

/*
Plan:
-we will check substrings and print in order in the same nested loop for efficiency (and to avoid having to sort and array and list just to print)
-because we are printing from smallest to largest, the outer loop will determine the length of the substring that we are looking for
and the inner loop will analyze each valid substring of that size
*/
void PalindromeFinder::checkSubstringsForPalindromes(DNASeq fullSequence)
{
    // first check if DNA seq is 4 or less, then there are no DNA substrings. If it is 5, there is no substring that isnt the exact same as full string, so same applies
    int fullSequenceSize = fullSequence.getSequenceSize();
    if (fullSequenceSize <= 5)
    {
        return;
    }

    // make a DNASeq for each substring and check if its a genetic palindrome
    // nested for loop, start from front
    //int largestSubstringStartIndex = fullSequenceSize - 5;
  //  std::cout << "largest substring index: " << largestSubstringStartIndex << endl;
    for (int i = 5; i < fullSequenceSize; i++)
    { // iterate through all possible sizes of substring, 5 being the smallest (according to directions)
        int numPossibleSubstringsOfSizeI = fullSequenceSize - i;
        for (int j = 0; j <= numPossibleSubstringsOfSizeI; j++)
        { // from the back, it will decrease how far the substring goes to (int e), until the length is 5 from int s to int e
            DNASeq substringSequence = fullSequence.substring(j, i + j);
            if (substringSequence.isGeneticPalindrome())
            {
                substringSequence.printSequence();
                cout << endl;
            }
        }
    }
    // return;
    // exit(0);
}

