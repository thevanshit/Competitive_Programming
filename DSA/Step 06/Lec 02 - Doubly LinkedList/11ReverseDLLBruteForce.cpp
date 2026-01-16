#include <iostream>
#include <vector>
#include <stack> // Required for std::stack
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

// ⭐️ New Function to reverse a DLL using the brute-force stack method ⭐️
Node* reverseDLL_BruteForce(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    stack<int> st;
    Node* temp = head;

    // Push all node data into the stack
    while (temp != nullptr) {
        st.push(temp->data);
        temp = temp->next;
    }

    // Pop from stack and update node data
    temp = head;
    while (temp != nullptr) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

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

    cout << "Original list: ";
    PrintDLL(head);

    // Reverse the list using the brute-force method
    head = reverseDLL_BruteForce(head);

    cout << "List after brute-force reversal: ";
    PrintDLL(head);

    return 0;
}
