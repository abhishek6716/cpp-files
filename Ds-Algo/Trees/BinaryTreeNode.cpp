#include<iostream>
#include<queue>
#include<stack>
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
    return max(height(root->left), height(root->right))+1;
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
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(BinaryTreeNode<int> *root){                                               // postorder
    if(root==NULL){
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}

void inorder(BinaryTreeNode<int> *root){                                                 // inorder
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

BinaryTreeNode<int>* BuildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE){
    if(inS>inE){
        return NULL;
    }
    int rootData=pre[preS];
    int rootIndex=-1;
    for(int i=inS; i<inE; i++){
        if(in[i]==rootData){
            rootIndex=i;
            break;
        }
    }
    int lInS=inS;
    int lInE=rootIndex-1;
    int lPreS=preS+1;
    int lPreE=lInE-lInS+lPreS;
    int rPreS=lPreE+1;
    int rPreE=preE;
    int rInS=rootIndex+1;
    int rInE=inE;
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    root->left=BuildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right=BuildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}
BinaryTreeNode<int>* BuildTree(int* in, int* pre, int size){                                       // built tree from inorder preorder 
    return BuildTreeHelper(in, pre, 0, size-1, 0, size-1);
}

BinaryTreeNode<int>* helper(int *postorder, int postStart, int postEnd, int *inorder, int inStart, int inEnd){
    if(postStart>postEnd || inStart>inEnd){
        return NULL;
    }
    int rootData=postorder[postEnd];
    int rootIndex=-1;
    for(int i=inStart; i<inEnd; i++){
        if(inorder[i]==rootData){
            rootIndex=i;
            break;
        }
    }
    int LpostStart=postStart;
    int RpostEnd=postEnd-1;
    int LinStart=inStart;
    int LinEnd=rootIndex-1;
    int RinStart=rootIndex+1;
    int RinEnd=inEnd;
    int LpostEnd=LinEnd-LinStart+LpostStart;
    int RpostStart=LpostEnd+1;
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    root->left=helper(postorder, LpostStart, LpostEnd, inorder, LinStart, LinEnd);
    root->right=helper(postorder, RpostStart, RpostEnd, inorder, RinStart, RinEnd);
    return root;
}
BinaryTreeNode<int>* getTreefromPostandInOrder(int *postorder, int postLength, int *inorder, int inLength){          //built tree from inorder and postorder
    int postStart=0;
    int postEnd=postLength-1;
    int inStart=0;
    int inEnd=inLength-1;
    return helper(postorder, postStart, postEnd, inorder, inStart, inEnd);
}

int height(BinaryTreeNode<int> *root){                                                   // height of tree
    if(root==NULL){                                                                     
        return 0;
    }
    return 1+max(height(root->left), height(root->right));
}
int diameter(BinaryTreeNode<int> *root){                                                 // diameter of tree
    if(root==NULL){                                                                      // complexity O(n*heightOfTree)
        return 0;
    }
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1, max(option2, option3));
}

