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

// ⭐️ New Function to delete the head node ⭐️
Node* deleteHeadNode(Node* head) {
    // If the list is empty or has only one node
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    // Keep a backup of the old head to delete it later
    Node* prevHead = head;

    // Move the head pointer to the second node
    head = head->next;

    // Set the new head's 'prev' pointer to null
    head->prev = nullptr;

    // Disconnect the old head completely (good practice)
    prevHead->next = nullptr;

    // Delete the old head
    delete prevHead;

    return head; // Return the new head of the list
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

    // Delete the head node
    head = deleteHeadNode(head);

    cout << "List after deleting the head node: ";
    PrintDLL(head);

    return 0;
}
