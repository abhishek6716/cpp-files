#include<iostream>
#include<vector>
#include<algorithm>
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

void insertDuplicate(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    BinaryTreeNode<int> *duplicate=new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *left=root->left;
    insertDuplicate(root->left);
    insertDuplicate(root->right);
    root->left=duplicate;
    duplicate->left=left;
}


void convertToArray(BinaryTreeNode<int> *root, vector<int> &output){
    if(root==NULL){
        return;
    }
    output.push_back(root->data);
    convertToArray(root->left, output);
    convertToArray(root->right, output);
}
void nodesSumToS(BinaryTreeNode<int> *root, int sum){
    vector<int> output;
    convertToArray(root, output);
    sort(output.begin(), output.end());

    int i=0, j=output.size()-1;
    while(i<j){
        if(output[i]+output[j]==sum){
            // if duplicate elements present
            int countI=1, countJ=1;
            // count no of times the first element
            int k=i+1;
            while(output[k]==output[i]){
                countI++;
                k++;
            }
            // count no of times the second element
            k=j-1;
            while(output[k]==output[j]){
                countJ++;
                k--;
            }
            // printing the pair count times
            int count=countI*countJ;
            while(count>0){
                cout<<output[i]<<" "<<output[j]<<endl;
                count--;
            }
            i=i+countI;
            j=j+countJ;
        }
        else if(output[i]+output[j]>sum){
            j--;
        }
        else{
            i++;
        }
    }
}


BinaryTreeNode<int>* lcaBinaryTreeHelper(BinaryTreeNode<int> *root, int x, int y){       // lca in binary tree helper
    if(root==NULL){
        return NULL;
    }
    if(root->data==x || root->data==y){
        return root;
    }
    BinaryTreeNode<int> *leftLCA=lcaBinaryTreeHelper(root->left, x, y);
    BinaryTreeNode<int> *rightLCA=lcaBinaryTreeHelper(root->right, x, y);
    if(leftLCA && rightLCA){
        return root;
    }
    if(leftLCA){
        return leftLCA;
    }
    if(rightLCA){
        return rightLCA;
    }
}
int lcaBinaryTree(BinaryTreeNode<int> *root, int x, int y){                              // lca in binary tree(m-1)
    BinaryTreeNode<int> *node=lcaBinaryTreeHelper(root, x, y);
    if(node!=NULL){
        return node->data;
    } else{
        return -1;
    }
}

int lcaBinaryTree2(BinaryTreeNode<int> *root, int x, int y){                             // lca in binary tree(m-2)
    if(root==NULL){
        return -1;
    } else if(root->data==x || root->data==y){
        return root->data;
    }
    if(root->left==NULL || root->right==NULL){
        return -1;
    }
    int a=lcaBinaryTree2(root->left, x, y);
    int b=lcaBinaryTree2(root->right, x, y);

    if(a==-1 && b!=-1){
        return b;
    } else if(a!=-1 && b==-1){
        return a;
    }
    if(a!=-1 && b!=-1){
        return root->data;
    }
}


BinaryTreeNode<int>* lcaInBSTHelper(BinaryTreeNode<int> *root, int x, int y){            // lca in BST helper
    if(root==NULL){
        return NULL;
    }
    if(root->data==x || root->data==y){
        return root;
    }
    if(root->data<x && root->data<y){
        return lcaInBSTHelper(root->right, x, y);
    } else if(root->data>x && root->data>y){
        return lcaInBSTHelper(root->left, x, y);
    } else{
        BinaryTreeNode<int> *lcaLeft=lcaInBSTHelper(root->left, x, y);
        BinaryTreeNode<int> *lcaRight=lcaInBSTHelper(root->right, x, y);
        if(lcaLeft && lcaRight){
            return root;
        } else if(lcaLeft){
            return lcaLeft;
        } else{
            return lcaRight;
        }
    }
}
int lcaInBST(BinaryTreeNode<int> *root, int x, int y){                                   // lca in BST(m-1)
    BinaryTreeNode<int> *node=lcaInBSTHelper(root, x, y);
    if(node!=NULL){
        return node->data;
    } else{
        return -1;
    }
}

int lcaInBST2(BinaryTreeNode<int> *root, int x, int y){                                  // lca in BST(m-2)
    if(root==NULL){
        return -1;
    }
    if(x > root->data && y > root->data){
        return lcaInBST2(root->right, x, y);
    }
    if(x < root->data && y < root->data){
        return lcaInBST2(root->left, x, y);
    }
    return root->data;
}
