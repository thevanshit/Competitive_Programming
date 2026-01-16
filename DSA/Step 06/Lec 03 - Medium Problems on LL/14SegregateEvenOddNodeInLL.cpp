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
Node* buildList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    Node* head = new Node(nums[0]);
    Node* curr = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        curr->next = new Node(nums[i]);
        curr = curr->next;
    }
    return head;
}

// Function to segregate even and odd nodes using vectors
Node* segregateEvenOdd(Node* head) {
    vector<int> even, odd;

    for (Node* curr = head; curr; curr = curr->next) {
        if (curr->data % 2 == 0)
            even.push_back(curr->data);
        else
            odd.push_back(curr->data);
    }

    vector<int> result;
    result.insert(result.end(), even.begin(), even.end());
    result.insert(result.end(), odd.begin(), odd.end());

    // Rebuild the linked list with values from the result vector
    Node* newHead = buildList(result);
    return newHead;
}

int main() {
    vector<int> arr = {17, 15, 8, 9, 2, 4, 6};
    Node* head = buildList(arr);

    cout << "Original list: ";
    printList(head);

    Node* segregated = segregateEvenOdd(head);

    cout << "After segregating even and odd nodes: ";
    printList(segregated);

    // (Optional cleanup: You could free the memory here, skipped for brevity.)

    return 0;
}
