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

bool hasCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        if (fast == slow)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
     head->next->next->next->next->next = head->next;
    bool res = hasCycle(head);
    cout << res;
    // printList(res);
}

// problem_link: https://leetcode.com/problems/linked-list-cycle/