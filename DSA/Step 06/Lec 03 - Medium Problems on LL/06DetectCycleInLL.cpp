#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Node definition for a singly linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

// ⭐️ Function to detect a cycle using a hash set ⭐️
bool detectCycle(Node* head) {
    // This set will store the memory addresses of nodes we have visited.
    unordered_set<Node*> nodeSet;
    Node* temp = head;

    while (temp != nullptr) {
        // Check if the current node's address is already in our set.
        if (nodeSet.find(temp) != nodeSet.end()) {
            // If it is, we've found a cycle.
            return true;
        }

        // If we haven't seen this node before, add its address to the set.
        nodeSet.insert(temp);

        // Move to the next node.
        temp = temp->next;
    }

    // If the loop finishes, we reached the end (nullptr), so no cycle exists.
    return false;
}

// Helper to print the result
void printResult(Node* head) {
    if (detectCycle(head)) {
        cout << "A cycle was detected in the linked list." << endl;
    } else {
        cout << "No cycle was detected in the linked list." << endl;
    }
}


int main() {
    // --- Test Case 1: List with a cycle ---
    cout << "--- Test Case 1 ---" << endl;
    Node* head1 = new Node(1);
    Node* second1 = new Node(2);
    Node* third1 = new Node(3);
    Node* fourth1 = new Node(4);
    Node* fifth1 = new Node(5);

    head1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;
    // Creating a cycle: The last node (5) points back to the third node (3)
    fifth1->next = third1; 
    
    printResult(head1);


    // --- Test Case 2: List without a cycle ---
    cout << "\n--- Test Case 2 ---" << endl;
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    printResult(head2);

    return 0;
}
