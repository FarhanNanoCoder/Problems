
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

//Native solution
ListNode *reverseKGroup(ListNode *head, int k)
{
    vector<ListNode *> list;
    while (head != nullptr)
    {
        list.push_back(head);
        head = head->next;
    }
    int groups = list.size() / k;
    for (int i = 0; i < groups; i++)
    {
        int start = i * k;
        int last = start + k - 1;
        while (start < last)
        {
            swap(list[start++], list[last--]);
        }
    }
    for (int i = 0; i < list.size() - 1; i++)
    {
        list[i]->next = list[i + 1];
    }
    list[list.size() - 1]->next = nullptr;
    return list[0];
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    ListNode *temp = reverseKGroup(head, 2);
    printList(temp);
}

// problem_link: https://leetcode.com/problems/reverse-nodes-in-k-group/