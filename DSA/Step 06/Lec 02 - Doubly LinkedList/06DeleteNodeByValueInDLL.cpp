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

// ⭐️ New Function to delete a node by its value ⭐️
Node* deleteNodeByValue(Node* head, int valueToDelete) {
    Node* temp = head;
    while (temp != nullptr && temp->data != valueToDelete) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        return head;
    }

    Node* prevNode = temp->prev;
    Node* nextNode = temp->next;

    if (prevNode == nullptr) {
        head = nextNode;
    } else {
        prevNode->next = nextNode;
    }

    if (nextNode != nullptr) {
        nextNode->prev = prevNode;
    }

    delete temp;
    return head;
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
    vector<int> vec = {1, 100, 31, 40, 5};
    Node* head = ConvertArrayToDLL(vec);
    int valueToDelete = 100; // Let's delete the node with value 3

    cout << "Original list: ";
    PrintDLL(head);

    // Delete the node with the given value
    head = deleteNodeByValue(head, valueToDelete);

    cout << "List after deleting node with value " << valueToDelete << ": ";
    PrintDLL(head);

    return 0;
}
