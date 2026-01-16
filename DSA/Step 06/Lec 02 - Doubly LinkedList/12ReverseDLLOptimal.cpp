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

// ⭐️ New Function to reverse a DLL using the optimal pointer swap method ⭐️
Node* reverseDLL_Optimal(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* current = head;
    Node* last = nullptr;
    while (current != nullptr){
        last = current -> prev;
        current -> prev = current -> next;
        current -> next = last;
        current = current -> prev;
    }
    // The new head is the previous pointer of the last processed node.
    return last->prev;
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

    // Reverse the list using the optimal method
    head = reverseDLL_Optimal(head);

    cout << "List after optimal reversal: ";
    PrintDLL(head);

    return 0;
}
