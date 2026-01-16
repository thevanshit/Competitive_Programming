#include <iostream>
#include <vector>

// Using std namespace for cout, vector, etc.
using namespace std;

// Definition for singly-linked list, as provided.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// The Solution class containing your implementation.
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // If the list is empty or has fewer than three nodes,
        // no reordering is needed.
        if (!head || !head->next || !head->next->next) {
            return head;
        }

        // Initialize pointers for the odd and even chains.
        ListNode* odd_ptr = head;
        ListNode* even_ptr = head->next;
        
        // Keep a separate pointer to the head of the even list.
        // This will be attached to the end of the odd list later.
        ListNode* even_head = even_ptr;

        // Traverse the list, re-linking nodes.
        while (even_ptr && even_ptr->next) {
            // Link the current odd node to the next odd node.
            odd_ptr->next = even_ptr->next;
            // Move the odd pointer forward.
            odd_ptr = odd_ptr->next;

            // Link the current even node to the next even node.
            even_ptr->next = odd_ptr->next;
            // Move the even pointer forward.
            even_ptr = even_ptr->next;
        }

        // Attach the head of the even list to the tail of the odd list.
        odd_ptr->next = even_head;

        return head;
    }
};

// Helper function to create a linked list from a vector of integers.
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list.
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// The main function to run and test the code.
int main() {
    // --- Test Case 1 ---
    cout << "--- Test Case 1 ---" << endl;
    vector<int> vals1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(vals1);

    cout << "Original List: ";
    printList(head1);

    Solution sol;
    ListNode* reordered_head1 = sol.oddEvenList(head1);

    cout << "Reordered List: ";
    printList(reordered_head1);

    // --- Test Case 2 ---
    cout << "\n--- Test Case 2 ---" << endl;
    vector<int> vals2 = {2, 1, 3, 5, 6, 4, 7};
    ListNode* head2 = createList(vals2);
    
    cout << "Original List: ";
    printList(head2);

    ListNode* reordered_head2 = sol.oddEvenList(head2);
    
    cout << "Reordered List: ";
    printList(reordered_head2);

    // Note: In a real-world application, you would need to deallocate the memory
    // for the linked list nodes to prevent memory leaks. This is omitted for brevity.

    return 0;
}
