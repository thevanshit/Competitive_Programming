#include <iostream>
#include <vector>
using namespace std;

// Node for the Doubly Linked List
class Node {
public:
    int data;
    Node* next;
    Node* prev;

public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to convert a vector to a Doubly Linked List
Node* ConvertArrayToDLL(vector<int>& vec) {
    if (vec.empty()) return nullptr;

    Node* head = new Node(vec[0]);
    Node* prevNode = head;

    for (int i = 1; i < vec.size(); i++) {
        Node* temp = new Node(vec[i]);
        temp->prev = prevNode;
        prevNode->next = temp;
        prevNode = temp;
    }
    return head;
}

// Function to insert a node at the head
Node* insertAtHead(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }
    return newNode;
}

// ⭐️ New Function to insert a node at the tail ⭐️
Node* insertAtTail(Node* head, int data) {
    Node* newNode = new Node(data);

    // If the list is empty, the new node is the head
    if (head == nullptr) {
        return newNode;
    }

    // Traverse to the current last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Link the current tail's 'next' to the new node
    temp->next = newNode;

    // Link the new node's 'prev' to the current tail
    newNode->prev = temp;

    return head; // The head remains the same
}


// Function to print the Doubly Linked List (Forward)
void PrintDLL(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    Node* head = ConvertArrayToDLL(vec);
    int valueToInsert = 6;

    cout << "Original list: ";
    PrintDLL(head);

    // Insert the new node at the tail
    head = insertAtTail(head, valueToInsert);

    cout << "List after inserting " << valueToInsert << " at the tail: ";
    PrintDLL(head);

    // Test with an empty list
    Node* emptyHead = nullptr;
    cout << "\nEmpty list insertion test:" << endl;
    emptyHead = insertAtTail(emptyHead, 10);
    cout << "List after inserting 10 into empty list: ";
    PrintDLL(emptyHead);


    return 0;
}
