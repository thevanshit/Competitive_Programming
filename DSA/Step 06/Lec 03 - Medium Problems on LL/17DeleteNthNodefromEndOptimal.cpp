#include <iostream>
#include <vector>

// Using std namespace for cout, vector, etc.
using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor with data and next node
    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

// Function to print the linked list
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to delete the Nth node from the end (Optimal Two-Pointer Approach)
Node* DeleteNthNodefromEnd(Node* head, int N) {
    // Create two pointers, fastp and slowp, both starting at the head
    Node* fastp = head;
    Node* slowp = head;

    // Move the fastp pointer N nodes ahead
    for (int i = 0; i < N; i++) {
        // This check handles cases where N is larger than the list size,
        // though the problem constraints usually prevent this.
        if (fastp == nullptr) return head; 
        fastp = fastp->next;
    }

    // Edge Case: If fastp becomes NULL, it means N is equal to the list's length.
    // Therefore, the head node must be deleted.
    if (fastp == NULL) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    // Move both pointers one step at a time until fastp reaches the last node.
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // At this point, slowp is at the node just before the one to be deleted.
    // Delete the Nth node from the end.
    Node* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    
    return head;
}

// Helper function to create a linked list from a vector
Node* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node* head = createList(arr);

    cout << "Original list: ";
    printLL(head);

    // Delete the Nth node from the end and print the modified list
    head = DeleteNthNodefromEnd(head, N);
    
    cout << "List after deleting " << N << "-th node from end: ";
    printLL(head);

    return 0;
}
