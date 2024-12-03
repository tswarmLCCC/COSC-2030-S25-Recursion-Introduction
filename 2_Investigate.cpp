
#include <iostream>
using namespace std;

int sum_of_digits(int n) {
  if (n == 0) {
    return 0;
  }
  cout << "n: " << n << " - modulus: " <<  n % 10 << " - quotient: " << n / 10 << endl;
  return n % 10 + sum_of_digits(n / 10);
}

int main() {
  int number;

  std::cout << "Enter a non-negative integer: ";
  std::cin >> number;

  if (number < 0) {
    std::cout << "Error: Please enter a non-negative integer." << std::endl;
    return 1; // Indicate error
  }

  int sum = sum_of_digits(number);
  std::cout << "The sum of digits in " << number << " is: " << sum << std::endl;

  return 0;
}
