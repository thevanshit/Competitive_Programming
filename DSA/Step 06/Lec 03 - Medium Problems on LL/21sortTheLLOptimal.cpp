#include <iostream>
#include <vector>
using namespace std;

/* ──────────  Node definition  ────────── */
struct Node {
    int   val;
    Node* next;
    explicit Node(int v, Node* nxt = nullptr) : val(v), next(nxt) {}
};

/* ──────────  Utilities  ────────── */
void printList(const Node* head)
{
    for (auto cur = head; cur; cur = cur->next) cout << cur->val << ' ';
    cout << '\n';
}

Node* buildList(const vector<int>& v)
{
    Node *head = nullptr, *tail = nullptr;
    for (int x : v) {
        Node* n = new Node(x);
        if (!head) head = tail = n;
        else { tail->next = n; tail = n; }
    }
    return head;
}

void destroyList(Node* head)
{
    while (head) { Node* tmp = head; head = head->next; delete tmp; }
}

/* ──────────  Merge-sort on list  ────────── */
static Node* merge(Node* a, Node* b)          // merge two sorted lists
{
    Node dummy(0); Node* tail = &dummy;
    while (a && b) {
        if (a->val <= b->val) { tail->next = a; a = a->next; }
        else                  { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = (a ? a : b);
    return dummy.next;
}

static Node* mergeSort(Node* head)
{
    if (!head || !head->next) return head;    // 0- or 1-node list

    /* 1️⃣  Split list into two halves */
    Node *slow = head, *fast = head->next;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    Node* mid = slow->next;
    slow->next = nullptr;                     // break

    /* 2️⃣  Recursively sort both halves */
    Node* left  = mergeSort(head);
    Node* right = mergeSort(mid);

    /* 3️⃣  Merge and return */
    return merge(left, right);
}

/* ──────────  Demo  ────────── */
int main()
{
    Node* head1 = buildList({4, 2, 1, 3});
    cout << "Original : ";  printList(head1);
    head1 = mergeSort(head1);
    cout << "Sorted   : ";  printList(head1);
    destroyList(head1);

    cout << '\n';

    Node* head2 = buildList({-1, 5, 3, 4, 0});
    cout << "Original : ";  printList(head2);
    head2 = mergeSort(head2);
    cout << "Sorted   : ";  printList(head2);
    destroyList(head2);

    return 0;
}
