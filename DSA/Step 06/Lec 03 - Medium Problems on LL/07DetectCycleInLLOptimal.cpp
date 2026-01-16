#include <iostream>
#include <vector>
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

// ⭐️ Optimal Function: Detect a cycle using Tortoise and Hare ⭐️
bool detectCycle_Optimal(Node* head) {
    // An empty or single-node list cannot have a cycle.
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    // The race begins!
    // The loop condition ensures fast->next->next is safe to access.
    while (fast != nullptr && fast->next != nullptr) {
        // Slow pointer moves one step.
        slow = slow->next;

        // Fast pointer moves two steps.
        fast = fast->next->next;

        // Check for a collision. If they meet, a cycle exists.
        if (slow == fast) {
            return true;
        }
    }

    // If the loop finishes, the fast pointer reached the end of the list. No cycle.
    return false;
}

// Helper to print the result
void printResult(Node* head) {
    if (detectCycle_Optimal(head)) {
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
