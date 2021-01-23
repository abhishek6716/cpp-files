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

Node* kReverse(Node *head, int k){
    if(k==0 || k==1){
        return head;
    }
    Node *current=head;
    Node *fwd=NULL;
    Node *prev=NULL;
    int cnt=0;
    while(cnt<k && current!=NULL){
        fwd=current->next;
        current->next=prev;
        prev=current;
        current=fwd;
        cnt++;
    }
    if(fwd!=NULL){
        head->next=kReverse(fwd, k);
    }
    return prev;
}

Node* swapNodes(Node* head, int i, int j){                                     // swap nodes of LL
    if(i==j){
        return head;
    }
    Node *currentNode=head, *prev=NULL;
    Node *firstNode=NULL, *firstNodePrev=NULL, *secondNode=NULL, *secondNodePrev=NULL;
    int pos=0;
    while(currentNode!=NULL){
        if(pos==i){
            firstNode=currentNode;
            firstNodePrev=prev;
        }
        else if(pos==j){
            secondNode=currentNode;
            secondNodePrev=prev;
        }
        prev=currentNode;
        currentNode=currentNode->next;
        pos++;
    }
    if(firstNodePrev!=NULL){
        firstNodePrev->next=secondNode;
    }
    else{
        head=secondNode;
    }
    if(secondNodePrev!=NULL){
        secondNodePrev->next=firstNode;
    }
    else{
        head=firstNode;
    }
    Node* currentFirstNode=secondNode->next;
    secondNode->next=firstNode->next;
    firstNode->next=currentFirstNode;
    return head;
}

Node* SkipM_DeleteN(Node* head, int m, int n){
    if(head==NULL || m==0){
        return head;
    }
    if(n==0){
        return head;
    }
    Node* currNode=head;
    Node* temp=NULL;
    while(currNode!=NULL){
        int take=0;
        int skip=0;

        while(currNode!=NULL && take<m){
            if(temp==NULL){
                temp=currNode;
            }
            else{
                temp->next=currNode;
                temp=currNode;
            }
            currNode=currNode->next;
            take++;
        }
        while(currNode!=NULL && skip<n){
            Node* newNode=currNode;
            delete currNode;
            currNode=newNode->next;
            skip++;
        }
    }
    if(temp!=NULL){
        temp->next=NULL;
    }
    return head;
}

Node* EvenAfterOdd(Node* head){                                                // even after odd
    if(head==NULL){
        return head;
    }
    Node* oddHead=NULL;
    Node* oddTail=NULL;
    Node* evenHead=NULL;
    Node* evenTail=NULL;

    while(head!=NULL){
        if(head->data%2==0){
            if(evenHead==NULL){
                evenHead=head;
                evenTail=head;
            }
            else{
                evenTail->next=head;
                evenTail=evenTail->next;
            }       
        }
        else{
            if(oddHead==NULL){
                oddHead=head;
                oddTail=head;
            }
            else{
                oddTail->next=head;
                oddTail=oddTail->next;
            }
        }
        head=head->next;
    }
    if(evenTail!=NULL){
        evenTail->next=NULL;
    }
    if(oddTail!=NULL){
        oddTail->next=NULL;
    }

    if(oddHead==NULL){
        return evenHead;
    }
    else{
        oddTail->next=evenHead;
    }
    
    return oddHead;
}

int FindNode_Rec(Node* head, int n){                                           // find node
    if(head==NULL){
        return -1;
    }
    if(head->data==n){
        return 0;
    }
    int smallAns=FindNode_Rec(head->next, n);
    return smallAns+1;
}

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

Node* TakeInput_Better(){                                                      // better complexity
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;                                                      // or tail=tail->next;
        }
        cin>>data;
    }
    return head;
}

void Print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head=TakeInput_Better();
}