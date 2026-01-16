#include <iostream>
#include <vector>
using namespace std;

// Node definition for singly linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

// Helper to create a linked list from vector
Node* ConvertArrayToLL(vector<int>& vec) {
    if (vec.empty()) return nullptr;

    Node* head = new Node(vec[0]);
    Node* current = head;
    for (size_t i = 1; i < vec.size(); i++) {
        current->next = new Node(vec[i]);
        current = current->next;
    }
    return head;
}

// ⭐️ Optimal Approach: Reverse links in-place (Iterative) ⭐️
Node* reverseLinkedListOptimal1(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextTemp = nullptr;

    while (current != nullptr) {
        // 1. Store the next node before we lose its reference
        nextTemp = current->next;
        
        // 2. Reverse the link: current node points to the previous one
        current->next = prev;
        
        // 3. Move the pointers one step forward for the next iteration
        prev = current;
        current = nextTemp;
    }

    // When the loop ends, 'prev' will be the new head
    return prev;
}

// Helper to print linked list
void PrintLL(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    Node* head = ConvertArrayToLL(vec);

    cout << "Original List: ";
    PrintLL(head);

    head = reverseLinkedListOptimal1(head);

    cout << "Reversed List (Optimal): ";
    PrintLL(head);

    return 0;
}
