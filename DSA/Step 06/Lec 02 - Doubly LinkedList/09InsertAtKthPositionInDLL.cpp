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

// ⭐️ New Function to insert a node at the k-th position ⭐️
Node* insertAtKthPosition(Node* head, int data, int k) {
    if (k < 1) return head;

    if (k == 1) {
        Node* newNode = new Node(data);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        return newNode;
    }

    Node* temp = head;
    int count = 1;
    while (temp != nullptr && count < k - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) return head;

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;

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
    int k = 3; // Position to insert at

    cout << "Original list: ";
    PrintDLL(head);

    // Insert the new node at the k-th position
    head = insertAtKthPosition(head, valueToInsert, k);

    cout << "List after inserting " << valueToInsert << " at position " << k << ": ";
    PrintDLL(head);

    return 0;
}
