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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);          // dummy head of the result list
        ListNode* tail = &dummy;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int sum = carry;        // start with previous carry

            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }

            carry = sum / 10;       // update (don’t redeclare!)
            tail->next = new ListNode(sum % 10);
            tail       = tail->next;
        }
        return dummy.next;          // first real node of the result
    }
};

/* ──────────  helpers  ────────── */
ListNode* build(const int a[], int n)
{
    if (n == 0) return nullptr;
    ListNode *head = new ListNode(a[0]), *tail = head;
    for (int i = 1; i < n; ++i) { tail->next = new ListNode(a[i]); tail = tail->next; }
    return head;
}

void print(const ListNode* head)
{
    for (const ListNode* p = head; p; p = p->next)
        cout << p->val << (p->next ? " -> " : "");
    cout << '\n';
}

void destroy(ListNode* head)
{
    while (head) { ListNode* tmp = head; head = head->next; delete tmp; }
}

/* ──────────  driver  ────────── */
int main()
{
    int a1[] = {9,8,5,7,9};   // represents 342
    int a2[] = {9,6,4,8,7};   // represents 465

    ListNode* l1 = build(a1,5);
    ListNode* l2 = build(a2,5);

    Solution sol;
    ListNode* sum = sol.addTwoNumbers(l1, l2);   // expect 7 -> 0 -> 8

    cout << "List 1 : "; print(l1);
    cout << "List 2 : "; print(l2);
    cout << "Sum    : "; print(sum);

    destroy(l1); destroy(l2); destroy(sum);      // free memory
    return 0;
}
