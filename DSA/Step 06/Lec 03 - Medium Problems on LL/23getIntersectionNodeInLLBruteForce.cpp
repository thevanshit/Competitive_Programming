#include <iostream>
using namespace std;

/* ──────────  node definition  ────────── */
struct ListNode {
    int       val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

/* ──────────  brute-force intersection  ──────────
   Time  O(m · n)   |   Aux-space  O(1)                        */
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    for (ListNode* a = headA; a; a = a->next)          // every node in A
        for (ListNode* b = headB; b; b = b->next)      // every node in B
            if (a == b)                                // same memory address
                return a;                              // first common node
    return nullptr;                                    // no intersection
}

/* ──────────  helpers only for demo / testing  ────────── */
ListNode* build(const int arr[], int n)                // make list from array
{
    if (n == 0) return nullptr;
    ListNode *head = new ListNode(arr[0]), *tail = head;
    for (int i = 1; i < n; ++i) { tail->next = new ListNode(arr[i]); tail = tail->next; }
    return head;
}
/* connect tail of listB to node index idx in listA (0-based) */
void connect(ListNode* headA, ListNode* headB, int idx)
{
    ListNode* join = headA;
    for (int i = 0; i < idx && join; ++i) join = join->next;
    ListNode* tailB = headB;
    while (tailB && tailB->next) tailB = tailB->next;
    if (tailB) tailB->next = join;
}
/* destroy list (safe even if two lists share nodes) */
void destroy(ListNode* head, ListNode* stop = nullptr)
{
    while (head && head != stop) { ListNode* tmp = head; head = head->next; delete tmp; }
}

/* ──────────  basic demo  ────────── */
int main()
{
    /* Example with intersection at value 8 */
    int arrA[] = {4,1,8,4,5};
    int arrB[] = {5,6,1};
    ListNode *headA = build(arrA,5), *headB = build(arrB,3);
    connect(headA, headB, 2);             // splice B to A’s node “8”

    ListNode* node = getIntersectionNode(headA, headB);
    cout << (node ? node->val : -1) << '\n';   // prints 8

    destroy(headB, headA); destroy(headA);
    return 0;
}
