//Name: Bailey Payne  ID: brp7vh  Title: StackNode.h  Date: 9/16/16

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>
#include "MyStack.h"
#include "StackItr.h"
using namespace std;

class StackNode{
 public:
  StackNode();    //Constructor

 private:
  int value;
  StackNode *next, *previous;

  friend class MyStack;
  
  friend class StackItr;

};

#endif


