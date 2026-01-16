#include <iostream>
// Note: <bits/stdc++.h> is a non-standard header.
// For wider compatibility on macOS, it's better to include just what you need.
// In this case, only <iostream> is required.

using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Helper function to find the length of the loop
// This is called AFTER a cycle has been detected.
int findLength(Node* slow, Node* fast){
    
    // Initialize a counter for the nodes in the loop.
    int cnt = 1;
    
    // Move the fast pointer one step forward.
    fast = fast->next;
    
    // Traverse the loop with the fast pointer until it meets the slow pointer again.
    while(slow != fast){
        cnt++;
        fast = fast->next;
    }
    
    // The count is the length of the loop.
    return cnt;
}

// Main function to find the length of the loop in a linked list
int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Step 1: Traverse the list to detect a loop
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;     // Move slow one step
        fast = fast->next->next; // Move fast two steps

        // Step 2: If the slow and fast pointers meet, a loop is found.
        if (slow == fast) {
            // Call the helper function to count the nodes in the loop.
            return findLength(slow, fast);
        }
    }

    // Step 3: If the fast pointer reaches the end, there is no loop.
    return 0; 
}


int main() {
    // Create a sample linked list with a loop
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Create the links for the list
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // Create a loop from the fifth node back to the second node.
    // The loop is: 2 -> 3 -> 4 -> 5 -> 2. Length = 4.
    fifth->next = second; 

    int loopLength = lengthOfLoop(head);
    
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    // Note: Proper memory deallocation for a cyclic list is complex
    // and omitted here for simplicity, as the focus is on the algorithm.

    return 0;
}
