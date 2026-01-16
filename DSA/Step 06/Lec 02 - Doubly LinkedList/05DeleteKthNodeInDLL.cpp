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

// ⭐️ New Function to delete the k-th node ⭐️
Node* deleteKthNode(Node* head, int k) {
    if (head == nullptr) return nullptr;

    if (k == 1) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return head;
    }

    Node* kthNode = head;
    int count = 1;
    while (kthNode != nullptr && count < k) {
        kthNode = kthNode->next;
        count++;
    }

    if (kthNode == nullptr) {
        return head;
    }

    Node* prevNode = kthNode->prev;
    Node* nextNode = kthNode->next;

    prevNode->next = nextNode;
    if (nextNode != nullptr) {
        nextNode->prev = prevNode;
    }

    delete kthNode;
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
    int k = 4; // Let's delete the 3rd node

    cout << "Original list: ";
    PrintDLL(head);

    // Delete the k-th node
    head = deleteKthNode(head, k);

    cout << "List after deleting the " << k << "-rd node: ";
    PrintDLL(head);

    return 0;
}
