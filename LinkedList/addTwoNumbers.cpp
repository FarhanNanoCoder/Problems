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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    ListNode *ptr = nullptr, *head = nullptr;
    while (l1 != nullptr || l2 != nullptr)
    {
        int sum;
        if (l1 == nullptr)
            sum = l2->val + carry;
        else if (l2 == nullptr)
            sum = l1->val + carry;
        else
            sum = l1->val + l2->val + carry;

        if (sum > 9)
            carry = 1;
        else
            carry = 0;

        ListNode *temp = new ListNode(sum % 10);
        if (ptr == nullptr)
            head = temp;
        else
            ptr->next = temp;
        ptr = temp;

        if (l1 == nullptr)
            l2 = l2->next;
        else if (l2 == nullptr)
            l1 = l1->next;
        else
        {
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    if (carry != 0)
    {
        ListNode *temp = new ListNode(carry);
        if (ptr == nullptr)
            head = temp;
        else
            ptr->next = temp;
    }
    return head;
}

int main()
{
    ListNode *head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);

    ListNode *head1 = new ListNode(5);
    head1->next = new ListNode(6);
    head1->next->next = new ListNode(4);
    ListNode *temp = addTwoNumbers(head, head1);
    printList(temp);
}
// problem_link: https://leetcode.com/problems/add-two-numbers/description/