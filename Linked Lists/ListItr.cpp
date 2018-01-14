//Name: Bailey Payne  ID: brp7vh  Title: ListItr.cpp

#include <iostream>
#include "ListItr.h"
#include "List.h"
#include "ListNode.h"
using namespace std;

//Constructor
ListItr::ListItr(){
  current = new ListNode;
}

//One Parameter Constructor
ListItr::ListItr(ListNode* theNode){
  current = theNode;
}

//Returns true if iterator is pointing past end position
bool ListItr::isPastEnd() const{
  ListItr itr;
  if ((itr.current -> next) == NULL){
    return true;
  }else{
    return false;
}
}

//Returns true if iterator is pointing past first position
  bool ListItr::isPastBeginning() const{
  ListItr itr;
  if ((itr.current -> previous) == NULL){
    return true;
  }else{
    return false;
  }
}

//Advances current position to the next position
void ListItr::moveForward(){
  ListItr itr;
  ListNode *nn;
  if (itr.isPastEnd() != true){
    itr.current = nn -> next;
  }else{
    cout << "The Pointer is Past the End of the List" << endl;
}
}

//Moves current position to the previous position
void ListItr::moveBackward(){
  ListItr itr;
  ListNode *np;
  if (itr.isPastBeginning() != true){
    itr.current = np -> previous;
  }else{
    cout << "The Pointer is Past the Beginning of the List" << endl;
}
}

//Returns the value of the item in the current position
int ListItr::retrieve() const{
  ListItr itr;
  return itr.current -> value;
}
 

