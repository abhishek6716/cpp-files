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

Node* ReverseLinkedList(Node* head){                                           // reverselinkedlist
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

bool IsPalindrome(Node* head){                                                 // check palindrome
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node* slow=head;
    Node* fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }

    Node* secondHead=slow->next;
    slow->next=NULL;
    secondHead=ReverseLinkedList(secondHead);
    
    //compare the two sublists
    Node* firstSubList=head;
    Node* secondSubList=secondHead;
    bool ans=true;

    while(secondSubList!=NULL){
        if(firstSubList->data != secondSubList->data){
            ans=false;
            break;
        }
        firstSubList=firstSubList->next;
        secondSubList=secondSubList->next;
    }

    //rejoins the two sublists
    firstSubList=head;
    secondSubList=ReverseLinkedList(secondHead);

    while(firstSubList->next != NULL){
        firstSubList=firstSubList->next;
    }
    firstSubList->next=secondSubList;
    return ans;
}

void PrintReverse(Node* head){                                                 // Print Reverse
    if(head==NULL){
        return;
    }
    PrintReverse(head->next);
    cout<<head->data<<" ";
}

Node* RemoveDuplicates(Node* head){                                            // remove duplicates
    if(head==NULL){                                                            // input:  1 1 2 2 3 3 4 5 5 6
        return head;                                                           // output: 1 2 3 4 5 6
    }
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
            Node* a=temp->next;
            temp->next=temp->next->next;
            delete a;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}

Node* appendLastNtoFirst(Node* head, int n){                                   // append last N to first
    if(n==0 || head==NULL){
        return head;
    }
    Node* fast=head;
    Node* slow=head;
    Node* initialHead;

    for(int i=0; i<n; i++){
        fast=fast->next;
    }

    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }

    Node* temp=slow->next;
    slow->next=NULL;
    fast->next=initialHead;
    head=temp;

    return head;
}

int FindIndex(Node *head, int n){                                              // find index
    Node *temp=head;
    int cnt=0;
    while(temp!=NULL){
        if(temp->data==n){
            return cnt;
        }
        temp=temp->next;
        cnt++;
    }
    return -1;
}

Node* DeleteNode(Node *head, int pos){                                         // delete node
    if(head==NULL){
        return head;
    }
    if(pos==0){
        return head->next;
    }
    Node *temp=head;
    int cnt=0;
    while(temp!=NULL && cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp==NULL || temp->next==NULL){
        return head;
    }
    Node *a=temp->next;
    temp->next=temp->next->next;
    delete a;
    return head;
}

Node* DeleteNode_rec(Node *head, int pos){                                     // delete node rec
    if(head==NULL){
        return head;
    }
    if(pos==0){
        Node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node *smallHead=DeleteNode_rec(head->next, pos-1);
    head->next=smallHead;
    return head;
}

Node* InsertNode(Node *head, int i, int data){                                 // insert node
    Node *newNode=new Node(data);
    int cnt=0; 
    Node *temp=head;
    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    while(temp!=NULL && cnt<i-1){
        temp=temp->next;
        cnt++;
    }
    if(temp!=NULL){
        newNode->next=temp->next;
        temp->next=newNode;
    }
    return head;
}

Node* InsertNode_rec(Node *head, int i, int data){                             // insertNode rec
    if(head==NULL){
        if(i==0){
            Node *newNode=new Node(data);
            return newNode;
        }
        else{
            return head;
        }
    }
    Node *newNode=new Node(data);
    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    head->next=InsertNode_rec(head->next, i-1, data);
    return head;
}

void ithElement(Node *head, int i){                                            // ith element
    int k=0;
    while(k<i){
        head=head->next;
        k++;
    }
    cout<<head->data<<endl;
}

int Length(Node *head){                                                        // length
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}

int Length_rec(Node *head){                                                    // length rec
    if(head==NULL){
        return 0;
    }
    else{
        return Length_rec(head->next)+1;
    }
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


Node* TakeInput(){                                                             // complexity o(n^2);
    int data;
    cin>>data;
    Node *head=NULL;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL){
            head=newNode;
        }
        else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
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
    Node *head=TakeInput_Better();
    //cout<<Length(head)<<endl;
    //ithElement(head, 0);
    Print(head);
    int n; cin>>n;
    cout<<FindIndex(head, n);
    /*
    int i, data;
    cin>>i>>data;
    head=InsertNode(head, i, data);
    Print(head);
    */
    /*
    // statically
    Node n1(100);
    Node *head=&n1;
    Node n2(200);
    Node n3(300);
    Node n4(400);
    Node n5(500);

    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    Print(head);

    // dynamically
    Node *b1=new Node(1);
    Node *b2=new Node(2);
    Node *b3=new Node(3);
    Node *b4=new Node(4);
    Node *b5=new Node(5);
    
    Node *head2=b1;
    b1->next=b2;
    b2->next=b3;
    b3->next=b4;
    b4->next=b5;
    Print(head2);
    */
}