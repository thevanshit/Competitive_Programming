#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  unordered_multiset < int > s;
  for (int i = 1; i <= 10; i++) {
    s.insert(i);
  }
  s.insert(10);

  cout << "Elements present in the unordered multiset: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << * it << " ";
  }
  cout << endl;
  int n = 2;
  if (s.find(2) != s.end())
    cout << n << " is present in unordered multiset" << endl;

  s.erase(s.begin());
  cout << "Elements after deleting the first element: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << * it << " ";
  }
  cout << endl;

  cout << "The size of the unordered multiset is: " << s.size() << endl;

  if (s.empty() == false)
    cout << "The unordered multiset is not empty " << endl;
  else
    cout << "The unordered multiset is empty" << endl;
  s.clear();
  cout << "Size of the unordered multiset after clearing all the elements: " << s.size();
}