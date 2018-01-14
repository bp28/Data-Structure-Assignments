//Name: Bailey Payne  ID: brp7vh  Title: postfixCalculator.cpp  Date: 9/13/16

#include <iostream>
#include "MyStack.h"
#include "postfixCalculator.h"
using namespace std;

//Constructor
postfixCalculator::postfixCalculator(){
  MyStack stk;
}

//Destructor
postfixCalculator::~postfixCalculator(){
  stk.~MyStack();
}

//Inserts x into top of the stack
void postfixCalculator::push(int x){
  stk.push(x);
}

//Adds x and y
void postfixCalculator::addOp(){
  if (stk.size() >= 2){
    int x = stk.top();
    stk.pop();
    int y = stk.top();
    int result = x + y;
    stk.pop();
    stk.push(result);
}
  else if (stk.size() == 1){
    int result = stk.top();
    stk.pop();
    stk.push(result);
}
  else{
    cout << "The stack is empty. Push some values into the stack." << endl;
  }
}

//Subtracts x from y
void postfixCalculator::subOp(){
  if (stk.size() >= 2){
    int x = stk.top();
    stk.pop();
    int y = stk.top();
    int result = y - x;
    stk.pop();
    stk.push(result);
}
  else if (stk.size() == 1){
    int result = stk.top();
    stk.pop();
    stk.push(result);
}
  else{
    cout << "The stack is empty. Push some values into the stack." << endl;
  }
}

//Divides y by x
void postfixCalculator::divOp(){
  if (stk.size() >= 2){
    int x = stk.top();
    stk.pop();
    int y = stk.top();
    int result = y / x;
    stk.pop();
    stk.push(result);
}
  else if (stk.size() == 1){
    int result = stk.top();
    stk.pop();
    stk.push(result);
}
  else{
    cout << "The stack is empty. Push some values into the stack." << endl;
  }
}

//Multiplies x and y
void postfixCalculator::timesOp(){
  if (stk.size() >= 2){
    int x = stk.top();
    stk.pop();
    int y = stk.top();
    int result = x * y;
    stk.pop();
    stk.push(result);
}
  else if (stk.size() == 1){
    int result = stk.top();
    stk.pop();
    stk.push(result);
}
  else{
    cout << "The stack is empty. Push some values into the stack." << endl;
  }
}

//Negates sign of operand
void postfixCalculator::negOp(){
   if (stk.size() >= 1){
    int x = stk.top();
    stk.pop();
    stk.push(-x);
}
  else{
    cout << "The stack is empty. Push some values into the stack." << endl;
  }
}

//Returns top element in stack
int postfixCalculator::evaluate(){
  return stk.top();
}





  

  
	
