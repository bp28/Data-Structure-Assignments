/** Name: Bailey Payne  ID: brp7vh  Section: Tuesdays 9:30am **/
// Beginning of Main Written by Another Source (Part of Given Code)

#include <iostream>
#include "heap.h"
#include "huffman_node.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void constructHuffmanTree(huffman_node* root, string s){
  if (root -> left == NULL && root -> right == NULL){
    if (root -> getCharacter() == ' '){
      cout << "space " << s << endl;
    }
    else{
    cout << root -> getCharacter() << " "<< s << endl;
    }
  }
  else if (root -> left != NULL && root -> right == NULL){
    s = s + "0";
    constructHuffmanTree(root -> left, s);
  }
  else if (root -> left == NULL && root -> right != NULL){
    s = s + "1";
    constructHuffmanTree(root -> right, s);
  }
  else{
    constructHuffmanTree(root -> left, s + "0");
    constructHuffmanTree(root -> right, s + "1");
  }
}

int numCompressed = 0;

string convertToCode(huffman_node* root, string s, char c){
  if (root -> left == NULL && root -> right == NULL){
    if (root -> getCharacter() == c){
      return s + " ";
    }
    else{
      return "";
    }
  }
  else if (root -> left != NULL && root -> right == NULL){
    s = s + "0";
    numCompressed++;
    string str = convertToCode(root -> left, s, c);
    return str;
  }
  else if (root -> left == NULL && root -> right != NULL){
    s = s + "1";
    numCompressed++;
    string str = convertToCode(root -> right, s, c);
    return str;
  }
  else{
    string str1 = convertToCode(root -> left, s + "0", c);
    string str2 = convertToCode(root -> right, s + "1", c);
    if (str1 != ""){
      numCompressed++;
      return str1;
    }
    else if (str2 != ""){
      numCompressed++;
      return str2;
    }
    else{
      return "";
  }
  }
}

float calculateTreeCost(huffman_node* root, string s, char c, int numChars, int freq[95]){
  float total = 0.0;
  for (int i = 0; i < 95; i++){
   if (freq[i] != 0){
      for (int i = 0; i <= numChars; i++){
	  s = convertToCode(root, s, c);
	  int bits = s.length();
	  total += (freq[i] * bits) / numChars;
      }
    }
  }
  return total;
}
  
int main (int argc, char **argv) {
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    FILE *fp = fopen(argv[1], "r");
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }

    //cout << endl;
    
    char g;
    while ( (g = fgetc(fp)) != EOF ){
      //cout << g;
    }

    //cout << "----------------------------------------" << endl;

    rewind(fp);

    int frequencies[95];

    for (int i = 0; i < 95; i++){
      frequencies[i] = 0;
    }

    int num;

    while ( (g = fgetc(fp)) != EOF ){
      num = (int) g;
      num = num - 32;
      frequencies[num] = frequencies[num] + 1;
    }

    binary_heap bh;

    int numSymbols = 0;
    int numCharacters = 0;

    for (int i = 0; i < 95; i++){
      //cout << frequencies[i] << endl;
      int ascii = i + 32;
      char c = ascii;
      if (frequencies[i] != 0){
	numSymbols++;
	numCharacters += frequencies[i];
	huffman_node* newNode = new huffman_node::huffman_node(frequencies[i], c);
	//cout << frequencies[i] << endl;
	//cout << c << endl;
	bh.insert(newNode);
      }
    }
    
    while (bh.size() >= 2){
        huffman_node* min1 = bh.findMin(); bh.deleteMin();
	huffman_node* min2 = bh.findMin(); bh.deleteMin();
	int totalFreq = (min1 -> getFrequency()) + (min2 -> getFrequency());
	huffman_node* parent = new huffman_node(totalFreq, ' ');
	parent -> left = min1;
	parent -> right = min2;
	bh.insert(parent);
      }

    constructHuffmanTree(bh.findMin(), "");

    fclose(fp);

    cout << "----------------------------------------" << endl;

    FILE *file = fopen(argv[1], "r");
    if ( file == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }

    char chr;
    while ( (chr = fgetc(file)) != EOF ){
      cout << convertToCode(bh.findMin(), "", chr);
    }
    cout << endl;

    cout << "----------------------------------------" << endl;

    float ratio = (numCharacters * 8.0) / numCompressed;
    float cost = numCompressed * 1.0 / numCharacters;
    
    cout << "There are a total of " << numCharacters << " symbols that are encoded." << endl;
    cout << "There are " << numSymbols << " distinct symbols used." << endl;
    cout << "There were " << numCharacters * 8 << " bits in the original file." << endl;
    cout << "There were " << numCompressed << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << ratio << "." << endl;
    cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl;
    cout << endl;
    
return 0;
}

