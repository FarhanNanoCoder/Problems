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
bool isPalindrome(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow->next = reverseList(slow->next);
    fast = head;
    slow=slow->next;
    while (slow != nullptr)
    {
        if (fast->val != slow->val)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(2);
    bool res = isPalindrome(head);
    // printList(temp);
    cout << res;
}

// problem_link: https://leetcode.com/problems/palindrome-linked-list/