pair<int, int>  heightDiameter(BinaryTreeNode<int> *root){                               // diameter and height of tree
    if(root==NULL){                                                                      // better complexity of O(n)
        pair<int, int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int, int> leftAns=heightDiameter(root->left);
    pair<int, int> rightAns=heightDiameter(root->right);
    int ld=leftAns.second;
    int lh=leftAns.first;
    int rd=rightAns.second;
    int rh=rightAns.first;

    int height=1+max(lh, rh);
    int diameter=max(lh+rh, max(ld, rd));
    pair<int, int> p;
    p.first=height;
    p.second=diameter;
    return p;
}

pair<int, int> minMax(BinaryTreeNode<int> *root){                                        // min max data of tree
    if(root==NULL){
        pair<int, int> p;
        p.first=INT_MAX;
        p.second=INT_MIN;
        return p;
    }
    pair<int, int> leftAns=minMax(root->left);
    pair<int, int> rightAns=minMax(root->right);
    int lmin=leftAns.first;
    int lmax=leftAns.second;
    int rmin=rightAns.first;
    int rmax=rightAns.second;

    pair<int, int> p;
    p.first=min(min(lmin, rmin), root->data);
    p.second=max(max(lmax, rmax), root->data);
    return p;
}

int SumOfAllNodes(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    int subAns1=SumOfAllNodes(root->left);
    int subAns2=SumOfAllNodes(root->right);
    return subAns1+subAns2+root->data;
}

int height(BinaryTreeNode<int> *root){                                                   // height of tree
    if(root==NULL){                                                                     
        return 0;
    }
    return 1+max(height(root->left), height(root->right));
}
bool isBalanced(BinaryTreeNode<int> *root){                                              // isBalanced
    if(root==NULL){                                                                      // not good complexity
        return true;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    if(h1-h2>1 || h1-h2<-1){
        return false;
    }
    bool subAns1=isBalanced(root->left);
    bool subAns2=isBalanced(root->right);
    if(subAns1 && subAns2){
        return true;
    }
    return false;
}

class BalancedReturnType{
    public:
    int height;
    bool balanced;
};
BalancedReturnType* isBalancedHelper(BinaryTreeNode<int> *root){
    if(root==NULL){
        BalancedReturnType *ans=new BalancedReturnType();
        ans->height=0;
        ans->balanced=true;
        return ans;
    }
    BalancedReturnType *ans1=isBalancedHelper(root->left);
    BalancedReturnType *ans2=isBalancedHelper(root->right);
    bool flag;
    if(!(ans1->balanced) || !(ans2->balanced) || abs(ans1->height-ans2->height) > 1){
        flag=false;
    }
    else{
        flag=true;
    }
    BalancedReturnType *output=new BalancedReturnType();
    output->height=max(ans1->height, ans2->height)+1;
    output->balanced=flag;
    return output;
}
bool isBalanced(BinaryTreeNode<int> *root){                                              // better complexity
    if(root==NULL){
        return true;
    }
    return isBalancedHelper(root)->balanced;
}

void PrintLevelWise(BinaryTreeNode<int> *root){                                          // print level wise
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
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
            cout<<front->data<<" ";
            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL){
                pendingNodes.push(front->right);
            }
        }
    }
}

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root){                         // remove leaf nodes
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        delete root;
        return NULL;
    }
    root->left=removeLeafNodes(root->left);
    root->right=removeLeafNodes(root->right);
    return root;
}

void zigzagOrder(BinaryTreeNode<int> *root){                                             // print tree in zigzag order
    if(root==NULL){
        return;
    }
    stack<BinaryTreeNode<int>*> currentlevel;
    stack<BinaryTreeNode<int>*> nextlevel;
    currentlevel.push(root);
    bool leftToright=true;
    while(currentlevel.size()!=0){
        BinaryTreeNode<int> *temp=currentlevel.top();
        currentlevel.pop();
        if(temp!=NULL){
            cout<<temp->data<<" ";
            if(leftToright==true){
                if(temp->left!=NULL){
                    nextlevel.push(temp->left);
                }
                if(temp->right!=NULL){
                    nextlevel.push(temp->right);
                }
            }
            else{
                if(temp->right!=NULL){
                    nextlevel.push(temp->right);
                }
                if(temp->left!=NULL){
                    nextlevel.push(temp->left);
                }
            }
        }
        if(currentlevel.size()==0){
            cout<<endl;
            leftToright=false;
            swap(currentlevel, nextlevel);
        }
    }
}

void NodesWithoutSibling(BinaryTreeNode<int> *root){                                     // print nodes withot siblings
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    if(root->left!=NULL && root->right==NULL){
        cout<<root->left->data<<endl;
    }
    if(root->left==NULL && root->right!=NULL){
        cout<<root->right->data<<endl;
    }

    NodesWithoutSibling(root->left);
    NodesWithoutSibling(root->right);
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
vector<Node<int>*> createLLForEachLvl(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    int currLvlRem=1;
    int nextLvlCnt=0;
    vector<Node<int>*> output;
    Node<int>* currLvlHead=NULL;
    Node<int>* currLvlTail=NULL;
    while(!q.empty()){
        BinaryTreeNode<int>* front=q.front();
        q.pop();
        Node<int>* newNode=new Node<int>(front->data);
        if(currLvlHead==NULL){
            currLvlHead=newNode;
            currLvlTail=newNode;
        }
        else{
            currLvlTail->next=newNode;
            currLvlTail=newNode;
        }
        if(front->left!=NULL){
            q.push(front->left);
            nextLvlCnt++;
        }
        if(front->right!=NULL){
            q.push(front->right);
            nextLvlCnt++;
        }
        currLvlRem--;
        if(currLvlRem==0){
            output.push_back(currLvlHead);
            currLvlHead=NULL;
            currLvlTail=NULL;
            currLvlRem=nextLvlCnt;
            nextLvlCnt=0;
        }
    }
    return output;
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
    pair<int, int> p=heightDiameter(root);
    cout<<"height: "<<p.first<<endl;
    cout<<"diameter: "<<p.second<<endl;
    /*
    cout<<numNodes(root)<<endl;
    cout<<isNodePresent(root, 0)<<endl;
    cout<<"height: "<<height(root)<<endl;
    mirrorBinaryTree(root);
    cout<<endl;
    */
    delete root;
}