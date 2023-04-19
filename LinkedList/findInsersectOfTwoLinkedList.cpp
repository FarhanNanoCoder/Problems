#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{

    if (headA == nullptr || headB == nullptr)
        return nullptr;
    ListNode *ptr1 = headA, *ptr2 = headB;
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1 == nullptr ? headB : ptr1->next;
        ptr2 = ptr2 == nullptr ? headA : ptr2->next;
    }
    return ptr1;
}
int main()
{
    ListNode *head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);

    ListNode *head1 = new ListNode(5);

    head1->next = new ListNode(6);
    head->next->next->next = head1->next;
    head1->next->next = new ListNode(4);
    ListNode *temp = getIntersectionNode(head, head1);
    printList(temp);
}

// problem_link: https://leetcode.com/problems/intersection-of-two-linked-lists/