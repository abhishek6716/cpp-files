#include<iostream>
#include<vector>
#include<queue>
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
};

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
    Print(root);
    cout<<endl;
    PrintLvlWise(root);
}
