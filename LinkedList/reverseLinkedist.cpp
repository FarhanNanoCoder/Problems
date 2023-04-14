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
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }
    ListNode *next = head->next, *next2 = nullptr;
    head->next = nullptr;
    while (next != nullptr)
    {
        next2 = next->next;
        next->next = head;
        head = next;
        next = next2;
    }
    return head;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    // printList(head);
    head = reverseList(head);
    printList(head);
}