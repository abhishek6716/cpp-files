#include<iostream>
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

//// BST class ////
class BST{
    BinaryTreeNode<int> *root;
    public:
    BST(){
        root==NULL;
    }
    
    ~BST(){
        delete root;
    }

    private:
    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int> *node){                // delete data helper
        if(node==NULL){
            return NULL;
        }
        if(data < node->data){
            node->left=deleteData(data, node->left);
        } else if(data > node->data){
            node->right=deleteData(data, node->right);
        } else{
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            } else if(node->left==NULL){
                BinaryTreeNode<int> *temp=node->right;
                node->right=NULL;
                delete node;
                return temp;
            } else if(node->right==NULL){
                BinaryTreeNode<int> *temp=node->left;
                node->left=NULL;
                delete node;
                return temp;
            } else{
                BinaryTreeNode<int> *minNode=node->right;
                while(node->left!=NULL){
                    minNode=minNode->left;
                }
                int rightMin=minNode->data;
                node->data=rightMin;
                node->right=deleteData(rightMin, node->right);
                return node;
            }
        }
    }
    public:
    void deleteData(int data){                                                           // delete data
        root=deleteData(data, root);
    }

    private:
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int> *node){                    // insert data helper
        if(node==NULL){
            BinaryTreeNode<int> *newNode=new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data<node->data){
            node->left=insert(data, node->left);
        } else{
            node->right=insert(data, node->right);
        }
        return node;
    }
    public:
    void insert(int data){                                                               // insert data
        this->root=insert(data, this->root);
    }

    private:
    bool hasData(int data, BinaryTreeNode<int> *node){                                   // hasdata helper
        if(node==NULL){
            return false;
        }
        if(node->data==data){
            return true;
        } else if(data<node->data){
            return hasData(data, node->left);
        } else{
            return hasData(data, node->right);
        }
    }
    public:
    bool hasData(int data){                                                              // hasdata
        return hasData(data, root);
    }

    private:
    void PrintTreeHelper(BinaryTreeNode<int> *node){                                     // print BST helper
        if(node==NULL){
        return;
        }
        cout<<node->data<<":";
        if(node->left!=NULL){
        cout<<"L"<<node->left->data;
        }
        if(node->right!=NULL){
        cout<<"R"<<node->right->data;
        }
        cout<<endl;
        PrintTreeHelper(node->left);
        PrintTreeHelper(node->right);
    }
    public:
    void printTree(){                                                                    // print BST
        PrintTreeHelper(root);
    }
};