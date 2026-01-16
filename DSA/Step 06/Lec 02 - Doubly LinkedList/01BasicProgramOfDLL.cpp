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
        // Create a new node, linking its 'prev' to the previous node
        Node* temp = new Node(vec[i], nullptr, prevNode);
        // Link the previous node's 'next' to the new node
        prevNode->next = temp;
        // Move our tracker forward
        prevNode = temp;
    }
    return head;
}

// 3. Function to print the Doubly Linked List
void PrintDLL(Node* head) {
    Node* temp = head;
    cout << "Forward Traversal: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    Node* head = ConvertArrayToDLL(vec);

    cout << "Successfully converted vector to Doubly Linked List!" << endl;
    PrintDLL(head);

    return 0;
}
