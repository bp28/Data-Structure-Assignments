//Name: Bailey Payne  ID: brp7vh  Title: MyStack.cpp  Date: 9/16/16

#include <iostream>
#include "StackNode.h"
#include "MyStack.h"
#include "StackItr.h"
using namespace std;

//Constructor
MyStack::MyStack(){
  head = new StackNode;
  tail = new StackNode;
  count = 0;
  head -> next = tail;
  tail -> previous = head;
  head -> previous = NULL;
  tail -> next = NULL;
}

//Destructor
MyStack::~MyStack(){
  makeEmpty();
  delete head;
  delete tail;
}

//Removes all items except for blank head and tail
void MyStack::makeEmpty(){
  StackNode *c = head -> next;
  while (c != tail){
    StackNode *nn = c -> next;
    delete nn;
    count--;
  }
  head -> next = tail;
  tail -> previous = head;
}

//Returns an int that is the value of the first node
int MyStack::top(){
  StackItr first;
  first.current = head -> next;
  return first.current -> value;
}

//Inserts x after head node
void MyStack::push(int x){
  StackItr itr;
  StackNode *nn = itr.current;
  head -> next = nn;
  nn -> value = x;
  count++;
}

//Deletes the first node in the list
void MyStack::pop(){
  StackItr itr;
  StackNode *nn = itr.current;
  head -> next = nn;
  delete nn;
  count--;
  }

//Returns number of elements in list
int MyStack::size() const{
  return count;
}


