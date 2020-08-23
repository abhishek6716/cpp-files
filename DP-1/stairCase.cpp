#include<iostream>
using namespace std;

int stairCase_3(int n){                                         //By DP
    int *ans=new int[n+1]; 
    ans[0] = 1; 
    ans[1] = 1; 
    ans[2] = 2; 
    for (int i = 3; i <= n; i++) 
        ans[i]=ans[i - 1]+ans[i - 2]+ans[i - 3]; 
  
    return ans[n];
}

int helper(int n, int *ans){                                    //Memoisation method
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int a=helper(n-1, ans);
    int b=helper(n-2, ans);
    int c=helper(n-3, ans);
    ans[n]=a+b+c;
    return ans[n];
}
int stairCase_2(int n){
    int *ans=new int[n+1];
    for(int i=0; i<n+1; i++){
        ans[i]=-1;
    }
    return helper(n, ans);
}

int stairCase_1(int n){                                         //Brute force method
    if(n<0){                                                    //Base Case 1
        return 0;
    }
    if(n==0){                                                   //Base Case 2
        return 1;
    }
    int a=stairCase_1(n-1);                 
    int b=stairCase_1(n-2);    
    int c=stairCase_1(n-3);    
    return a+b+c;
}

int main(){
    cout<<"enter no of steps ";
    int n;
    cin>>n;
    cout<<stairCase_1(n)<<endl;
    cout<<stairCase_2(n)<<endl;
    cout<<stairCase_3(n)<<endl;
}