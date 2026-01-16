#include <iostream>
#include <vector> // You forgot this header for vector
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

Node* InsertingNodeInTail(Node* Head, int val) {
    // Create the new node with the given value
    Node* newNode = new Node(val);

    // Case 1: If the list is empty, the new node is the head
    if (Head == nullptr) {
        return newNode;
    }

    // Case 2: Traverse to the last node
    Node* temp = Head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Link the last node to the new node
    temp->next = newNode;

    return Head; // The head of the list remains the same
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    int val = 7;
    Node* Head = ConvertArrayToLL(vec);
    Head = InsertingNodeInTail(Head, val);
    Node* temp = Head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
    return 0;
}
