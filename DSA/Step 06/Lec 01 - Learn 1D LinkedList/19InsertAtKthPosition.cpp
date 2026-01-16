#include <iostream>
#include <vector> // You were missing this header for vector
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;
public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* ConvertArrayToLL(vector<int>& vec) {
    if (vec.empty()) return nullptr;

    Node* Head = new Node(vec[0]);
    Node* Mover = Head;

    for (int i = 1; i < vec.size(); i++) {
        Node* temp = new Node(vec[i]);
        Mover->next = temp;
        Mover = temp;
    }
    return Head;
}

Node* InsertAtKthPosition(Node* Head, int val, int k) {
    // If k is less than 1, it's an invalid position
    if (k < 1) return Head;

    // Create the new node
    Node* newNode = new Node(val);

    // Case 1: Insert at the head (k=1)
    if (k == 1) {
        newNode->next = Head;
        return newNode; // The new node is now the head
    }

    // Case 2: Traverse to the node at position k-1
    Node* temp = Head;
    int count = 1;
    while (temp != nullptr && count < k - 1) {
        temp = temp->next;
        count++;
    }

    // If k is out of bounds (e.g., list has 5 nodes and k=7), do nothing
    if (temp == nullptr) {
        delete newNode; // Clean up the unused node
        return Head;
    }

    // Link the new node into the list
    newNode->next = temp->next;
    temp->next = newNode;

    return Head; // The head remains the same
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    int val = 100;
    int k = 3; // We want to insert at the 3rd position

    Node* Head = ConvertArrayToLL(vec);
    Head = InsertAtKthPosition(Head, val, k);

    Node* temp = Head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
    return 0;
}
