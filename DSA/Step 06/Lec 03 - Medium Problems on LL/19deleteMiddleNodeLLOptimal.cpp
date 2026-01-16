#include <iostream>
#include <vector>

// ─────────────────────  Node definition  ─────────────────────
struct Node
{
    int   data;
    Node* next;

    // Use an initialisation list (and make the ctor explicit)
    explicit Node(int val, Node* nxt = nullptr) : data(val), next(nxt) {}
};

// ─────────────────────  Helpers  ─────────────────────
void printLL(const Node* head)          // does not modify the list ➜ const
{
    for (auto cur = head; cur != nullptr; cur = cur->next)
        std::cout << cur->data << ' ';
    std::cout << '\n';
}

Node* createList(const std::vector<int>& v)
{
    Node *head = nullptr, *tail = nullptr;

    for (int x : v)
    {
        Node* tmp = new Node(x);
        if (head == nullptr)
            head = tail = tmp;
        else
        {
            tail->next = tmp;
            tail       = tmp;
        }
    }
    return head;
}

void destroyList(Node* head)            // avoid memory leaks
{
    while (head)
    {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// ─────────────────────  Core logic  ─────────────────────
Node* deleteMiddle(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {                                   // 0 or 1 node ➜ return empty list
        delete head;
        return nullptr;
    }

    Node *slow = head, *fast = head, *prev = nullptr;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast  = fast->next->next;       // 2-step jump
        prev  = slow;                   // lag behind slow by one
        slow  = slow->next;             // 1-step jump
    }
    // slow now points at the middle node
    prev->next = slow->next;            // unlink it
    delete slow;

    return head;
}

// ─────────────────────  Driver  ─────────────────────
int main()
{
    std::cout << "--- Test 1 (odd length) ---\n";
    Node* head1 = createList({1,2,3,4,5});
    printLL(head1);
    head1 = deleteMiddle(head1);
    printLL(head1);
    destroyList(head1);

    std::cout << "\n--- Test 2 (even length) ---\n";
    Node* head2 = createList({2,1,3,5,6,4});
    printLL(head2);
    head2 = deleteMiddle(head2);        // removes the “second” middle (5)
    printLL(head2);
    destroyList(head2);
}
