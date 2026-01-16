#include <iostream>
using namespace std;

/* ──────────  node definition  ────────── */
struct Node {
    int   data;
    Node* next;
    explicit Node(int v) : data(v), next(nullptr) {}
};

/* reverse a list and return new head */
static Node* reverse(Node* head)
{
    Node *prev = nullptr, *cur = head;
    while (cur) { Node* nxt = cur->next; cur->next = prev; prev = cur; cur = nxt; }
    return prev;
}

/* add 1 to the number represented by the list */
Node* addOne(Node* head)
{
    head = reverse(head);                 // 1️⃣ work from least-significant digit
    Node* cur  = head;
    int   carry = 1;                      // initial “+1”

    while (cur && carry) {                // propagate carry
        cur->data += carry;
        carry      = cur->data / 10;
        cur->data %= 10;

        if (carry && cur->next == nullptr) {   // need an extra digit
            cur->next = new Node(carry);
            carry = 0;
        }
        cur = cur->next;
    }
    return reverse(head);                 // 3️⃣ restore original order
}

/* ──────────  helpers for quick demo  ────────── */
Node* build(const int a[], int n)
{
    if (n == 0) return nullptr;
    Node *head = new Node(a[0]), *tail = head;
    for (int i = 1; i < n; ++i) { tail->next = new Node(a[i]); tail = tail->next; }
    return head;
}
void print(const Node* head)
{
    for (auto p = head; p; p = p->next) cout << p->data << (p->next ? "->" : "");
    cout << '\n';
}

/* ──────────  driver  ────────── */
int main()
{
    int digits[] = {1, 2, 9};                 // represents 129
    Node* head = build(digits, 3);

    cout << "Original number : ";  print(head);
    head = addOne(head);
    cout << "After adding one : "; print(head);

    return 0;
}
