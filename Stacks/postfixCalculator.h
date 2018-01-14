//Name: Bailey Payne  ID: brp7vh  Title: postfixCalculator.h  Date: 9/13/16

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "MyStack.h"
using namespace std;

class postfixCalculator {
  
 public:

  postfixCalculator();                     //Constructor
  ~postfixCalculator();                    //Destructor
  void push(int x);             //Inserts x at top of stack
  void addOp();                //Adds two operands together
  void subOp();                //Subtracts the second operand from the first
  void divOp();                //Divides the first operand by the second
  void timesOp();              //Multiplies two operands together
  void negOp();                //Negates top value in stack
  int evaluate();              //Returns top value in stack

  
 private:

  MyStack stk;
  
};

#endif
