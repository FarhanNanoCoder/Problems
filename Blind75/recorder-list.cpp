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

void reorderList(ListNode *head)
{
    ListNode *second = head, *temp = head;
    // fast and slow pointer method to find the mid
    while (temp != nullptr && temp->next != nullptr)
    {
        second = second->next;
        temp = temp->next->next;
    }
    // separating fisrt & second half as a separated array
    temp = second;
    second = second->next;
    temp->next = nullptr;

    // reversing the second half
    if (second != nullptr && second->next != nullptr)
    {
        ListNode *next = nullptr;
        temp = second->next;
        second->next = nullptr;
        while (temp != nullptr)
        {
            next = temp->next;
            temp->next = second;
            second = temp;
            temp = next;
        }
    }

    // merging
    ListNode *temp2 = nullptr;
    ListNode *tempHead = head;
    while (second != nullptr)
    {
        temp = tempHead->next;
        temp2 = second->next;
        tempHead->next = second;
        tempHead->next->next = temp;
        second = temp2;
        tempHead = tempHead->next->next;
    }

    // return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);


    reorderList(head);
    printList(head);
}