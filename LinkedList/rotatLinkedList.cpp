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
ListNode *rotateRight(ListNode *head, int k)
{
    if(head==nullptr) return head;
    ListNode *tail = head;
    int length = 0;
    while (tail->next != nullptr && ++length)
        tail = tail->next;
    ++length;
    tail->next = head;
    int diff = length - (k%length);
    while (diff)
    {
        // cout << "head" << head->val << " tail" << tail->val << endl;
        head = head->next;
        tail = tail->next;
        diff--;
    }
    tail->next = nullptr;
    return head;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode *temp = rotateRight(head, 3);
    printList(temp);
}

// PROBLEM_LINK: https://leetcode.com/problems/rotate-list/description/