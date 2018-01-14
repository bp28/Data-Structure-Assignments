//Name: Bailey Payne  ID: brp7vh  Title: inlab4.cpp  Date: 9/21/16

#include <iostream>
using namespace std;

void memRep(){

/** Part One **/

bool Bl = true;
char Chr = '1';
int Int = 14;
double Dbl = 1.4;
int* intPtr = NULL;

cout << "Boolean Value: " << Bl << endl;
cout << "Character Value: " << Chr << endl;
cout << "Integer Value: " << Int << endl;
cout << "Double Value: " << Dbl << endl;
cout << "Integer Pointer: " << intPtr << endl;

}

void arrayMem(){

/** Part Two **/

int IntArray[10] = {1,2,3,4,5,6,7,8,9,10};
char CharArray[10] = {1,2,3,4,5,6,7,8,9,10};

int IntArray2D[6][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25},{26,27,28,29,30}};
char CharArray2D[6][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25},{26,27,28,29,30}};

int i = 0;
int j = 0;
for (i=0; i<6; i++){
for (j=0; j<5; j++){
  cout << "[" << i << "]" << "[" << j << "] // " <<  &IntArray2D[i][j] << endl;
}
}
}

int main(){
memRep();
arrayMem();
return 0;
}

  
