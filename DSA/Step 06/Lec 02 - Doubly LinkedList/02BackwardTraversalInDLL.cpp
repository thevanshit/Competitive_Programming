#include <iostream>
#include <vector>
using namespace std;

// 1. Define the Node for the Doubly Linked List
class Node {
public:
    int data;
    Node* next; // Pointer to the next node
    Node* prev; // Pointer to the previous node

public:
    // Constructor for a node with data, pointing to nothing initially
    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }

    // A more complete constructor
    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

// 2. Function to convert a vector to a Doubly Linked List
Node* ConvertArrayToDLL(vector<int>& vec) {
    if (vec.empty()) return nullptr;

    Node* head = new Node(vec[0]);
    Node* prevNode = head;

    for (int i = 1; i < vec.size(); i++) {
        Node* temp = new Node(vec[i], nullptr, prevNode);
        prevNode->next = temp;
        prevNode = temp;
    }
    return head;
}

// 3. Function to print the Doubly Linked List (Forward)
void PrintDLL(Node* head) {
    Node* temp = head;
    cout << "Forward Traversal: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// 4. New Function to print the Doubly Linked List (Backward)
void PrintDLLBackward(Node* head) {
    // First, find the tail of the list
    Node* tail = head;
    if (tail == nullptr) { // Handle empty list
        cout << "Backward Traversal: List is empty." << endl;
        return;
    }
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // Now, traverse backward from the tail
    cout << "Backward Traversal: ";
    Node* temp = tail;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev; // Move backward using the 'prev' pointer
    }
    cout << endl;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    Node* head = ConvertArrayToDLL(vec);

    cout << "Successfully converted vector to Doubly Linked List!" << endl;
    PrintDLL(head);
    PrintDLLBackward(head); // Call the new backward traversal function
    return 0;
}
