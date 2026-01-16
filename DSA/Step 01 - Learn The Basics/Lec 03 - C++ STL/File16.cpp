#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Push elements to front and back
    dq.push_back(10);
    dq.push_front(5);
    dq.push_back(15);
    dq.push_front(1);

    // Display all elements
    cout << "Elements in deque: ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Access front and back
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    // Access using index
    cout << "Element at index 2: " << dq.at(2) << endl;

    // Pop from front and back
    dq.pop_front();
    dq.pop_back();

    // Display after pop
    cout << "After popping front and back: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Insert at 1st index
    dq.insert(dq.begin() + 1, 99);

    // Erase element at index 0
    dq.erase(dq.begin());

    // Display after insert and erase
    cout << "After insert and erase: ";
    for (auto val : dq)
        cout << val << " ";
    cout << endl;

    // Size and empty check
    cout << "Size of deque: " << dq.size() << endl;
    cout << (dq.empty() ? "Deque is empty" : "Deque is not empty") << endl;

    // Clear the deque
    dq.clear();
    cout << "Size after clearing: " << dq.size() << endl;

    return 0;
}