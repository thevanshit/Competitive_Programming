#include <iostream>

// Note: The <unordered_map> include from your original code is not actually used,
// so it can be safely removed. I've kept the code identical to yours otherwise.
// #include <unordered_map> 

// Using std namespace for cout and endl
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

// Function to find the first node of the loop in a linked list
Node* firstNode(Node* head) {
    
    // Initialize a slow and fast pointers to the head of the list
    Node* slow = head;  
    Node* fast = head;  

    // Phase 1: Detect the loop
    while (fast != NULL && fast->next != NULL) {
        
        // Move slow one step
        slow = slow->next;        
        
        // Move fast two steps
        fast = fast->next->next;  

        // If slow and fast meet, a loop is detected
        if (slow == fast) {
            
             // Reset the slow pointer to the head of the list
            slow = head; 

            // Phase 2: Find the first node of the loop
            while (slow != fast) {
                
                // Move slow and fast one step at a time
                slow = slow->next;  
                fast = fast->next;  
            }
            
            // Return the first node of the loop
            return slow;  
        }
    }
    
     // If no loop is found, return NULL
    return NULL; 
}


int main() {
    // Create a sample linked list with a loop
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1->next = node2;
    Node* node3 = new Node(3);
    node2->next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4->next = node5;

    // Make a loop from node5 back to node2
    node5->next = node2;

    // Set the head of the linked list
    Node* head = node1;

    // Detect the loop in the linked list
    Node* loopStartNode = firstNode(head);

    if (loopStartNode) {
        cout << "Loop detected. Starting node of the loop is: " << loopStartNode->data << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // --- Clean up memory to avoid leaks ---
    // A robust solution for deleting a cyclic list is complex.
    // For this example, we'll just confirm the code runs.
    // In a real application, you would need a strategy to break the cycle
    // before freeing the nodes to avoid an infinite loop.

    return 0;
}
