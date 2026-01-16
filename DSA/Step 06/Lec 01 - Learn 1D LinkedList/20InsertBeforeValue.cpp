#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
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

Node* InsertBeforeValue(Node* Head, int val, int beforeVal) {
    // Case 1: Empty list
    if (Head == nullptr) return nullptr;

    Node* newNode = new Node(val);

    // Case 2: Insert before head
    if (Head->data == beforeVal) {
        newNode->next = Head;
        return newNode; // New node becomes the head
    }

    // Case 3: Traverse list to find the node before 'beforeVal'
    Node* temp = Head;
    while (temp->next != nullptr && temp->next->data != beforeVal) {
        temp = temp->next;
    }

    // If we found the node
    if (temp->next != nullptr) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    // If value not found → do nothing

    return Head;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    Node* Head = ConvertArrayToLL(vec);

    int val = 100;       // value to insert
    int beforeVal = 3;   // insert before node with value 3
    Head = InsertBeforeValue(Head, val, beforeVal);

    Node* temp = Head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
    return 0;
}
