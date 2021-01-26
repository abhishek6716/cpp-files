#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;


template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;

    //constructor
    TreeNode(T data){
        this->data=data;
    }

    //destructor
    ~TreeNode(){
        for(int i=0; i<children.size(); i++){
            delete children[i];
        }
    }
};

void replaceWithDepthValueHelper(TreeNode<int> *root, int depth){                   // replace with depth value
    root->data=depth;
    for(int i=0; i<root->children.size(); i++){
        replaceWithDepthValueHelper(root->children[i], depth+1);
    }
}
void replaceWithDepthValue(TreeNode<int> *root){                                    // replace with depth value
    if(root==NULL){
        return;
    }
    replaceWithDepthValueHelper(root, 0);
}

template<typename T>                                                                // secondlargest class
class secondLargestReturnType{
    public:
    TreeNode<T> *largest;
    TreeNode<T> *secondLargest;

    secondLargestReturnType(TreeNode<T> *first, TreeNode<T> *second){
        this->largest=first;
        this->secondLargest=second;
    }
};


secondLargestReturnType<int>* secondLargestNodeHelper(TreeNode<int> *root){                        // secondlargest helper
    if(root==NULL){
        secondLargestReturnType<int> *ans=new secondLargestReturnType<int>(NULL, NULL);
        return ans;
    }
    secondLargestReturnType<int> *ans=new secondLargestReturnType<int>(root, NULL);
    for(int i=0; i<root->children.size(); i++){
        secondLargestReturnType<int> *childAns=secondLargestNodeHelper(root->children[i]);
        if(childAns->largest->data > ans->largest->data){
            if(childAns->secondLargest==NULL){
                ans->secondLargest=ans->largest;
                ans->largest=childAns->largest;
            }
            else{
                if(childAns->secondLargest->data > ans->largest->data){
                    ans->secondLargest=childAns->secondLargest;
                    ans->largest=childAns->largest;
                }
                else{
                    ans->secondLargest=ans->largest;
                    ans->largest=childAns->largest;
                }
            }
        }
        else{
            if(ans->largest->data != childAns->largest->data && (ans->secondLargest==NULL || childAns->largest->data > ans->secondLargest->data)){
                ans->secondLargest=childAns->largest;
            }
        }
    }
    return ans;
}
TreeNode<int>* secondLargest(TreeNode<int> *root){                                  // find second largest
    return secondLargestNodeHelper(root)->secondLargest;
}



TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n){                       // next larger element
    if(root==NULL){
        return NULL;
    }
    TreeNode<int> *ans=NULL;
    if(root->data > n){
        ans=root;
    }
    for(int i=0; i<root->children.size(); i++){
        TreeNode<int> *temp=nextLargerElement(root->children[i], n);
        if(ans==NULL){
            ans=temp;
        }
        else{
            if(temp!=NULL && ans->data > temp->data){
                ans=temp;
            }
        }
    }
    return ans;
}

bool isIdenticle(TreeNode<int> *root1, TreeNode<int> *root2){                       // Two trees are identicle or not
    if(root1==NULL && root2==NULL){
        return true;
    }
    if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL)){
        return false;
    }
    if((root1->data!=root2->data) || (root1->children.size() != root2->children.size())){
        return false;
    } 
    int i=0;
    while(i<root1->children.size()){
        TreeNode<int> *child1=root1->children[i];
        TreeNode<int> *child2=root2->children[i];
        if(isIdenticle(child1, child2)){
            i++;
        }
        else{
            return false;
        }
    }
    return true;
}

template<typename T>                                                                // find max node pair class
class MaxNodePair{
    public:
    TreeNode<int> *node;
    int sum;
};
MaxNodePair<int>* maxSumNode_better_helper(TreeNode<int> *root){                    // find max node helper fxn
    if(root==NULL){ 
        MaxNodePair<int> *pair=new MaxNodePair<int>();
        pair->node=NULL;
        pair->sum=INT_MIN;
        return pair;
    }
    int sum=root->data;
    for(int i=0; i<root->children.size(); i++){
        sum=sum+root->children[i]->data;
    }
    MaxNodePair<int> *ans=new MaxNodePair<int>();
    ans->node=root;
    ans->sum=sum;
    for(int i=0; i<root->children.size(); i++){
        MaxNodePair<int> *childAns=maxSumNode_better_helper(root->children[i]);
        if(childAns->sum > ans->sum){
            ans=childAns;
        }
    }
    return ans;
}
TreeNode<int>* maxSumNode_better(TreeNode<int> *root){                              // find max sum node better complexity
    return maxSumNode_better_helper(root)->node;
}

TreeNode<int>* maxSumNode(TreeNode<int> *root){                                     // find max sum node
    if(root==NULL){
        return NULL;
    }
    TreeNode<int> *max=root;
    int rootSum=root->data;
    for(int i=0; i<root->children.size(); i++){
        rootSum=rootSum + root->children[i]->data;
    }
    for(int i=0; i<root->children.size(); i++){
        TreeNode<int> *temp=maxSumNode(root->children[i]);
        int childrenSum=temp->data;
        for(int i=0; i<temp->children.size(); i++){
            childrenSum=childrenSum + temp->children[i]->data;
        }
        if(childrenSum>rootSum){
            max=temp;
            rootSum=childrenSum;
        }
    }
    return max;
}

