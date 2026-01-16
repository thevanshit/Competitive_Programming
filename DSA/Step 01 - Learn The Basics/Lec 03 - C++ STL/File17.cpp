#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Max Heap (default)
    priority_queue<int> maxPQ;

    // Insert elements
    for (int i = 1; i <= 5; i++) {
        maxPQ.push(i * 10);  // 10, 20, 30, 40, 50
    }

    // Insert using emplace
    maxPQ.emplace(25);

    cout << "Max Heap Priority Queue elements (top to bottom): ";
    while (!maxPQ.empty()) {
        cout << maxPQ.top() << " ";
        maxPQ.pop();
    }
    cout << endl;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minPQ;
    minPQ.push(50);
    minPQ.push(10);
    minPQ.push(30);
    minPQ.emplace(5);

    cout << "Min Heap Priority Queue elements (top to bottom): ";
    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }
    cout << endl;

    // Re-initialize and check size/empty
    priority_queue<int> pq;
    pq.push(100);
    pq.push(200);
    cout << "Size of pq: " << pq.size() << endl;
    cout << "Top of pq: " << pq.top() << endl;
    pq.pop();
    cout << "After pop, top: " << pq.top() << endl;
    pq.pop();
    cout << "Is pq empty? " << (pq.empty() ? "Yes" : "No") << endl;

    return 0;
}