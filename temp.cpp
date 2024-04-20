#include<bits/stdc++.h>
using namespace std;


struct ListNode{

    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){};
    ListNode(int x):val(x),next(nullptr){};
    ListNode(int x, ListNode*next):val(x),next(next){}
};

void insertNode(ListNode* head, int val){
    while(head->next!=nullptr) head=head->next;
    ListNode* ptr = new ListNode(val);
    head->next = ptr;
}

void printList(ListNode* head){
    while(head!=nullptr){
        cout<<head->val<<" ";
        head= head->next;
    }
}

void insertAfter(ListNode* head,int pos, int val){
    ListNode* ptr = head;
    pos--;
    while(pos--){
        if(ptr!=nullptr) ptr=ptr->next;
        else {
            cout<<"Invalid position"<<endl;
            return;
        }
    }
    if(ptr==nullptr){
        cout<<"Invalid position"<<endl;
        return;
    }
    ListNode* temp = new ListNode(val);
    temp->next = ptr->next;
    ptr->next = temp;
}
/*
ListNode* insertBefore(ListNode* head,int pos, int val){
    ListNode* ptr = head;
    if(pos==1){
        ListNode* temp = new ListNode(val);
        temp->next=head;
        return temp;
    }
    pos-=2;
    while(pos--){
        if(ptr!=nullptr) ptr=ptr->next;
        else {
            cout<<"Invalid position"<<endl;
            return head;
        }
    }
    if(ptr==nullptr){
        cout<<"Invalid position"<<endl;
        return head;
    }
    ListNode* temp = new ListNode(val);
    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}
*/

ListNode* reverseList(ListNode* head){
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* prev=nullptr;
    ListNode* curr=head;
    ListNode* next=head->next;
    while(next!=nullptr){
        curr->next = prev;
        prev= curr;
        curr = next;
        next= next->next;
    }
    curr->next = prev;
    return curr;
}
int main(){
    ListNode* head = new ListNode(1);
    insertNode(head,2);

    //insertAfter(head,4,4);
    //head= insertBefore(head,4,4);
    head = reverseList(head);
    printList(head);
}
