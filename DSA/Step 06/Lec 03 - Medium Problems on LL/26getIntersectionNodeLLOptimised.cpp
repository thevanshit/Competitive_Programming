// intersection_switch.cpp — compile with:  g++ -std=c++17 -Wall -O2 intersection_switch.cpp -o intersect
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

/* ── O(m+n)-time, O(1)-space intersection ── */
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    if (!headA || !headB) return nullptr;          // empty list ⇒ no intersection

    ListNode *pa = headA, *pb = headB;
    /* At most (lenA + lenB) iterations:
       • first pass walks own list
       • second pass walks the other list
       If an intersection exists, pointers meet there; otherwise both hit nullptr. */
    while (pa != pb) {
        pa = pa ? pa->next : headB;                // switch to headB when pa hits end
        pb = pb ? pb->next : headA;                // switch to headA when pb hits end
    }
    return pa;                                     // either common node or nullptr
}

/* ── helpers for quick demo ── */
ListNode* build(const int a[], int n)
{
    if (n == 0) return nullptr;
    ListNode *head = new ListNode(a[0]), *tail = head;
    for (int i = 1; i < n; ++i) { tail->next = new ListNode(a[i]); tail = tail->next; }
    return head;
}
void connect(ListNode* headA, ListNode* headB, int idx)
{
    ListNode* join = headA;
    for (int i = 0; i < idx && join; ++i) join = join->next;
    ListNode* tailB = headB;
    while (tailB && tailB->next) tailB = tailB->next;
    if (tailB) tailB->next = join;
}

int main()
{
    int A[] = {4,1,8,4,5};
    int B[] = {5,6,1};

    ListNode *headA = build(A,5), *headB = build(B,3);
    connect(headA, headB, 2);                      // make them intersect at “8”

    ListNode* node = getIntersectionNode(headA, headB);
    std::cout << "Intersection node value: " << (node ? node->val : -1) << '\n';
    return 0;
}
