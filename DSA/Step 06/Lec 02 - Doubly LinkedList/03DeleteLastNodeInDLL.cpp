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

// ⭐️ New Function to delete the last node ⭐️
Node* deleteLastNode(Node* head) {
    // If the list is empty or has only one node
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    // Traverse to the last node (the tail)
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // Get the node before the tail
    Node* newTail = tail->prev;

    // Disconnect the tail from the list
    newTail->next = nullptr;
    tail->prev = nullptr;

    // Delete the old tail
    delete tail;

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
    vector<int> vec = {1, 2, 3, 4, 5};
    Node* head = ConvertArrayToDLL(vec);

    cout << "Original list: ";
    PrintDLL(head);

    // Delete the last node
    head = deleteLastNode(head);

    cout << "List after deleting the last node: ";
    PrintDLL(head);

    return 0;
}
