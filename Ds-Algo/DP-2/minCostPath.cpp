#include<iostream>
using namespace std;

//By DP method
int minCostPath_dp(int **input, int m, int n){
    int **output=new int*[m];
    for(int i=0; i<m; i++){
        output[i]=new int[n];
    }

    //fill the last cell ie. destination
    output[m-1][n-1]=input[m-1][n-1];

    //fill last row (right to left)
    for(int j=n-2; j>=0; j--){
        output[m-1][j]=output[m-1][j+1]+input[m-1][j];
    }

    //fill last column (bottom to top)
    for(int i=m-2; i>=0; i--){
        output[i][n-1]=output[i+1][n-1]+input[i][n-1];
    }

    //fill remaining cells
    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            output[i][j]=min(output[i][j+1], min(output[i+1][j], output[i+1][j+1]))+input[i][j];
        }
    }

    return output[0][0];
}



//By memoisation method
int minCostPath_Memo(int **input, int m, int n, int i, int j, int **output){
     //Base cases
    if(i==m-1 && j==n-1){
        return input[i][j];
    }
    if(i>=m || j>=n){
        return INT_MAX;
    }
    //check if answer is already exists or not
    if(output[i][j]!=-1){
        return output[i][j];
    }
    //Recursive calls
    int x=minCostPath_Memo(input, m, n, i, j+1, output);
    int y=minCostPath_Memo(input, m, n, i+1, j+1, output);
    int z=minCostPath_Memo(input, m, n, i+1, j, output);

    //small calculation
    int a=min(min(x,y),z)+input[i][j];
    //save answer
    output[i][j]=a;
    return a;
}
int minCostPath_Memo(int **input, int m, int n, int i, int j){
    int **output=new int*[m];
    for(int i=0; i<m; i++){
        output[i]=new int[n];
        for(int j=0; j<n; j++){
            output[i][j]=-1;
        }
    }
    return minCostPath_Memo(input, m, n, i, j, output);
}



//Brute force method
int minCostPath(int **input, int m, int n, int i, int j){       
    //Base cases
    if(i==m-1 && j==n-1){
        return input[i][j];
    }
    if(i>=m || j>=n){
        return INT_MAX;
    }
    //Recursive calls
    int x=minCostPath(input, m, n, i, j+1);
    int y=minCostPath(input, m, n, i+1, j+1);
    int z=minCostPath(input, m, n, i+1, j);

    //small calculation
    int ans=min(min(x,y),z)+input[i][j];
    return ans;
}
int minCostPath(int **input, int m, int n){
    return minCostPath(input, m, n, 0, 0);
}

int main(){
    cout<<"enter no of rows & columns ";
    int m, n;
    cin>>m>>n;
    int **input=new int*[m];
    for(int i=0; i<m; i++){
        input[i]=new int[n];
        for(int j=0; j<n; j++){
            cin>>input[i][j];
        }
    }
    cout<<minCostPath(input, m, n)<<endl;
    cout<<minCostPath_Memo(input, m, n, 0, 0)<<endl;
    cout<<minCostPath_dp(input, m, n);
}