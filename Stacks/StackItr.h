//Name: Bailey Payne  ID: brp7vh  Title: StackItr.h  Date: 9/16/16

#ifndef STACKITR_H
#define STACKITR_H

#include <iostream>
#include "StackNode.h"
#include "MyStack.h"
using namespace std;

class StackNode;

class StackItr{
 public:
  StackItr();                    //Constructor
  StackItr(StackNode* theNode);  //One Parameter Constructor
  void moveForward();            //Moves current node to next node in list
  bool isPastEnd() const;        //Checks if itr is pointing past end of list
  int retrieve() const;          //Returns value of current node

 private:
  StackNode* current;

  friend class MyStack;

};

#endif
