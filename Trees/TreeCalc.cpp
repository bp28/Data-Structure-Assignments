// Name: Bailey Payne  ID: brp7vh  Title: TreeCalc.cpp
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
  if (ptr != NULL){
    cleanTree(ptr -> left);
    cleanTree(ptr -> right);
    delete ptr;
}
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
  TreeNode* tn = new TreeNode();
  if ((val == "+") || (val == "-") || (val == "/") || (val == "*")){
    tn -> value = val;
    tn -> right = stk.top();
    stk.pop();
    tn -> left = stk.top();
    stk.pop();
    stk.push(tn);
  }
  else{
    tn -> value = val;
    stk.push(tn);
}
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
  if ((ptr -> left == NULL) && (ptr -> right == NULL)){
      cout << ptr -> value << " ";
    }
  else if (ptr != NULL){
    cout << ptr -> value << " ";
    printPrefix(ptr -> left);
    printPrefix(ptr -> right);
}
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
  if ((ptr -> left == NULL) && (ptr -> right == NULL)){
    cout << ptr -> value << " ";
    }
  else if (ptr != NULL){
    if ((ptr -> value == "+") || (ptr -> value == "-") || (ptr -> value == "/") || (ptr -> value == "*")){
	cout << "(" << " ";
      }
    printInfix(ptr -> left);
    cout << ptr -> value << " ";
    printInfix(ptr -> right);
    if ((ptr -> value == "+") || (ptr -> value == "-") || (ptr -> value == "/") || (ptr -> value == "*")){
       cout << ")" << " ";
      }
      }
      }

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
  if ((ptr -> left == NULL) && (ptr -> right == NULL)){
    cout << ptr -> value << " ";
    }
  else if (ptr != NULL){
    printPostfix(ptr -> left);
    printPostfix(ptr -> right);
    cout << ptr -> value << " ";
}
      }

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (stk.size()!=0 && stk.top()!= NULL) {
        cout << "Expression tree in postfix expression: ";
        printPostfix(stk.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        printInfix(stk.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        printPrefix(stk.top());
        cout << endl;
    } else{
        cout<< "Size is 0." << endl;
}
  }

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
  if ((ptr -> left == NULL) && (ptr -> right == NULL)){
    return atoi(ptr -> value.c_str());
}
  else{
    if (ptr -> value == "+"){
      return calculate(ptr -> left) + calculate(ptr -> right);
    }
    else if (ptr -> value == "-"){
      return calculate(ptr -> left) - calculate(ptr -> right);
    }
    else if (ptr -> value == "/"){
      return calculate(ptr -> left) / calculate(ptr -> right);
    }
    else{
      return calculate(ptr -> left) * calculate(ptr -> right);
    }
  }
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
  return calculate(stk.top());
}
