#include <iostream>

using namespace std;

void printPascal(int n) {
  // Create an array to store rows
  int *prevRow = new int[n];
  int *currRow = new int[n];

  // Initialize the first row
  prevRow[0] = 1;
  for (int i = 1; i < n; ++i) {
    prevRow[i] = 0;
  }

  // Print the first row
  cout << "1" << endl;

  // Iterate for remaining rows
  for (int i = 1; i < n; ++i) {
    currRow[0] = 1;
    currRow[i] = 1;

    // Calculate remaining elements of the current row using the previous row
    for (int j = 1; j < i; ++j) {
      currRow[j] = prevRow[j - 1] + prevRow[j];
    }

    // Print the current row
    for (int j = 0; j <= i; ++j) {
      cout << currRow[j] << " ";
    }
    cout << endl;

    // Swap the row pointers for efficient memory usage
    swap(prevRow, currRow);
  }

  // Free the allocated memory
  delete[] prevRow;
  delete[] currRow;
}

int main() {
  int numRows;

  cout << "Enter the number of rows: ";
  cin >> numRows;

  printPascal(numRows);

  return 0;
}
