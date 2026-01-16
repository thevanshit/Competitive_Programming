#include <iostream>
#include <vector>
using namespace std;

// Node class for a singly linked list
class Node {
public:
    int data;
    Node* next;
public:
    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

// Helper function to create a linked list from a vector
Node* ConvertArrayToLL(vector<int>& vec) {
    if (vec.empty()) return nullptr;
    Node* head = new Node(vec[0]);
    Node* mover = head;
    for (int i = 1; i < vec.size(); i++) {
        Node* temp = new Node(vec[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// ⭐️ Function to find the middle node using the brute-force method ⭐️
Node* findMiddleNode_BruteForce(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    // --- Pass 1: Count the total number of nodes ---
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    // --- Pass 2: Traverse to the middle node ---
    // The target position is count / 2. This works for both odd and even cases.
    int middlePosition = count / 2;
    temp = head; // Reset the pointer to the head

    for (int i = 0; i < middlePosition; i++) {
        temp = temp->next;
    }

    return temp;
}

// Helper function to print the linked list
void PrintLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Test Case 1: Even number of nodes
    vector<int> vec1 = {1, 2, 3, 4, 5, 6};
    Node* head1 = ConvertArrayToLL(vec1);
    cout << "Original List 1: ";
    PrintLL(head1);
    Node* middle1 = findMiddleNode_BruteForce(head1);
    cout << "Middle Node is: " << middle1->data << endl;

    cout << "--------------------" << endl;

    // Test Case 2: Odd number of nodes
    vector<int> vec2 = {1, 2, 3, 4, 5};
    Node* head2 = ConvertArrayToLL(vec2);
    cout << "Original List 2: ";
    PrintLL(head2);
    Node* middle2 = findMiddleNode_BruteForce(head2);
    cout << "Middle Node is: " << middle2->data << endl;

    return 0;
}
