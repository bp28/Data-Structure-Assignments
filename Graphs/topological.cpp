/** Name: Bailey Payne  ID: brp7vh  Section: Tuesdays 9:30am **/
// Beginning of Main Written by Another Source (Part of Given Code)

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

/** @brief Creates an adjacency list and performs a topological sort on it
 * @details Step 1: Reads the file and returns strings
 * Step 2: Creates a node struct to hold the desired information
 * Step 3: Creates a vector to hold all of these node pointers
 * Step 4: Performs 4 Cases to determine when to insert nodes
 *         Case 1: Both Nodes Exist in the List
 *         Case 2 and 3: One Nodes Exists and the Other Does Not
 *         Case 4: Neither Node Exists in the List
 * Step 5: Creates a queue and inserts all nodes into the queue from least Indegree to greatest
 * Step 6: Performs a topological sort
 * @param argc The number of input files
 * @param argv The input file containing classes and prerequisites
 */

int main (int argc, char **argv) {

  if ( argc != 2 ) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }
    
  ifstream file(argv[1], ifstream::binary);
    
  if ( !file.is_open() ) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }

  struct node{
    struct node *next;
    string name;
    int nDeg;
    int topoNum;
  };

  vector< node* > adjList;

  string s1, s2;
    
  while ( file >> s1 ) {
    file >> s2;
    bool s1Exists = false;
    bool s2Exists = false;

    if (s1 == "0"){
      continue;
    }
    
    for (int i = 0; i < adjList.size(); i++){
      if (adjList[i] -> name == s1){
	s1Exists = true;
      }
      if (adjList[i] -> name == s2){
	s2Exists = true;
      }
    }

    if (s1Exists == true && s2Exists == true){
      node* itr1 = new node();
      for (int i = 0; i < adjList.size(); i++){
	if (adjList[i] -> name == s1){
	  itr1 = adjList[i];
	}
	if (adjList[i] -> name == s2){
	  adjList[i] -> nDeg += 1;
	  while (itr1 -> next != NULL){
	    itr1 = itr1 -> next;
	  }
	  itr1 -> next = adjList[i];
	}
      }
    }
 
    
    else if (s1Exists == true && s2Exists == false){
      node* new2 = new node();
      node* itr2 = new node();
      new2 -> name = s2;
      adjList.push_back(new2);
      for (int i = 0; i < adjList.size(); i++){
	if (adjList[i] -> name == s1){
  	  itr2 = adjList[i];
	  while (itr2 -> next != NULL){
	    itr2 = itr2 -> next;
	  }
	  itr2 -> next = new2;
	  new2 -> nDeg += 1;
	}
      }
    }

    else if (s1Exists == false && s2Exists == true){
      node* new1 = new node();
      new1 -> name = s1;
      adjList.push_back(new1);
      for (int i = 0; i < adjList.size(); i++){
	if (adjList[i] -> name == s2){
	  new1 -> next = adjList[i];
	  adjList[i] -> nDeg += 1;
	}
      }
    }

    else{
      node* new1 = new node();
      new1 -> name = s1;
      node* new2 = new node();
      new2 -> name = s2;
      adjList.push_back(new1);
      adjList.push_back(new2);
      new2 -> nDeg += 1;
      new1 -> next = new2;
    }
  }
      
    cout << adjList.size() << endl;
    
    for (int i = 0; i < adjList.size(); i++){
      cout << "INDEX: " << i << " // " << adjList[i] -> name << " : " << adjList[i] -> nDeg << endl;
      node* iter2 = new node();
      iter2 = adjList[i];
      while (iter2 -> next != NULL){
	cout << iter2 -> name << " ";
	iter2 = iter2 -> next;
       }
       cout << endl;
    }
     
  cout << endl;
  
  int numV = adjList.size();
  queue< node* > q;
  int counter = 0;

  for (int i = 0; i < q.size(); i ++){
    q.pop();
  }
  for (int j = 0; j < adjList.size(); j++){
    if (adjList[j] -> nDeg == 0){
      q.push(adjList[j]);
    }
  }
  while (!q.empty()){
    node* ZERO = q.front(); q.pop();
    ZERO -> topoNum = ++counter;
    for (int i = 0; i < adjList.size(); i++){
      if (adjList[i] -> name == ZERO -> name){
	node* iter = adjList[i];
	while (iter != NULL){
	  if (--(iter -> nDeg) == 0){
	    q.push(iter);
	  }
	  iter = iter -> next;
	}
      }
    }
  }
  
  if (counter != numV){
    cout << "There was a cycle found!" << endl;
  }
  else{
    for (int i = 0; i < q.size(); i++){
      cout << q.front() << " ";
      q.pop();
    }
    cout << endl;
  }
  
  file.close();
}

