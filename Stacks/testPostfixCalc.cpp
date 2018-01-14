//Name: Bailey Payne  ID: brp7vh  Title: testPostfixCalc.cpp  Date: 9/13/16

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "postfixCalculator.h"
using namespace std;

int main(){
  
  postfixCalculator PFC;
  while (cin.good()){
    string s;
    cin >> s;

    char cs[s.length()+1];
    strcpy(cs, s.c_str());

    char * p = cs;

    if (isdigit(*p)){
      int x = atoi(p);
      PFC.push(x);
    }

    if (p[0] == '-' && isdigit(p[1])){
      int x = atoi(p);
      PFC.push(x);
    }

    else{
    if (p[0] == '+'){
      PFC.addOp();
      }
    if (p[0] == '-' && p[1] == ' '){
      PFC.subOp();
      }
    if (p[0] == '/'){
      PFC.divOp();
      }
    if (p[0] == '*'){
      PFC.timesOp();
      }
    if (p[0] == '~'){
      PFC.negOp();
      }
  }
  cout << PFC.evaluate() << endl;
  }
  return 0;
}

  




