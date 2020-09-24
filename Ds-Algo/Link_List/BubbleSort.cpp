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

int length(Node *head){
    if(head==NULL){
        return 0;
    }
    Node *temp=head;
    int size=length(temp->next)+1;
    return size;
}

Node* BubbleSort(Node *head){
    for(int i=0; i<length(head); i++){
        Node *prev=NULL, *curr=head;
        while(curr->next!=NULL){
            if(curr->data > curr->next->data){
                if(prev!=NULL){
                    Node *temp=curr->next->next;
                    curr->next->next=curr;
                    prev->next=curr->next;
                    curr->next=temp;
                    prev=prev->next;
                }
                else{
                    head=curr->next;
                    curr->next=head->next;
                    head->next=curr;
                    prev=head;
                }
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
    }
    return head;
}