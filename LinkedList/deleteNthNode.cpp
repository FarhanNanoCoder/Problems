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
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *l = head, *s = nullptr;
    while (n > 0 && l != nullptr)
    {
        l = l->next;
        n--;
    }
    while (l != nullptr)
    {
        if (s == nullptr)
        {
            s = head;
        }
        else
        {
            s = s->next;
        }

        l = l->next;
    }

    if(s==nullptr){
       head = head->next;
    }else{
        ListNode* temp = s->next->next;
        s->next=temp;
        temp= nullptr;
    }

    return head;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* temp = removeNthFromEnd(head, 4);
    printList(temp);
}