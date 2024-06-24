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

ListNode *getMid(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    ListNode *pre = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = nullptr;
    return slow;
}
ListNode *mergeList(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr)
        return list2;
    else if (list2 == nullptr)
        return list1;
    ListNode *res, *temp = nullptr;

    if (list1->val > list2->val)
    {
        temp = list1;
        list1 = list2;
        list2 = temp;
        temp = nullptr;
    }
    res = list1;

    while (list1 != nullptr)
    {
        if (list1->val > list2->val)
        {
            // cout<<"compared"<<endl;
            temp->next = list2;
            list2 = list1;
            list1 = temp->next;
            temp = nullptr;
        }
        else
        {
            temp = list1;
            list1 = list1->next;
            if (list1 == nullptr)
            {
                temp->next = list2;
                break;
            }
        }
    }
    return res;
}
ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *mid = getMid(head);

    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);

    return mergeList(left, right);
}

int main()
{
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    ListNode *res = sortList(head);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}

// https://leetcode.com/problems/sort-list/description/