#include<iostream>
#include<queue>
#include<stack>
#include<climits>
#include<vector>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root, int k){                      // search in BST
    if(root==NULL){
        return NULL;
    }
    if(root->data==k){
        return root;
    }
    if(k < root->data){
        return searchInBST(root->left, k);
    } else{
        return searchInBST(root->right, k);
    }
}

void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2){                     // print elements in given range
    if(root==NULL){
        return;
    }
    if(root->data >= k1 && root->data <= k2){
        elementsInRangeK1K2(root->left, k1, k2);
        cout<<root->data<<" ";
        elementsInRangeK1K2(root->right, k1, k2);
        return;
    }
    if(root->data<k1){
        elementsInRangeK1K2(root->right, k1, k2);
        return;
    }
    if(root->data>k2){
        elementsInRangeK1K2(root->left, k1, k2);
        return;
    }
}

void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)  
{  
    /* base case */
    if ( NULL == root )  
        return;  
      
    /* Since the desired o/p is sorted,  
        recurse for left subtree first  
        If root->data is greater than k1,  
        then only we can get o/p keys  
        in left subtree */
    if ( k1 < root->data )  
        elementsInRangeK1K2(root->left, k1, k2);  
      
    /* if root's data lies in range,  
    then prints root's data */
    if ( k1 <= root->data && k2 >= root->data )  
        cout<<root->data<<" ";  
      
    /* If root->data is smaller than k2, 
        then only we can get o/p keys  
        in right subtree */
    if ( k2 > root->data )  
        elementsInRangeK1K2(root->right, k1, k2);  
}  


bool checkBST(BinaryTreeNode<int> *root, int minima, int maxima){                        // topdown approach
    if(root==NULL){
        return true;
    }
    if(root->data < minima || root->data > maxima){
        return false;
    }
    bool leftSearch=checkBST(root->left, minima, root->data);
    bool rightSearch=checkBST(root->right, root->data, maxima);
    return leftSearch & rightSearch;
}
bool isBST1(BinaryTreeNode<int> *root){                                                  // is BST m-1
    return checkBST(root, INT_MIN, INT_MAX);                                            
}

int minimum(BinaryTreeNode<int> *root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
int maximum(BinaryTreeNode<int> *root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
bool isBST2(BinaryTreeNode<int> *root){                                                  // is BST m-2
    if(root==NULL){
        return true;
    }
    int leftMax=maximum(root->left);
    int rightMin=minimum(root->right);
    bool p=(root->data > leftMax) && (root->data < rightMin);
    bool q=isBST2(root->left);
    bool r=isBST2(root->right);
    return p && q && r;
}

class IsBSTReturn{
    public:
    bool isBST;
    int minimum;
    int maximum;
};
IsBSTReturn isBST3(BinaryTreeNode<int> *root){                                           // is BST m-3                                           
    if(root==NULL){
        IsBSTReturn output;
        output.isBST=true;
        output.minimum=INT_MAX;
        output.maximum=INT_MIN;
        return output;
    }
    IsBSTReturn leftOutput=isBST3(root->left);
    IsBSTReturn rightOutput=isBST3(root->right);
    int minimum=min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum=max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    bool isBSTFinal=(root->data > leftOutput.maximum) && (root->data < rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;
    IsBSTReturn output;
    output.minimum=minimum;
    output.maximum=maximum;
    output.isBST=isBSTFinal;
    return output;
}

BinaryTreeNode<int>* constructHelper(int *input, int si, int ei){                        // BST from sorted array
    if(si>ei){
        return NULL;
    }
    int mid=(si+ei)/2;
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(input[mid]);
    root->left=constructHelper(input, si, mid-1);
    root->right=constructHelper(input, mid+1, ei);
    return root;
}
BinaryTreeNode<int>* constructBST(int *input, int n){
    constructHelper(input, 0, n-1);
}

template<typename T>
class Node{
    public:
    T data;
    Node *next;

    Node(T data){
        this->data=data;
        this->next=NULL;
    }
};
class base{
    public:
    Node<int> *head;
    Node<int> *tail;
};

Node<int>* LLfromBST(BinaryTreeNode<int> *root){
    if(root==NULL){
        return NULL;
    }
    Node<int> *newNode=new Node<int>(root->data);
    Node<int> *head0=LLfromBST(root->left);
    Node<int> *head1=LLfromBST(root->right);

    newNode->next=head1;
    Node<int> *temp=head0;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    if(temp!=NULL){
        temp->next=newNode;
        return head0;
    }
    else{
        return newNode;
    }
}
base helper(BinaryTreeNode<int> *root){
    if(root==NULL){
        base b;
        b.head=NULL;
        b.tail=NULL;
        return b;
    }
    base head0=helper(root->left);
    base head1=helper(root->right);
    Node<int> *newNode=new Node<int>(root->data);
    if(head0.tail!=NULL){
        head0.tail->next=newNode;
        newNode->next=head1.head;
        base b;
        if(head0.head!=NULL){
            b.head=head0.head;
        } else{
            b.head=newNode;
        }
        if(head1.tail!=NULL){
            b.tail=head1.tail;
        } else{
            b.tail=newNode;
        }
        return b;
    }
}
Node<int>* LLfromBST(BinaryTreeNode<int> *root){                                         // // BST from sorted array
    base b=helper(root);
    return b.head;
}

vector<int>* getRootToNodePath(BinaryTreeNode<int> *root, int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        vector<int> *output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftOutput=getRootToNodePath(root->left, data);
    if(leftOutput!=NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    
    vector<int> *rightOutput=getRootToNodePath(root->right, data);
    if(rightOutput!=NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    } else
    {
        return NULL;
    }
    
}
