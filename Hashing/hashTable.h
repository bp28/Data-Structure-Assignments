/** Name: Bailey Payne  ID: brp7vh  Title: hashTable.h  Lab: Tuesdays 9:30am**/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class hashTable{

 public:

//Constructor
hashTable();

//Destructor
~hashTable();

//Hash Function
int hashFunction(string word);

//Insert
void wordInsert(string word);

//Find
bool findWord(string word);

//Print Table
void printTable();

private:
   vector< list<string> > lst;

};

#endif

