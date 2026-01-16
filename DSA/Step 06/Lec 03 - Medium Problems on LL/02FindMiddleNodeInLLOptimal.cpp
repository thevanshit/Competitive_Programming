#include <iostream>
#include <vector>
using namespace std;

// Node class for a singly linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

// Convert vector to Linked List
Node* ConvertArrayToLL(vector<int>& vec) {
    if (vec.empty()) return nullptr;

    Node* head = new Node(vec[0]);
    Node* mover = head;
    for (size_t i = 1; i < vec.size(); i++) {
        Node* temp = new Node(vec[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// ⭐️ Optimal Approach: Find Middle using Tortoise-Hare ⭐️
Node* findMiddleNode_Optimal(Node* head) {
    if (head == nullptr) return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;        // move 1 step
        fast = fast->next->next; // move 2 steps
    }
    return slow; // slow is at the middle
}

// Print Linked List
void PrintLL(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test Case 1: Even length
    vector<int> vec1 = {1, 2, 3, 4, 5, 6};
    Node* head1 = ConvertArrayToLL(vec1);

    cout << "Original List 1: ";
    PrintLL(head1);

    Node* middle1 = findMiddleNode_Optimal(head1);
    cout << "Middle Node (Even) is: " << middle1->data << endl;

    cout << "-----------------------------" << endl;

    // Test Case 2: Odd length
    vector<int> vec2 = {1, 2, 3, 4, 5};
    Node* head2 = ConvertArrayToLL(vec2);

    cout << "Original List 2: ";
    PrintLL(head2);

    Node* middle2 = findMiddleNode_Optimal(head2);
    cout << "Middle Node (Odd) is: " << middle2->data << endl;

    return 0;
}
