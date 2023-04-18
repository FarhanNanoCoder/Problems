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
void deleteNode(ListNode *node)
{
    node->val= node->next->val;
    node->next = node->next->next;

}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    deleteNode(head->next->next);
    // ListNode* temp = removeNthFromEnd(head, 4);
    printList(head);
}

// problem_link: https://leetcode.com/problems/delete-node-in-a-linked-list/description/