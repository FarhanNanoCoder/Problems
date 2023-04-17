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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
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
int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(4);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(10);
    // head->next->next->next->next = new ListNode(5);
    ListNode *head2 = new ListNode(1);
    // head2->next = new ListNode(7);
    // head2->next->next = new ListNode(9);
    // head2->next->next->next = new ListNode(4);
    // head2->next->next->next->next = new ListNode(5);

    head = mergeTwoLists(head, head2);
    printList(head);
}