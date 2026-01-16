#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list node
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Helper to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper to build a linked list from a vector
Node* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    Node* head = new Node(vals[0]);
    Node* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new Node(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Function to delete the middle node (second middle for even length)
Node* deleteMiddle(Node* head) {
    if (!head || !head->next) {
        // Empty list or only one node (return nullptr)
        delete head;
        return nullptr;
    }

    // Step 1: Find the length n
    int n = 0;
    Node* temp = head;
    while (temp) {
        ++n;
        temp = temp->next;
    }

    // Step 2: Find the previous node to the middle node
    int mid = n / 2;
    temp = head;
    for (int i = 0; i < mid - 1; ++i) {
        temp = temp->next;
    }
    // Step 3: Delete the middle node
    Node* delNode = nullptr;
    if (mid == 0) {
        // List has 2 nodes, delete the second (head->next)
        delNode = head->next;
        head->next = head->next->next;
        delete delNode;
        return head;
    } else {
        delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = buildList(arr);

    cout << "Original List: ";
    printList(head);

    head = deleteMiddle(head);

    cout << "List after deleting the middle node: ";
    printList(head);

    // You can free memory here if you wish, omitted for brevity
    return 0;
}
