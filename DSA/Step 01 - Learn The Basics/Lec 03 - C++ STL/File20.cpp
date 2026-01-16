#include <iostream>
using namespace std;

int main() {
  int n = 29;  // Binary: 11101

  cout << "Original number: " << n << endl;

  // Count number of 1s in binary using __builtin_popcount
  cout << "Number of set bits (1s) in binary: " << __builtin_popcount(n) << endl;

  // Check for power of two using popcount
  if (__builtin_popcount(n) == 1)
    cout << n << " is a power of 2" << endl;
  else
    cout << n << " is NOT a power of 2" << endl;

  // Looping through numbers 0 to 10 and counting set bits
  cout << "\nSet bits from 0 to 10:\n";
  for (int i = 0; i <= 10; i++) {
    cout << "Number: " << i << ", Binary set bits: " << __builtin_popcount(i) << endl;
  }

  // Using __builtin_popcountll for long long numbers
  unsigned long long big = 9223372036854775807LL;  // max 64-bit number
  cout << "\nNumber of set bits in big 64-bit number: " << __builtin_popcountll(big) << endl;

  return 0;
}