int countNodes(TreeNode<int> *root, int x){                                         // no of nodes greater then x
    if(root==NULL){
        return 0;
    }
    int cnt=0;
    if(root->data > x){
        cnt++;
    }
    for(int i=0; i<root->children.size(); i++){
        cnt=cnt+countNodes(root->children[i], x);
    }
    return cnt;
}

bool containsX(TreeNode<int> *root, int x){                                         // tree contains int or not
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    for(int i=0; i<root->children.size(); i++){
        bool ans=containsX(root->children[i], x);
        if(ans==true){
            return true;
        }
    }
    return false;
}

void deleteTree(TreeNode<int> *root){                                               // delete tree
    for(int i=0; i<root->children.size(); i++){
        deleteTree(root->children[i]);
    }    
    delete root;
}

void postOrderTraversal(TreeNode<int> *root){                                       // post order traversal
    if(root==NULL){
        return;
    }
    for(int i=0; i<root->children.size(); i++){
        preOrderTraversal(root->children[i]);
    }
    cout<<root->data<<" ";
}

void preOrderTraversal(TreeNode<int> *root){                                        // pre order traversal
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0; i<root->children.size(); i++){
        preOrderTraversal(root->children[i]);
    }
}

int noOfLeafNodes(TreeNode<int> *root){                                             // no of leaf nodes
    if(root==NULL){
        return 0;
    }
    if(root->children.size()==0){
        return 1;
    }
    int subAns=0;
    for(int i=0; i<root->children.size(); i++){
        subAns=subAns+noOfLeafNodes(root->children[i]);
    }
    return subAns;
}

void printAtLvlK(TreeNode<int> *root, int k){                                       // depth of node
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<endl;
    }
    for(int i=0; i<root->children.size(); i++){
        printAtLvlK(root->children[i], k-1);
    }
}

int height(TreeNode<int> *root){                                                    // height of tree
    if(root==NULL){
        return 0;
    }
    int ans=0;
    for(int i=0; i<root->children.size(); i++){
        int subans=height(root->children[i]);
        if(subans>ans){
            ans=subans;
        }
    }
    return ans+1;
}

TreeNode<int>* maxNode(TreeNode<int> *root){                                        // return max node
    if(root==NULL){
        return root;
    }
    TreeNode<int> *max=root;
    for(int i=0; i<root->children.size(); i++){
        TreeNode<int> *max1=maxNode(root->children[i]);
        if(max1->data > max->data){
            max=max1;
        }
    }
    return max;
}

int sumNodes(TreeNode<int> *root){                                                  // sum of nodes
    int sum=root->data;
    for(int i=0; i<root->children.size(); i++){
        sum=sum+sumNodes(root->children[i]);
    }
    return sum;
}

int numNodes(TreeNode<int> *root){                                                  // no of nodes
    if(root==NULL){
        return 0;
    }
    int ans=1;
    for(int i=0; i<root->children.size(); i++){
        ans=ans+numNodes(root->children[i]);
    }
    return ans;
}

TreeNode<int>* TakeInputLvlWise(){                                                  // take input lvl wise
    cout<<"enter root data"<<endl;
    int rootData; cin>>rootData;
    TreeNode<int> *root=new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingTreeNodes;
    pendingTreeNodes.push(root);

    while(pendingTreeNodes.size()!=0){
        TreeNode<int> *front=pendingTreeNodes.front();
        pendingTreeNodes.pop();
        cout<<"enter no childrens of "<<front->data<<endl;
        int n; cin>>n;
        for(int i=0; i<n; i++){
            int childData;
            cout<<"enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int> *child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingTreeNodes.push(child);
        }
    }
    return root;
}

void PrintLvlWise(TreeNode<int> *root){                                             // print lvl wise
    if(root==NULL){
        return;
    }
    queue<TreeNode<int>*> pendingTreeNodes;
    pendingTreeNodes.push(root);
    while(pendingTreeNodes.size()!=0){
        TreeNode<int> *front=pendingTreeNodes.front();
        pendingTreeNodes.pop();
        cout<<front->data<<":";
        for(int i=0; i<front->children.size(); i++){
            if(i==front->children.size()-1){
                cout<<front->children[i]->data;
            }
            else{
                cout<<front->children[i]->data<<",";
            }
            pendingTreeNodes.push(front->children[i]);
        }  
        cout<<endl;
    }
}

TreeNode<int>* TakeInput(){                                                         // take input recursive
    cout<<"enter root data"<<endl;
    int rootData; cin>>rootData;
    TreeNode<int> *root=new TreeNode<int>(rootData);

    cout<<"enter no childrens of "<<rootData<<endl;
    int n; cin>>n;

    for(int i=0; i<n; i++){
        TreeNode<int> *child=TakeInput();
        root->children.push_back(child);
    }
    return root;
}

void Print(TreeNode<int> *root){                                                    // print tree
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++){
        Print(root->children[i]);
    }
}

int main(){

    /*
    TreeNode<int> *root=new TreeNode<int>(100);
    TreeNode<int> *n1=new TreeNode<int>(200);
    TreeNode<int> *n2=new TreeNode<int>(300);
    root->children.push_back(n1);
    root->children.push_back(n2);
    */
    TreeNode<int> *root=TakeInputLvlWise();
    PrintLvlWise(root);
    // deleteTree(root);
}
