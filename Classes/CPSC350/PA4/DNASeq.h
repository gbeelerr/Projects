// DNASeq.h
//  - Richard Graedon Beeler
//  - 2423448
//  - beeler @chapman.edu
//  - cpsc350 - 02
//  - PA4 - Genetic Palindromes
//  - 11 / 1 / 2023
#ifndef DNA_SEQ_H
#define DNA_SEQ_H
#include "ListNode.h"
#include "DblList.h"

class DNASeq{

public:
DNASeq();
DNASeq(char* string, int size);
DNASeq(char* string);
virtual ~DNASeq();
bool isGeneticPalindrome();
DNASeq compliment();
DNASeq substring(int s, int e);
void printSequence();
int getSequenceSize();
DblList<char> getSequence();
char getSequenceChar(int index);
bool isValidSequence();

private:
bool isValid;
bool m_isGeneticPalindrome;
DblList<char> sequence;
};









#endif
