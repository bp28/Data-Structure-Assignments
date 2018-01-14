//Name: Bailey Payne  ID: brp7vh  Title: Stack.h  Date: 9/16/16

#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include "StackNode.h"
#include "StackItr.h"
using namespace std;

class StackItr;

class MyStack{
 public:
  MyStack();                               //Constructor
  ~MyStack();                              //Destructor
  void makeEmpty();                      //Removes all items except blank head
  int top();                             //Returns the value that at the first node
  void push(int x);                      //Inserts x before current position
  void pop();                            //Delete first node in list
  int size() const;                      //Returns number of elements in list
  
 private:
  StackNode *head, *tail;
  int count;
  
  friend class StackItr;

};

#endif
  

