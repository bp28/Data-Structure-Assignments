/* Name: Bailey Payne  ID: brp7vh  Section: Tuesdays 9:30am */

#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H

using namespace std;

class huffman_node {
 public:
  huffman_node(int freq, char chr);
  ~huffman_node();
  int getFrequency();
  char getCharacter();
  void setFrequency(int i);
  void setCharacter(char c);

  huffman_node * left;
  huffman_node * right;

 private:
  int frequency;
  char character;

};

#endif
