
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const unsigned int NUM_CITIES = 3;         // Number of cities
int cityDistances[NUM_CITIES][NUM_CITIES]; // Distance between cities
string cityNames[NUM_CITIES];              // City names

/* Output every possible travel path.
   Each recursive call moves to a new city.
*/
void TravelPaths(vector<int> currPath, vector<int> needToVisit) {
   int totalDist;     // Total distance given current path
   int tmpCity;       // Next city distance
   unsigned int i;    // Loop index
   
   if (currPath.size() == NUM_CITIES) { // Base case: Visited all cities
      totalDist = 0;                     // return total path distance
      for (i = 0; i < currPath.size(); ++i) {
         cout << cityNames[currPath.at(i)] << "   ";
         
         if (i > 0) {
            totalDist += cityDistances[currPath.at(i - 1)][currPath.at(i)];
         }
      }
      
      cout << "= " << totalDist << endl;
   }
   else {                                // Recursive case: pick next city
      for (i = 0; i < needToVisit.size(); ++i) {
         // Add city to travel path
         tmpCity = needToVisit.at(i);
         needToVisit.erase(needToVisit.begin() + i);
         currPath.push_back(tmpCity);
         
         TravelPaths(currPath, needToVisit);
         
         // Remove city from travel path
         needToVisit.insert(needToVisit.begin() + i, tmpCity);
         currPath.pop_back();
      }
   }
}

int main() {
   vector<int> needToVisit(0); // Cities left to visit
   vector<int> currPath(0);    // Current path traveled
   
   // Initialize distances array
   cityDistances[0][0] = 0;
   cityDistances[0][1] = 960;  // Boston-Chicago
   cityDistances[0][2] = 2960; // Boston-Los Angeles
   cityDistances[1][0] = 960;  // Chicago-Boston
   cityDistances[1][1] = 0;
   cityDistances[1][2] = 2011; // Chicago-Los Angeles
   cityDistances[2][0] = 2960; // Los Angeles-Boston
   cityDistances[2][1] = 2011; // Los Angeles-Chicago
   cityDistances[2][2] = 0;
   
   cityNames[0] = "Boston";
   cityNames[1] = "Chicago";
   cityNames[2] = "Los Angeles";
   
   needToVisit.push_back(0); // Boston
   needToVisit.push_back(1); // Chicago
   needToVisit.push_back(2); // Los Angeles

   // Explore different paths   
   TravelPaths(currPath, needToVisit);
   
   return 0;
}