# COSC-2030-S25-Recursion-Introduction

Write a recursive function called DigitCount() that takes a non-negative integer as a parameter
and returns the number of digits in the integer.
Hint: The digit count increases by 1 whenever the input number is divided by 10.

Ex: If the input is:

345
the function DigitCount() returns and the program outputs:
3

```C++ Starter Code


#include 
using namespace std;

/* TODO: Write recursive DigitCount() function here. */


int main() {
   int num;
   int digits;

   cin >> num;
   digits = DigitCount(num);
   cout << digits << endl;
   return 0;
}
```
 
