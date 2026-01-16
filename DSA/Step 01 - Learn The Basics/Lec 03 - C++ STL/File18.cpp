#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;

    // Inserting elements
    l.push_back(10);
    l.push_front(5);
    l.push_back(20);
    l.push_back(15);
    l.push_front(5);

    cout << "Elements in list: ";
    for (auto it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // Size, front, back
    cout << "Size: " << l.size() << endl;
    cout << "Front: " << l.front() << ", Back: " << l.back() << endl;

    // Deleting front and back
    l.pop_front();
    l.pop_back();

    cout << "After popping front and back: ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Inserting at a specific position
    auto it = l.begin();
    advance(it, 1); // move iterator to 2nd position
    l.insert(it, 99);

    cout << "After inserting 99 at 2nd position: ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Erasing an element at position
    it = l.begin();
    advance(it, 1);
    l.erase(it);

    cout << "After erasing 2nd element: ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Removing all occurrences of 5
    l.remove(5);
    cout << "After removing all 5s: ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Add duplicates to demonstrate unique and sort
    l.push_back(10);
    l.push_back(10);
    l.push_back(3);
    l.push_back(3);

    // Sorting
    l.sort();
    cout << "After sorting: ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Unique (removes consecutive duplicates only)
    l.unique();
    cout << "After unique(): ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Reversing
    l.reverse();
    cout << "After reversing: ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // Clear and empty
    l.clear();
    cout << "Is list empty after clear()? " << (l.empty() ? "Yes" : "No") << endl;

    return 0;
}