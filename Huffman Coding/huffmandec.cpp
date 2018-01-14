/** Name: Bailey Payne  ID: brp7vh  Section: Tuesdays 9:30am **/
// First Part of Main was Written by Another Source (Part of Given Code)

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "huffman_node.h"
#include <string>
using namespace std;

void treeFromCodes(huffman_node* root, string code, char c){
  code = code.c_str();
  for (int i = 0; i < code.size(); i++){
    if (code[i] == '0' && root -> left == NULL){
      huffman_node* newNode = new huffman_node(0, '~');
      //cout << " -> left" << endl;
      root -> left = newNode;
      root = newNode;
    }
    if (code[i] == '0' && root -> left != NULL){
      //cout << "-> left" << endl;
      root = root -> left;
    }
    if (code[i] == '1' && root -> right == NULL){
      huffman_node* newNode = new huffman_node(0, '~');
      //cout << " -> right" << endl;
      root -> right = newNode;
      root = newNode;
  }
    if (code[i] == '1' && root -> right != NULL){
      //cout << " -> right" << endl;
      root = root -> right;
    }
}
  root -> setCharacter(c);
  //cout << root -> getCharacter() << endl;
}

void convertCodeToChar(huffman_node* root, string code){
  huffman_node* temp = root;
  code = code.c_str();
  for (int i = 0; i <= code.size(); i++){
    if (temp -> left == NULL && temp -> right == NULL){
      cout << temp -> getCharacter();
      temp = root;
    }
    if (temp -> left != NULL && code[i] == '0'){
       temp = temp -> left;
      }
    if (temp -> right != NULL && code[i] == '1'){
       temp = temp -> right;
      }
}
}


int main (int argc, char **argv) {

  //cout << endl;
 
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
   
    ifstream file(argv[1], ifstream::binary);
   
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in the first section of the file: the prefix codes
    huffman_node* root = new huffman_node(0, '~');
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
	char chr = character[0];
        // do something with the prefix code
	treeFromCodes(root, prefix, chr);
	//cout << convertCodeToChar(root, prefix);
    }

    //cout << endl;

    
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' ){
            break;
	}
        // add it to the stringstream
        sstm << bits;
    }
    
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    //cout << "-----------------------------------------" << endl;
    convertCodeToChar(root, allbits);
    //cout << endl;
  
    
    // close the file before exiting
    file.close();

    cout << endl;
}

