//Name: Bailey Payne  ID: brp7vh  Title: List.cpp

#include <iostream>
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"
using namespace std;

//Constructor
List::List(){
  head = new ListNode;
  tail = new ListNode;
  count = 0;
  head -> next = tail;
  tail -> previous = head;
  head -> previous = NULL;
  tail -> next = NULL;
}

//Destructor
List::~List(){
  makeEmpty();
  delete head;
  delete tail;
}

//Copy Assignment Operator
List& List::operator=(const List& source){
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

//Copy Constructor
List::List(const List& source){
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

//Returns true if list is empty, false otherwise
bool List::isEmpty() const{
  if (count == 0){
    return true;
  }
  else{
    return false;
  }
}


//Removes all items from list
void List::makeEmpty(){
  ListNode *current;
  current = head -> next;
  while (current != tail){
    ListNode *nxt = current -> next;
    delete current;
    current = nxt;
    count--;
  }
  head -> next = tail;
  tail -> previous = head;
}

//Returns an iterator that points to the first position node
ListItr List:: first(){
  ListItr first;
  first.current = head -> next;
  return first;
  }

//Returns an iterator that points to the last position node
ListItr List::last(){
  ListItr last;
  last.current = tail -> previous;
  return last;
}

//Inserts x after the current iterator position
void List::insertAfter(int x, ListItr position){
  ListNode *ptr = new ListNode;
  ptr -> previous = position.current;
  position.current -> next -> previous = ptr;
  ptr -> next = position.current -> next;
  position.current -> next = ptr;
  ptr -> value = x;
  count++;
}

//Inserts x before the current iterator position
void List::insertBefore(int x, ListItr position){
  ListNode *ptr = new ListNode;
  ptr -> next = position.current;
  position.current -> previous -> next = ptr;
  ptr -> previous = position.current -> previous;
  position.current -> previous = ptr;
  ptr -> value = x;
  count++;
}

//Inserts x at the tail node
void List::insertAtTail(int x){
  ListNode *bef = tail -> previous;
  ListNode *nn = new ListNode();
  nn -> value = x;
  bef -> next = nn;
  nn -> next = tail;
  tail -> previous = nn;
  nn -> previous = bef;
  count++;
}

//Removes first occurence of x
void List::remove(int x){
    ListNode *c;
    c = head -> next;
    while (c != tail){
      ListNode *nn = c -> next;
      ListNode *np = c -> previous;
      if (c -> value == x){
        np -> next = nn;
	nn -> previous = np;
        delete c;
	c = tail;
	count--;
        }
      else{
        c = nn;
    }
  }
}

//Returns an iterator that points 
ListItr List::find(int x){
    ListNode *c;
    ListItr temp;
    c = head -> next;
    while (c != tail){
      ListNode *nn = c -> next;
      if (c -> value ==  x){
	temp.current = c;
        return temp;
       }
      else{
        c = nn;
     }
   }
    ListItr itr;
    itr.current = tail;
    return itr;
}

//Returns the number of elements in the list
int List::size() const{
  return count;
}

//Prints a list either forwards or backwards
void printList(List& theList, bool forward){
  if (forward == true){
    ListItr itr;
    theList.first() = itr;
    while (itr.isPastEnd() != true){
 
      itr.moveForward();
    }
  }
  else{
      ListItr itr;
      theList.last() = itr;
      while (itr.isPastBeginning() != true){
  
	itr.moveBackward();
    }
  }  
}


