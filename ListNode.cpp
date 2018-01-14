//Name: Bailey Payne  ID: brp7vh  Title: ListNode.cpp

#include <iostream>
#include "ListItr.h"
#include "List.h"
#include "ListNode.h"
using namespace std;

//Constructor
ListNode::ListNode(){
  int value = 0;
  next = new ListNode;
  previous = new ListNode;
}

