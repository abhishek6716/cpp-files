#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<stack>
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

////// largest BST subtree/////////
int minimum(BinaryTreeNode<int> *root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
int maximum(BinaryTreeNode<int> *root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root){
       if(root==NULL){
           return true;
       }
    int leftmax=maximum(root->left);
    int rightmin=minimum(root->right);
    bool output=(root->data>leftmax)&&(root->data<=rightmin)&&isBST(root->left)&&isBST(root->right);
    return output;

}
int height(BinaryTreeNode<int> *root) {
    if(root==NULL){
        return 0;
    }
    int left_height=height(root->left);
    int right_height=height(root->right);
    if(left_height>right_height){
        return left_height+1;
    }else
    {
        return right_height+1;
    }

}

int largestBSTSubtree1(BinaryTreeNode<int> *root) {                                      // largest BST compexity O(n^2)
    if(isBST(root)){
        height(root);
    }else{
    return max(largestBSTSubtree1(root->left),largestBSTSubtree1(root->right));
    }
}

class BSTsubtreeReturn{
    public:
    int max;
    int min;
    int height;
    bool isBST;
};
BSTsubtreeReturn largestBSTsubtree2helper(BinaryTreeNode<int> *root){
    if(root==NULL){
        BSTsubtreeReturn ans;
        ans.max=INT_MIN;
        ans.min=INT_MAX;
        ans.height=0;
        ans.isBST=true;
        return ans;
    }
    BSTsubtreeReturn left=largestBSTsubtree2helper(root->left);
    BSTsubtreeReturn right=largestBSTsubtree2helper(root->right);
    if(!(right.isBST && right.min>root->data)){
        right.isBST=false;
    }
    if(!(left.isBST && left.max<root->data)){
        left.isBST=false;
    }
    BSTsubtreeReturn ans;
    if(!left.isBST || !right.isBST || root->data<left.max || root->data>right.min){
        if(left.height>right.height){
            left.isBST=false;
            return left;
        } else{
            right.isBST=false;
            return right;
        }
    }
    ans.isBST=true;
    ans.min=min(left.min, min(right.min, root->data));
    ans.max=max(left.max, max(right.max, root->data));
    ans.height=max(left.height, right.height)+1;
    return ans;
}
int largestBSTsubtree2(BinaryTreeNode<int> *root){                                       // largest BST complexity O(n)
    return largestBSTsubtree2helper(root).height;
}

int replaceWithLargerNodesSum(BinaryTreeNode<int> *root, int sum){                       // replace with larger nodes sum
    if(root==NULL){
        return sum;
    }
    sum=replaceWithLargerNodesSum(root->right, sum);
    sum=sum+root->data;
    root->data=sum;
    sum=replaceWithLargerNodesSum(root->left, sum);
    return sum;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root){
    int sum=0;
    replaceWithLargerNodesSum(root, sum);
}

void rootToLeafPathsSumToKHelper(BinaryTreeNode<int> *root, vector<int> path, int k){
    if(root==NULL){
        return;
    }
    k=k-root->data;
    path.push_back(root->data);

    if(root->left==NULL && root->right==NULL){
        if(k==0){
            for(int i=0; i<path.size(); i++){
                cout<<path[i]<<" ";
            }
            cout<<endl;
        }
        path.pop_back();
        return;
    }
    rootToLeafPathsSumToKHelper(root->left, path, k);
    rootToLeafPathsSumToKHelper(root->right, path, k);
    path.pop_back();
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k){
    vector<int> path;
    rootToLeafPathsSumToKHelper(root, path, k);
}

////////   print nodes at distance k ///////

void downwardsNodes(BinaryTreeNode<int> *root, int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    downwardsNodes(root->left, k-1);
    downwardsNodes(root->right, k-1);
}
int printKdistanceNodes(BinaryTreeNode<int> *root, int node, int k){                     // print nodes at distance k
    if(root==NULL){
        return -1;
    }
    if(root->data==node){
        downwardsNodes(root, k);
        return 0;
    }
    int dl=printKdistanceNodes(root->left, node, k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<endl;
        } else{
            downwardsNodes(root->right, k-(dl+1)-1);
            return dl+1;
        }
    }
    int dr=printKdistanceNodes(root->right, node, k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<endl;
        } else{
            downwardsNodes(root->left, k-(dr+1)-1);
            return dr=1;
        }
    }
    return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k){                       // print nodes at distance k
    printKdistanceNodes(root, node, k);
}

//////// pair sum in BST /////////
int countNodes(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    return countNodes(root->left)+countNodes(root->right)+1;
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s){
    if(root==NULL){
        return;
    }
    int totalcount=countNodes(root);
    int count=0;
    stack<BinaryTreeNode<int>*> inorder;
    stack<BinaryTreeNode<int>*> revInorder;
    BinaryTreeNode<int> *temp=root;
    while(temp!=NULL){
        inorder.push(temp);
        temp=temp->left;
    }
    temp=root;
    while(temp!=NULL){
        revInorder.push(temp);
        temp=temp->right;
    }

    while(count<totalcount-1){
        BinaryTreeNode<int> *top1=inorder.top();
        BinaryTreeNode<int> *top2=revInorder.top();
        if(top1->data+top2->data==s){
            cout<<top1->data<<" "<<top2->data<<endl;

            BinaryTreeNode<int> *top=top1;
            inorder.pop();
            count++;
            if(top->right!=NULL){
                top=top->right;
                while(top!=NULL){
                    inorder.push(top);
                    top=top->left;
                }
            }
            top=top2;
            revInorder.pop();
            count++;
            if(top->left!=NULL){
                top=top->left;
                while(top!=NULL){
                    revInorder.push(top);
                    top=top->right;
                }
            }
        }
        else if(top1->data+top2->data>s){
            BinaryTreeNode<int> *top=top2;
            revInorder.pop();
            count++;
            if(top->left!=NULL){
                top=top->left;
                while(top!=NULL){
                    revInorder.push(top);
                    top=top->right;
                }
            }
        }
        else{
            BinaryTreeNode<int> *top=top1;
            inorder.pop();
            count++;
            if(top->right!=NULL){
                top=top->right;
                while(top!=NULL){
                    inorder.push(top);
                    top=top->left;
                }
            }
        }
    }
}
