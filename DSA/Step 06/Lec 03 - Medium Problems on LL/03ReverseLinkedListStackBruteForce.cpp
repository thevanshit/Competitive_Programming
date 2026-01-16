#include <iostream>
#include <vector>
#include <stack>
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

// Brute force: Reverse linked list using a stack
Node* reverseLinkedListStack(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    stack<Node*> st;
    Node* temp = head;

    // Step 1: Push all nodes onto the stack
    while (temp != nullptr) {
        st.push(temp);
        temp = temp->next;
    }

    // Step 2: Pop from stack to rebuild reversed list
    Node* newHead = st.top();
    st.pop();
    Node* current = newHead;

    while (!st.empty()) {
        current->next = st.top();
        st.pop();
        current = current->next;
    }
    current->next = nullptr; // Last node next should be nullptr

    return newHead;
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

    head = reverseLinkedListStack(head);

    cout << "Reversed List (Using Stack): ";
    PrintLL(head);

    return 0;
}
