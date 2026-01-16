#include <iostream>
#include <vector>

// Using std namespace for cout, vector, etc.
using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor for Node with data and next node
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor for Node with only data (next set to nullptr)
    Node(int data1) {
        data = data1;
        next = nullptr;
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

// Function to delete the Nth node from the end of the linked list
Node* DeleteNthNodefromEnd(Node* head, int N) {
    if (head == NULL) {
        return NULL;
    }
    int cnt = 0;
    Node* temp = head;

    // First Pass: Count the number of nodes in the linked list
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    // Edge Case: If N equals the total number of nodes, delete the head
    if (cnt == N) {
        Node* newhead = head->next;
        delete (head);
        return newhead;
    }

    // Calculate the position of the node *before* the one to delete
    int res = cnt - N;
    temp = head;

    // Second Pass: Traverse to the node just before the one to delete
    while (temp != NULL) {
        res--;
        if (res == 0) {
            break;
        }
        temp = temp->next;
    }

    // Delete the Nth node from the end
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
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
    
    // Delete the Nth node from the end
    head = DeleteNthNodefromEnd(head, N);
    
    cout << "List after deleting " << N << "-th node from end: ";
    printLL(head);
    
    return 0;
}
