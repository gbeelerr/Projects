//DNASeq.cpp
// - Richard Graedon Beeler
// - 2423448
// - beeler @chapman.edu
// - cpsc350 - 02 
// - PA4 - Genetic Palindromes
// - 11 / 1 / 2023

#include "DNASeq.h"
#include <iostream>
#include <string>

using namespace std;

DNASeq::DNASeq()
{
    isValid = false;
}

DNASeq::DNASeq(char *seq)
{
    isValid = true;

    for (int i = 0; i < seq[i] != '\0'; i++)
    {
        char character = seq[i];
        if (isspace(character))
        {
            break;
        }
        if (character != 'A' && character != 'T' && character != 'C' && character != 'G')
        {
            isValid = false;
        }
        sequence.add(i, character);
    }

   // printSequence();
 //   cout << endl;
}
DNASeq::DNASeq(char *seq, int size) 
{
    isValid = true;
    for (int i = 0; i < size; i++)
    {
        char character = seq[i];
        if (isspace(character) || character == '\0')
        {
            break;
        }
        if (character != 'A' && character != 'T' && character != 'C' && character != 'G')
        {
            //cout << character << " is not a dna char" << endl;
            isValid = false;
        }
        sequence.add(i, character);
    }

    //printSequence();
    //cout << endl;
}

DNASeq::~DNASeq()
{
  //  cout << "destructing DNA sequence: ";
}

bool DNASeq::isValidSequence()
{
    return isValid;
}

void DNASeq::printSequence()
{
    for (int i = 0; i < getSequenceSize(); i++)
    {
        cout << sequence.get(i);
    }
   // cout << endl;
}
DNASeq DNASeq::compliment()
{
    // create a char* string that takes the compliment of every char in sequence list
    int stringSize = getSequenceSize();
    //cout << stringSize << endl;

    char *seq = new char[stringSize];
    for (int i = 0; i < stringSize; i++)
    {
        char character = sequence.get(i);
        if (character == 'A')
        {
            seq[i] = 'T';
        }
        else if (character == 'T')
        {
            seq[i] = 'A';
        }
        else if (character == 'C')
        {
            seq[i] = 'G';
        }
        else if (character == 'G')
        {
            seq[i] = 'C';
        }
        else
        {
            throw invalid_argument("DNA can only be represented by 'A','T','C', or 'G'");
        }
    }
    DNASeq d(seq, stringSize);
    delete seq;
    return d;
}

DNASeq DNASeq::substring(int s, int e)
{
    // check if s and e are within bounds
    if (sequence.isEmpty() || s < 0 || e > getSequenceSize())
    {
        throw out_of_range("substring bounds must be within range");
    }
    int substringSize = e - s;
    char *seq = new char[substringSize];
    int seqIndex = 0;
    for (int i = s; i < e; i++)
    {
        seq[seqIndex] = sequence.get(i);
        seqIndex++;
    }
    DNASeq d(seq, seqIndex);
    delete seq;
    return d;
}

bool DNASeq::isGeneticPalindrome()
{
    DNASeq seqCompliment = compliment();
    for (int i = 0; i < getSequenceSize(); i++)
    {
        if (sequence.get(i) != seqCompliment.getSequenceChar(getSequenceSize() - (i + 1)))
        {
            return false;
        }
    }
    return true;
}

int DNASeq::getSequenceSize()
{
    return sequence.getSize();
}

DblList<char> DNASeq::getSequence()
{
    return sequence;
}

char DNASeq::getSequenceChar(int index)
{
    return sequence.get(index);
}


