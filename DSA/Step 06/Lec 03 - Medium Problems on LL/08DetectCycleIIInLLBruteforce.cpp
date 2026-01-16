#include <iostream>

// Definition for singly-linked list, as used in the problem.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // --- Phase 1: Detect if a cycle exists ---
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            // If they meet, a cycle is present. Break to start Phase 2.
            if (slow == fast) {
                break;
            }
        }

        // If the loop finished because fast reached the end, there's no cycle.
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        // --- Phase 2: Find the start of the cycle ---
        // Reset one pointer to the head. Keep the other at the meeting point.
        slow = head;
        
        // Move both pointers one step at a time until they meet.
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // The meeting point is the start of the cycle.
        return slow;
    }
};

// Helper function to test the code
void testSolution() {
    // --- Test Case 1: List with a cycle ---
    std::cout << "--- Test Case 1 ---" << std::endl;
    // Create a list: 1 -> 2 -> 3 -> 4 -> 5 -> (points back to 3)
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    ListNode* cycleNode1 = new ListNode(3);
    head1->next->next = cycleNode1;
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    head1->next->next->next->next->next = cycleNode1; // This creates the cycle

    Solution sol;
    ListNode* startOfCycle1 = sol.detectCycle(head1);

    if (startOfCycle1 != nullptr) {
        std::cout << "Cycle detected. It starts at node with value: " << startOfCycle1->val << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    // --- Test Case 2: List without a cycle ---
    std::cout << "\n--- Test Case 2 ---" << std::endl;
    ListNode* head2 = new ListNode(10);
    head2->next = new ListNode(20);
    head2->next->next = new ListNode(30);
    
    ListNode* startOfCycle2 = sol.detectCycle(head2);
    
    if (startOfCycle2 != nullptr) {
        std::cout << "Cycle detected. It starts at node with value: " << startOfCycle2->val << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    // --- Clean up memory to avoid leaks (tricky for cyclic lists) ---
    // For simplicity, we just delete the non-cyclic list.
    // A robust solution would break the cycle before deleting.
    delete head2->next->next;
    delete head2->next;
    delete head2;

    // For the cyclic list, we can manually delete the nodes after breaking the cycle
    head1->next->next->next->next->next = nullptr; // Break the cycle
    delete head1->next->next->next->next;
    delete head1->next->next->next;
    delete head1->next->next;
    delete head1->next;
    delete head1;
}

int main() {
    testSolution();
    return 0;
}
