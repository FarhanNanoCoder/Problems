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
ListNode *mergeNodes(ListNode *head)
{
    ListNode *res = nullptr, *tail = nullptr;
    int c = 0;
    while (head != nullptr)
    {
        c += head->val;
        if (head->val == 0)
        {
            if (c != 0)
            {
                ListNode *t = new ListNode(c);
                if (res == nullptr)
                {
                    res = t;
                    tail = t;
                }
                else
                {
                    tail->next = t;
                    tail = tail->next;
                }
            }
            c = 0;
        }

        head = head->next;
    }
    return res;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(0, new ListNode(2, new ListNode(3, new ListNode(0, new ListNode(4, new ListNode(5, new ListNode(0, new ListNode(6)))))))));
    ListNode *res = mergeNodes(head);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}

//https://leetcode.com/problems/merge-nodes-in-between-zeros/description/