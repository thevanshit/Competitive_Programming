#include <iostream>
using namespace std;

/* ──────────  node definition  ────────── */
struct Node {
    int   data;
    Node* next;
    explicit Node(int v) : data(v), next(nullptr) {}
};

/* ──────────  core logic  ────────── */
Node* sort012(Node* head)
{
    if (!head) return nullptr;

    /* three dummy heads make link-splicing easy */
    Node zeroDummy(0), oneDummy(0), twoDummy(0);
    Node *zero = &zeroDummy, *one = &oneDummy, *two = &twoDummy;

    for (Node* cur = head; cur; cur = cur->next) {
        if (cur->data == 0)      { zero->next = cur; zero = zero->next; }
        else if (cur->data == 1) { one ->next = cur; one  = one ->next; }
        else                     { two ->next = cur; two  = two ->next; }
    }

    /* stitch the three chains: 0-list → 1-list (if any) → 2-list */
    zero->next = oneDummy.next ? oneDummy.next : twoDummy.next;
    one ->next = twoDummy.next;
    two ->next = nullptr;                       // terminate

    return zeroDummy.next;                      // new head
}

/* ──────────  helpers (build / print / destroy)  ────────── */
Node* build(const int a[], int n)
{
    if (n == 0) return nullptr;
    Node *head = new Node(a[0]), *tail = head;
    for (int i = 1; i < n; ++i) { tail->next = new Node(a[i]); tail = tail->next; }
    return head;
}

void print(const Node* head)
{
    for (auto p = head; p; p = p->next) cout << p->data << ' ';
    cout << '\n';
}

void destroy(Node* head)
{
    while (head) { Node* tmp = head; head = head->next; delete tmp; }
}

/* ──────────  driver  ────────── */
int main()
{
    int arr[] = {1, 2, 0, 1, 2, 2, 1, 0, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = build(arr, n);

    cout << "Original list : ";  print(head);
    head = sort012(head);
    cout << "Sorted list   : ";  print(head);

    destroy(head);
    return 0;
}
