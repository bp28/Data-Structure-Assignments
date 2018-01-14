#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests);

/** @brief Computes the smallest path between two cities
 * @param argc The number of parameters
 * @param argv width, height, number of cities, random seed, and number of cities to visit
 */
int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    vector<string> temp;
    float lowest = 1000;

    sort(dests.begin()+1, dests.end());
    if (dests.size() == 2){
      lowest = computeDistance(me, dests[0], dests);
      temp = dests;
      cout << lowest << endl;
    }

    while(next_permutation(dests.begin()+1, dests.end())){
      //if float < computeDist
      //      update float
      //      for every element in dests
      //          add element to temp vector
      
      if (computeDistance(me, dests[0], dests) < lowest){
	  lowest = computeDistance(me, dests[0], dests);
	  temp = dests;
	  cout << lowest << endl;
	}
    }

      printRoute(temp[0], temp);
      cout << "and will have length of " << lowest << endl;

    //printRoute(temp vector [0], temp vector)
    //print float

 
    return 0;
}

/** @brief This method will compute the full distance of the cycle that starts
 * at the 'start' parameter, goes to each of the cities in the dests
 * vector IN ORDER, and ends back at the 'start' parameter.
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
  float dist = 0.0;
  for (int i = 0; i < dests.size()-1; i++){
    dist += me.getDistance(dests[i], dests[i+1]);
    //cout << dist << " from " << dests[i] << " to " << dests[i+1] << endl;
  }
  float final = me.getDistance(dests[dests.size()-1], start);
  float total = dist + final;
  //cout << "and will have a length of  " << total << endl;
  return total;
}

/** @brief This method will print the entire route, starting and ending at the
 * 'start' parameter.  The output should be of the form:
 * Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
 */
void printRoute (string start, vector<string> dests) {
  string route = "";
  for (int i = 1; i < dests.size(); i++){
    route += " -> " + dests[i];
  }
  cout << "Your journey will take you along the path " << start << route << " -> " << start << endl;
}
