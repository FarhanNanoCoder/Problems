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

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return nullptr;
    else if (lists.size() == 1)
        return lists[0];
    else if (lists.size() == 2)
        return mergeTwoLists(lists[0], lists[1]);
    else
    {
        int mid = lists.size() / 2;
        vector<ListNode *> left(lists.begin(), lists.begin() + mid);
        vector<ListNode *> right(lists.begin() + mid, lists.end());
        return mergeTwoLists(mergeKLists(left), mergeKLists(right));
    }
}

int main(){
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(6);
    vector<ListNode *> lists;
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);
    ListNode *res = mergeKLists(lists);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/merge-k-sorted-lists/