#include <iostream>
// Note: <bits/stdc++.h> is a non-standard header.
// It's better practice to include only what's necessary.
// In this case, only <iostream> is needed.

using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    int data;   
    Node* next;      

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

// Function to reverse a linked list using the recursive approach
Node* reverseLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }

    Node* newHead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

// Function to check if the linked list is a palindrome (Optimal Approach)
bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; 
    }
    
    // Step 1: Find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;  
        fast = fast->next->next;  
    }
    
    // Step 2: Reverse the second half of the list
    Node* newHead = reverseLinkedList(slow->next);
    
    // Step 3: Compare the first and second halves
    Node* first = head;  
    Node* second = newHead; 
    while (second != NULL) {
        if (first->data != second->data) {
            // Restore the list before returning
            reverseLinkedList(newHead);  
            return false;
        }
        first = first->next; 
        second = second->next;  
    }
    
    // Step 4: Restore the list to its original state
    reverseLinkedList(newHead);  
    
    return true;  
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with values 1, 5, 2, 5, 1 (a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    cout << "Linked List after check (should be restored): ";
    printLinkedList(head);

    return 0;
}
