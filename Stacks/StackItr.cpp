//Name: Bailey Payne  ID: brp7vh  Title: StackItr.cpp  Date: 9/16/16

#include <iostream>
#include "MyStack.h"
#include "StackItr.h"
#include "StackNode.h"
using namespace std;

//Constructor
StackItr::StackItr(){
  current = new StackNode;
}

//Constructor with node parameter
StackItr::StackItr(StackNode* theNode){
  current = theNode;
}

//Advances current position to next position
void StackItr::moveForward(){
  StackItr itr;
  StackNode *nn;
  if (itr.isPastEnd() != true){
    itr.current = nn -> next;
  }else{
    cout << "The Pointer is Past the End of the List" << endl;
}
}

//Returns true if iterator is pointing past end position, otherwise returns false
bool StackItr::isPastEnd() const{
  StackItr itr;
  if ((itr.current -> next) == NULL){
    return true;
  }else{
    return false;
  }
}

//Returns value of current node
int StackItr::retrieve() const{
  StackItr itr;
  return itr.current -> value;
}





