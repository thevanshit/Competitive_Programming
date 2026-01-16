#include <iostream>
using namespace std;

/* ──────────  node definition  ────────── */
struct ListNode {
    int       val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

/* ──────────  core solution  ────────── */
class Solution {
    /* count how many nodes are in a list */
    static int length(ListNode* head) {
        int cnt = 0;
        while (head) { ++cnt; head = head->next; }
        return cnt;
    }

public:
    /* return first common node, or nullptr if the lists never meet */
    static ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        int lenA = length(headA);
        int lenB = length(headB);

        ListNode *pa = headA, *pb = headB;

        /* advance pointer of the longer list by |lenA − lenB| nodes */
        if (lenA > lenB) {
            for (int d = lenA - lenB; d--; ) pa = pa->next;
        } else {
            for (int d = lenB - lenA; d--; ) pb = pb->next;
        }

        /* walk both lists together until the pointers meet (or reach end) */
        while (pa && pb) {
            if (pa == pb) return pa;      // first common node
            pa = pa->next;
            pb = pb->next;
        }
        return nullptr;                   // no intersection
    }
};

/* ──────────  helper utilities for demo  ────────── */
ListNode* build(const int a[], int n)
{
    if (n == 0) return nullptr;
    ListNode *head = new ListNode(a[0]), *tail = head;
    for (int i = 1; i < n; ++i) { tail->next = new ListNode(a[i]); tail = tail->next; }
    return head;
}

void connect(ListNode* headA, ListNode* headB, int idx)   // splice B’s tail to idx-th node of A
{
    ListNode* join = headA;
    for (int i = 0; i < idx && join; ++i) join = join->next;

    ListNode* tailB = headB;
    while (tailB && tailB->next) tailB = tailB->next;

    if (tailB) tailB->next = join;
}

/* ──────────  simple driver  ────────── */
int main()
{
    int A[] = {4, 1, 8, 4, 5};
    int B[] = {5, 6, 1};

    ListNode *headA = build(A, 5);
    ListNode *headB = build(B, 3);
    connect(headA, headB, 2);                    // lists now intersect at value 8

    ListNode* node = Solution::getIntersectionNode(headA, headB);

    if (node) cout << "Intersection node value: " << node->val << '\n';
    else      cout << "No intersection\n";

    return 0;
}
