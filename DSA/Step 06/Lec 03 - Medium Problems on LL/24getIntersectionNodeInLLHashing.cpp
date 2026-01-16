#include <iostream>
#include <unordered_set>
using namespace std;

/* ──────────  Node definition  ────────── */
struct ListNode {
    int       val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

/* ──────────  Hash-based intersection  ────────── */
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    unordered_set<ListNode*> seen;          // store addresses of list-A nodes

    for (ListNode* p = headA; p; p = p->next)
        seen.insert(p);

    for (ListNode* p = headB; p; p = p->next)
        if (seen.count(p))                  // first common pointer = intersection
            return p;

    return nullptr;                         // no common node
}

/* ──────────  Helpers for quick demo  ────────── */
ListNode* build(const int a[], int n)                   // create list from array
{
    if (n == 0) return nullptr;
    ListNode *head = new ListNode(a[0]), *tail = head;
    for (int i = 1; i < n; ++i) { tail->next = new ListNode(a[i]); tail = tail->next; }
    return head;
}

/* splice tail of list B to the idx-th node of list A to force an intersection */
void connect(ListNode* headA, ListNode* headB, int idx)
{
    ListNode* join = headA;
    for (int i = 0; i < idx && join; ++i) join = join->next;

    ListNode* tailB = headB;
    while (tailB && tailB->next) tailB = tailB->next;

    if (tailB) tailB->next = join;
}

/* ──────────  Demo  ────────── */
int main()
{
    /* Example: intersect at value 8 */
    int A[] = {4,1,8,4,5};
    int B[] = {5,6,1};

    ListNode *headA = build(A,5), *headB = build(B,3);
    connect(headA, headB, 2);                      // hook B onto A’s node “8”

    ListNode* node = getIntersectionNode(headA, headB);
    if (node) cout << "Intersection at node value: " << node->val << '\n';
    else      cout << "No intersection\n";

    /* clean-up omitted for brevity */
    return 0;
}
