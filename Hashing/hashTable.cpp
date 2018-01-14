/** Name: Bailey Payne  ID: brp7vh  Title: hashTable.cpp  Lab: Tuesdays 9:30am **/

#include <iostream>
#include <fstream>
#include "hashTable.h"
#include "primenumber.cpp"
#include <iterator>
#include <cmath>
using namespace std;

/** Constructor **/
hashTable::hashTable(){
  //lst.resize(10);
  unsigned int size = 25000;
  size *= 2;
  getNextPrime(size);
  lst.resize(size);
}

/** Destructor **/
hashTable::~hashTable(){
}

/** Creates the hash function to be called on each insert value **/
int  hashTable::hashFunction(string word){
  //return 10;
  int modVal = 0;
  int val = 0;
  for (int i = 0; i < word.length(); i++){
    val += word[i];
  }
  modVal = val % lst.size();
  return modVal;
 }

//Prints all elements in the hash table
void hashTable::printTable(){
  for (int i = 0; i < lst.size(); i++){
    if (!lst.at(i).empty()){
      for (list<string>::iterator itr = lst.at(i).begin(); itr != lst.at(i).end(); itr++){
	cout << i <<  ' ' << *itr;
      }
      cout << endl;
    }
  }
} 

  /** Inserts a string into the table according to hash function **/
void hashTable::wordInsert(string word){
    unsigned int index = hashFunction(word);
    lst.at(index).push_back(word);
}

  /** Checks to see if a word found in the grid is in the hash table **/
bool hashTable::findWord(string word){
    unsigned int index = hashFunction(word);
    for (list<string>::iterator itr = lst.at(index).begin(); itr != lst.at(index).end(); itr++){
      if (*itr == word){
        return true;
       }
    }
    return false;
}

    
