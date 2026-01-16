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

// ⭐️ New Function to insert a node before a specific value ⭐️
Node* insertBeforeValue(Node* head, int dataToInsert, int targetValue) {
    if (head == nullptr) return head;

    if (head->data == targetValue) {
        Node* newNode = new Node(dataToInsert);
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp != nullptr && temp->data != targetValue) {
        temp = temp->next;
    }

    if (temp == nullptr) return head;

    Node* prevNode = temp->prev;
    Node* newNode = new Node(dataToInsert);

    newNode->next = temp;
    newNode->prev = prevNode;
    prevNode->next = newNode;
    temp->prev = newNode;

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
    int valueToInsert = 100;
    int targetValue = 5; // The "K" value to insert before

    cout << "Original list: ";
    PrintDLL(head);

    // Insert the new node
    head = insertBeforeValue(head, valueToInsert, targetValue);

    cout << "List after inserting " << valueToInsert << " before " << targetValue << ": ";
    PrintDLL(head);

    return 0;
}
