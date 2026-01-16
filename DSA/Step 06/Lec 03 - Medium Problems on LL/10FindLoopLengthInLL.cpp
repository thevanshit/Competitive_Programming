#include <iostream>
#include <unordered_map>

// Node class for a singly linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

// Function to find the length of a loop using a hash map
int findLoopLength(Node* head) {
    // This map stores the node pointer and the index where it was first seen.
    std::unordered_map<Node*, int> visitedNodes;
    
    Node* temp = head;
    int index = 0;

    // Traverse the list
    while (temp != nullptr) {
        // Check if the current node has been visited before.
        if (visitedNodes.find(temp) != visitedNodes.end()) {
            // If yes, a loop is found.
            // The length is the current index minus the index stored in the map.
            int loopLength = index - visitedNodes[temp];
            return loopLength;
        }

        // If not visited, store the node and its current index.
        visitedNodes[temp] = index;

        // Move to the next node and increment the index.
        index++;
        temp = temp->next;
    }

    // If the loop completes, no cycle was found.
    return 0;
}

// Helper function to test the code
void testSolution() {
    // --- Test Case 1: List with a cycle ---
    std::cout << "--- Test Case 1 ---" << std::endl;
    // Create a list: 1 -> 2 -> 3 -> 4 -> 5 -> (points back to 3)
    // The loop is 3 -> 4 -> 5 -> 3. Length = 3.
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    Node* cycleNode1 = new Node(3);
    head1->next->next = cycleNode1;
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = cycleNode1; // Create the cycle

    int length1 = findLoopLength(head1);
    if (length1 > 0) {
        std::cout << "Loop detected. Length of the loop is: " << length1 << std::endl;
    } else {
        std::cout << "No loop detected." << std::endl;
    }


    // --- Test Case 2: List without a cycle ---
    std::cout << "\n--- Test Case 2 ---" << std::endl;
    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);

    int length2 = findLoopLength(head2);
    if (length2 > 0) {
        std::cout << "Loop detected. Length of the loop is: " << length2 << std::endl;
    } else {
        std::cout << "No loop detected." << std::endl;
    }
}


int main() {
    testSolution();
    return 0;
}
