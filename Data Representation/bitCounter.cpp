//Name: Bailey Payne  ID: brp7vh  Title: bitCounter.cpp  Date: 9/22/16

#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

int bitCounter(int n){
  int count;
  if (n == 0){
    return 0;
  }
  if (n == 1){
    return 1;
  }
  if ((n % 2 == 0) && (n != 0)){
    return (bitCounter(n/2));
  }
  else{
    return 1 + (bitCounter(floor(n/2)));
  }
  return count;
}
  
int main(int argc, char **argv){
  int n = atoi(argv[1]);
  if (argv[1] == NULL){
  cout << "Invalid Input";
  }
  else{
  cout << "The number of 1 Bits in integer " << n << ": " << bitCounter(n) << endl;
  }
  return 0;
}

