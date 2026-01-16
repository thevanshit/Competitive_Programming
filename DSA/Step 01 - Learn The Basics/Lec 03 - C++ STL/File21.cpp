#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Custom comparator function
bool customDescending(int a, int b) {
    return a > b;
}

int main() {
  vector<int> v;

  // Inserting values
  for (int i = 10; i >= 1; i--) {
    v.push_back(i);
  }
  v.push_back(5); // duplicate value

  cout << "Original vector elements: ";
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // Sort in ascending order
  sort(v.begin(), v.end());
  cout << "Sorted in ascending order: ";
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // Sort in descending order using greater<>
  sort(v.begin(), v.end(), greater<int>());
  cout << "Sorted in descending order (greater<>): ";
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // Sort using custom comparator
  sort(v.begin(), v.end(), customDescending);
  cout << "Sorted using custom comparator (descending): ";
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // Partial sort: only first 5 elements sorted
  sort(v.begin(), v.begin() + 5);
  cout << "Partially sorted (first 5 elements): ";
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // Check if sorted
  if (is_sorted(v.begin(), v.end()))
    cout << "Vector is sorted" << endl;
  else
    cout << "Vector is NOT sorted" << endl;

  // Sort whole vector again in ascending
  sort(v.begin(), v.end());

  // Check sorted again
  if (is_sorted(v.begin(), v.end()))
    cout << "Vector is sorted now" << endl;

  return 0;
}