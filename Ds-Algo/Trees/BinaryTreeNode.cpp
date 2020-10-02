#include<iostream>
#include<queue>
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

void PrintTreeLevelWise(BinaryTreeNode<int> *root){                                      // print tree lvl wise
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        if(front==NULL){
            cout<<endl;
            if(pendingNodes.size()!=0){
                pendingNodes.push(NULL);
            }
        }
        else{
            cout<<front->data<<":";
            cout<<"L:";
            if(front->left!=NULL){
                pendingNodes.push(front->left);
                cout<<front->left->data<<",";
            }
            else{
                cout<<"-1"<<",";
            }
            cout<<"R:";
            if(front->right!=NULL){
                pendingNodes.push(front->right);
                cout<<front->right->data<<endl;
            }
            else{
                cout<<"-1"<<endl;
            }
        }
    }
}

BinaryTreeNode<int>* TakeInputLevelWise(){                                               // take input level wise
    int rootData;
    cout<<"enter root data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!=-1){
            BinaryTreeNode<int> *child=new BinaryTreeNode<int>(leftChildData);
            front->left=child;
            pendingNodes.push(child);
        }
        cout<<"enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int> *child=new BinaryTreeNode<int>(rightChildData);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}

BinaryTreeNode<int>* TakeInput(){                                                        // take input
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild=TakeInput();
    BinaryTreeNode<int> *rightChild=TakeInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}

void PrintTree(BinaryTreeNode<int> *root){                                               // print tree
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    PrintTree(root->left);
    PrintTree(root->right);
}

int height(BinaryTreeNode<int> *root){                                                   // height of tree
    if(root==NULL){
        return 0;
    }
    return 1+height(root->left)+height(root->right);
}

bool isNodePresent(BinaryTreeNode<int> *root, int n){                                    // node present or not
    if(root==NULL){
        return false;
    }
    if(root->data==n){
        return true;
    }
    bool ans1=isNodePresent(root->left, n);
    bool ans2=isNodePresent(root->right, n);
    if(ans1 || ans2){
        return true;
    }
    return false;
}

int numNodes(BinaryTreeNode<int> *root){                                                 // no of nodes
    if(root==NULL){
        return 0;
    }
    return 1+numNodes(root->left)+numNodes(root->right);
}

void mirrorBinaryTree(BinaryTreeNode<int> *root){                                        // mirror binary tree
    if(root==NULL){
        return;
    }
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    BinaryTreeNode<int> *left2=root->left;
    root->left=root->right;
    root->right=left2;
}

void preorder(BinaryTreeNode<int> *root){                                                // preorder
    if(root==NULL){
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}

void postorder(BinaryTreeNode<int> *root){                                               // postorder
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(BinaryTreeNode<int> *root){                                                 // inorder
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
/* 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 */ 
int main(){
    /*
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1=new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2=new BinaryTreeNode<int>(3);
    root->left=node1;
    root->right=node2;
    */
    BinaryTreeNode<int> *root=TakeInputLevelWise();
    PrintTreeLevelWise(root);
    cout<<endl;
    cout<<numNodes(root)<<endl;
    cout<<isNodePresent(root, 0)<<endl;
    cout<<"height: "<<height(root)<<endl;
    mirrorBinaryTree(root);
    cout<<endl;
    delete root;
}