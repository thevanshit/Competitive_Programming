#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Create a queue of integers
    queue<int> q;

    // Insert elements into queue
    for (int i = 1; i <= 5; ++i) {
        q.push(i);  // same as q.emplace(i);
    }

    // Display front and back
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    // Display all elements using pop()
    cout << "\nQueue elements (FIFO): ";
    queue<int> temp = q;  // copy queue for display
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Size of queue
    cout << "\nSize of queue: " << q.size() << endl;

    // Check if queue is empty
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    // Pop one element
    q.pop();
    cout << "\nAfter popping one element, front: " << q.front() << endl;

    // Swap with another queue
    queue<int> q2;
    q2.push(100);
    q2.push(200);
    q.swap(q2);

    // Show elements after swap
    cout << "\nAfter swapping with q2:\n";
    cout << "q front: " << q.front() << ", q back: " << q.back() << endl;
    cout << "q2 front: " << q2.front() << ", q2 back: " << q2.back() << endl;

    // Clear the queue manually by popping
    while (!q.empty()) {
        q.pop();
    }
    cout << "\nSize of q after clearing: " << q.size() << endl;

    return 0;
}