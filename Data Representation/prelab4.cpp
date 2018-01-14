//Name: Bailey Payne  //ID: brp7vh  //Title: prelab4.cpp  //Date: 9/20/16

#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>
using namespace std;

void sizeOfTest(){
  cout << "Integer // Number of Bytes: " << sizeof(int) << endl;
  cout << "Unsigned Integer // Number of Bytes: " << sizeof(unsigned int) << endl;
  cout << "Float // Number of Bytes: " << sizeof(float) << endl;
  cout << "Double // Number of Bytes: " << sizeof(double) << endl;
  cout << "Character // Number of Bytes: " << sizeof(char) << endl;
  cout << "Boolean // Number of Bytes: " << sizeof(bool) << endl;
  cout << "Integer Pointer // Number of Bytes: " << sizeof(int*) << endl;
  cout << "Character Pointer// Number of Bytes: " << sizeof(char*) << endl;
  cout << "Double Pointer // Number of Bytes: " << sizeof(double*) << endl;
}

void outputBinary(unsigned int uInt){
  string s = "";
  int size = 8 * sizeof(unsigned int) + 1;
  for (int i = 0; i < size; i++){
    if (uInt % 2 == 1){
      s = '1' + s;
	}
    if (uInt % 2 == 0){
      s = '0' + s;
    }
    uInt = uInt / 2;
  }
  cout << s << endl;
}

void overflow(){
  unsigned int uInt = std::numeric_limits<unsigned int>::max();
  cout << "Max Value: " << uInt << endl;
  cout << "Max Value + 1: " << (uInt + 1) << endl;
  cout << "The previous jump occurs because an unsigned int containing n bits can have a value between 0 and (2^n)-1. If (2^n)-1 is the max, adding 1 to it will result in (2^n) which requires one too many bits, so an overflow occurs." << endl;
  }

int main(){
  return 0;
}


    
