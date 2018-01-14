/* Name: Bailey Payne  ID: brp7vh  Section: Tuesdays 9:30am */

#include <iostream>
#include "huffman_node.h"
#include <stdlib.h>

using namespace std;

huffman_node::huffman_node(int freq, char chr){
  frequency = freq;
  character = chr;
  left = NULL;
  right = NULL;
}

huffman_node::~huffman_node(){
}

int huffman_node::getFrequency(){
  return frequency;
}

char huffman_node::getCharacter(){
  return character;
}

void huffman_node::setFrequency(int i){
  frequency = i;
}

void huffman_node::setCharacter(char c){
  character = c;
}



