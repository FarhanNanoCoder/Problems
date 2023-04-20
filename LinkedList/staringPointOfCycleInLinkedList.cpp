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

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    if (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    else
    {
        fast = nullptr;
    }
    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
    {
        if (fast == slow)
        {
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return nullptr;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next;
    ListNode *res = detectCycle(head);
    cout << res->val;
    // printList(res);
}

// problem_link: https://leetcode.com/problems/linked-list-cycle-ii/