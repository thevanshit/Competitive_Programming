#include <iostream>
#include <vector>
#include <algorithm>      // std::sort

/* ─────────  Node definition  ───────── */
struct Node {
    int   data;
    Node* next;
    explicit Node(int v, Node* nxt = nullptr) : data(v), next(nxt) {}
};

/* ─────────  Utility helpers  ───────── */
void printList(const Node* head)
{
    for (auto cur = head; cur; cur = cur->next) std::cout << cur->data << ' ';
    std::cout << '\n';
}

void destroyList(Node* head)          // avoid memory leaks
{
    while (head) { Node* tmp = head; head = head->next; delete tmp; }
}

/* ─────────  Brute-force sort  ─────────
   1. Copy values into a std::vector
   2. std::sort the vector
   3. Copy values back into the original nodes                */
Node* sortList(Node* head)
{
    if (!head) return nullptr;

    std::vector<int> vals;
    for (Node* cur = head; cur; cur = cur->next) vals.push_back(cur->data);

    std::sort(vals.begin(), vals.end());

    Node* cur = head;
    for (int v : vals) { cur->data = v; cur = cur->next; }
    return head;
}

/* ─────────  Driver  ───────── */
int main()
{
    /* Sample list: 3 → 2 → 5 → 4 → 1 */
    Node* head = new Node(3);
    head->next  = new Node(2);
    head->next->next  = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    std::cout << "Original list : ";
    printList(head);

    head = sortList(head);

    std::cout << "Sorted list   : ";
    printList(head);

    destroyList(head);                // free memory
    return 0;
}
