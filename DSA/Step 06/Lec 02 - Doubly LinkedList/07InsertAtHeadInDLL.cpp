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

// ⭐️ New Function to insert a node at the head ⭐️
Node* insertAtHead(Node* head, int data) {
    // Create the new node. Its 'prev' will be nullptr.
    Node* newNode = new Node(data);
    newNode->next = head;

    // If the list is not empty, link the old head back to the new node
    if (head != nullptr) {
        head->prev = newNode;
    }

    // The new node is the new head of the list
    return newNode;
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
    int valueToInsert = 0;

    cout << "Original list: ";
    PrintDLL(head);

    // Insert the new node at the head
    head = insertAtHead(head, valueToInsert);

    cout << "List after inserting " << valueToInsert << " at the head: ";
    PrintDLL(head);

    return 0;
}
