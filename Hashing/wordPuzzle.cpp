/** Name: Bailey Payne  ID: brp7vh  Title: wordPuzzle.cpp  Lab: Tuesdays 9:30am **/
/** Timer of 300x300 Grid for preoptimized run: 9.04972 seconds **/
/** Timer of 300x300 Grid for optimized run: 0.375753 seconds **/
/** Big-Theta Running Time: (rows * cols * words) **/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "hashTable.h"
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);

bool readInGrid (string filename, int &rows, int &cols) {
    string line;
    ifstream file(filename.c_str());
    if ( !file.is_open() )
        return false;
    file >> rows;
    cout << "There are " << rows << " rows." << endl;
    getline (file,line);
    file >> cols;
    cout << "There are " << cols << " cols." << endl;
    getline (file,line);
    getline (file,line);
    file.close();
    int pos = 0;
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
            //cout << grid[r][c];
        }
        cout << endl;
    }
    return true;
}

char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    static char output[256];
    if ( len >= 255 )
        len = 255;
    int pos = 0, r = startRow, c = startCol;
    for ( int i = 0; i < len; i++ ) {
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        output[pos++] = grid[r][c];
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    output[pos] = 0;
    return output;
}

int main(int argc, char* argv[]){
  hashTable theTable;
  hashTable pfxTable;

  ifstream dict(argv[1]);
  string word;
  while (getline(dict, word)){
    if (word.length() > 2) {
      theTable.wordInsert(word);
    }
    string str =  word.substr(0, 3);
    pfxTable.wordInsert(str);
  }
  //pfxTable.printTable();
  //theTable.printTable();

  //cout << theTable.findWord("nanotech") << endl;
  
  int rows, cols;
  bool result = readInGrid(argv[2], rows, cols);
  
  if (!result){
    cout << "Error reading in file!" << endl;
    exit(1);
 }
  
  string preWord = "";
  int count = 0;

  timer t;
  t.start();

  for (int x = 0; x < rows; x++){
    for (int y = 0; y < cols; y++){
      //cout << x << "," << y << endl;
      for (int d = 0; d <= 7; d++){
        for (int l = 3; l < 23; l++){
	  string word = getWordInGrid(x,y,d,l,rows,cols);
	  if (word.length() != l){
	    break;
	  }
	  else if (l == 3){
	    if (!pfxTable.findWord(word)){
	       break;
	    }
	  }
	    if (theTable.findWord(word)){
	  
	    count++;
 
	    switch (d){
            case 0:
	      cout << "N (" << x << ", " << y << "): " << word << endl;
                break;
            case 1:
	      cout << "NE (" << x << ", " << y << "): " << word << endl;
                break;
            case 2:
	      cout << "E (" << x << ", " << y << "): " << word << endl;
                break;
            case 3:
	      cout << "SE (" << x << ", " << y << "): " << word << endl;
                break;
            case 4:
	      cout << "S (" << x << ", " << y << "): " << word << endl;
                break;
            case 5:
	      cout << "SW (" << x << ", " << y << "): " << word << endl;
                break;
            case 6:
	      cout << "W (" << x << ", " << y << "): " << word << endl;
                break;
            case 7:
	      cout << "NW (" << x << ", " << y << "): " << word << endl;
                break;
	    }
	  }
	}
      }
    }
  }
  
  cout << "Word Count: " << count << endl;
	    
  t.stop();
  cout << "Found all words in " << t << " seconds" << endl;

  int tyme = (t.getTime() * 1000);
  
  cout << tyme << endl;

  return 0;
}

