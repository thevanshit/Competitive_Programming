#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool customCompare(int a, int b) {
    return (a % 10) < (b % 10);  // compare based on last digit
}

int main() {
  vector<int> s;
  for (int i = 10; i >= 1; i--) {
    s.push_back(i);
  }
  s.push_back(21); // extra value

  cout << "Elements present in the vector: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // Find min and max element normally
  auto min_it = min_element(s.begin(), s.end());
  auto max_it = max_element(s.begin(), s.end());

  cout << "Minimum element is: " << *min_it << endl;
  cout << "Maximum element is: " << *max_it << endl;

  // Find min and max using custom comparator
  auto min_custom = min_element(s.begin(), s.end(), customCompare);
  auto max_custom = max_element(s.begin(), s.end(), customCompare);

  cout << "Minimum element (by last digit): " << *min_custom << endl;
  cout << "Maximum element (by last digit): " << *max_custom << endl;

  // Size and empty checks
  cout << "The size of the vector is: " << s.size() << endl;

  if (s.empty() == false)
    cout << "The vector is not empty " << endl;
  else
    cout << "The vector is empty" << endl;

  s.clear();
  cout << "Size of the vector after clearing all the elements: " << s.size() << endl;
}