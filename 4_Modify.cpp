
/*
Problem Description:
We have three towers (let’s call them A, B, and C) and a set of N disks.
The disks are initially stacked on tower A in decreasing order of size (largest at the bottom, smallest at the top).
The goal is to move all the disks from tower A to tower C, following these rules:
Only one disk can be moved at a time.
A disk can only be placed on top of a larger disk or an empty tower.


https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/
*/
#include <iostream>

using namespace std;

void move_disk(int n, char source, char destination, char auxiliary) {
  if (n == 1) {
    cout << "Move disk 1 from " << source << " to " << destination << endl;
  } else {
    // Explain the plan
    cout << "To move disk " << n << ", we need to:" << endl;
    cout << "\t1. Move the top " << n-1 << " disks from " << source << " to " << auxiliary << ", using " << destination << " as the auxiliary tower." << endl;
    move_disk(n-1, source, auxiliary, destination);  // Recursive call

    // Move the nth disk to the destination
    cout << "\t2. Move disk " << n << " from " << source << " to " << destination << endl;
    move_disk(1, source, destination, auxiliary);  // Recursive call to move just the nth disk

    // Move the previously moved disks back to the original destination, using the source tower as auxiliary
    cout << "\t3. Move the top " << n-1 << " disks from " << auxiliary << " to " << source << ", using " << destination << " as the auxiliary tower." << endl;
    move_disk(n-1, auxiliary, source, destination);
  }
}

int main() {
  int number_of_disks;
  cout << "Enter the number of disks: ";
  cin >> number_of_disks;

  move_disk(number_of_disks, 'A', 'C', 'B');
  return 0;
}
