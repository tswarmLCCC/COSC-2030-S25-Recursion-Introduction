/*
https://www.programiz.com/cpp-programming/examples/factorial-recursion

What is the base case here?
What happens when n = 2? 3,4,5?

Use the trace functionality of your IDE to step through this.  Add print statements to show what factorial is being called with 
and what n-1 returns
*/

#include<iostream>
using namespace std;

int factorial(int n);

int main() {

  int n;

  cout << "Enter a positive integer: ";
  cin >> n;

  cout << "Factorial of " << n << " = " << factorial(n);

  return 0;
}

int factorial(int n) {
  if(n > 1)
    return n * factorial(n - 1);
  else
    return 1;
}