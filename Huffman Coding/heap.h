/** Name: Bailey Payne  ID: brp7vh  Section: Tuesdays 9:30am **/
// Original Code written by Aaron Bloomfield, 2014

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include "huffman_node.h"
#include <vector>
using namespace std;

class binary_heap {
public:
    binary_heap();
    binary_heap(vector< huffman_node* > vec); 
    ~binary_heap();

    void insert(huffman_node* hn);
    huffman_node* findMin();
    huffman_node* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

private:
    vector< huffman_node* > heap;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
