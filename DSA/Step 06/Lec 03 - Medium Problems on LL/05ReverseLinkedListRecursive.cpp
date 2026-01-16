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

// Helper to create a linked list from a vector
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

// ⭐️ Recursive Approach: Reverse a linked list ⭐️
Node* reverseLinkedListRecursive(Node* head) {
    // Base Case: If the list is empty or has one node, it's already reversed.
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recursive Step: Reverse the rest of the list.
    // 'newHead' will be the head of the reversed sub-list (the original tail).
    Node* newHead = reverseLinkedListRecursive(head->next);

    // After the recursion, 'head' is the second-to-last node of the original list.
    // 'head->next' is the last node. We need to make it point back to 'head'.
    Node* front = head->next;
    front->next = head;

    // The current 'head' becomes the new tail, so its 'next' must be null.
    head->next = nullptr;

    // Return the new head, which was found in the deepest recursive call.
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

    head = reverseLinkedListRecursive(head);

    cout << "Reversed List (Recursive): ";
    PrintLL(head);

    return 0;
}
