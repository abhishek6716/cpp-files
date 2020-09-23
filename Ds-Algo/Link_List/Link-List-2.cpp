#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class Pair{
    public:
    Node *head;
    Node *tail;
};

Pair reverseLL_2(Node *head){
    if(head==NULL && head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair smallAns=reverseLL_2(head->next);
    smallAns.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head=smallAns.head;
    ans.tail=head;
    return ans;
}
Node* reverse_better(Node* head){                                              // reverse LL using pair class
    return reverseLL_2(head).head;
}

Node* reverseLL_rec1(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* smallNode=reverseLL_rec1(head->next);
    Node* temp=smallNode;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    head->next=NULL;
    return smallNode;
}

Node* reverse_LL_Rec3(Node* head){                                              // reverse LL recursively
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* smallNode=reverse_LL_Rec3(head->next);
    head->next->next=head;
    head->next=NULL;
    return smallNode;
}

Node* ReverseLinkedList(Node* head){                                           // reverse LL iteratively
    Node* curr=head;
    Node* prev=NULL;
    Node* fwd=NULL;

    while(curr!=NULL){
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
    }
    return prev;
}

Node* MidNode(Node* head){                                                     // mid node
    if(head==NULL){
        return head;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node* MergeSort(Node* head){                                                   // merge sort
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node* mid=MidNode(head);
    Node* half1=head;
    Node* half2=mid->next;
    mid->next=NULL;

    half1=MergeSort(half1);
    half2=MergeSort(half2);

    Node* finalHead=MergeTwoSorted_LL(half1, half2);
    return finalHead;
}

Node* MergeTwoSorted_LL(Node* head1, Node* head2){                             // merge two sorted LL
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    Node* newHead=NULL;
    Node* newTail=NULL;
    if(head1->data < head2->data){
        newHead=head1;
        newTail=head1;
        head1=head1->next;
    }
    else{
        newHead=head2;
        newTail=head2;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            newTail->next=head1;
            newTail=newTail->next;
            head1=head1->next;
        }
        else{
            newTail->next=head2;
            newTail=newTail->next;
            head2=head2->next;
        }
    }
    if(head1!=NULL){
        newTail->next=head1;
    }
    if(head2!=NULL){
        newTail->next=head2;
    }
    return newHead;
}

Node* MidPnt(Node* head){                                                      // mid node of Link List
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

int main(){

}