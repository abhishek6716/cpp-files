#include<iostream>
using namespace std;

int min_to_1_dy(int n){                                         //DP-method
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=0;
    for(int i=2; i<n+1; i++){
       int x=ans[i-1];
       int y=INT_MAX;
       int z=INT_MAX;
       if(i%2==0){
           y=ans[i/2];
       }
       if(i%3==0){
           z=ans[i/3];
       }
       ans[i]=1+min(x,min(y,z));
    }
    return ans[n];
}

int helper_mem(int n, int *ans){                                //Memoisation method
    if(n==1){
        return 0;
    }
    if(ans[n]!=-1){
        return ans[n];
    }

    int a=helper_mem(n-1, ans);
    int b=INT_MAX, c=INT_MAX;
    if(n%2==0){
        b=helper_mem(n/2, ans);
    }
    if(n%3==0){
        c=helper_mem(n/3, ans);
    }
    ans[n]=1+ min(a, min(b, c));
    return ans[n];
}
int min_to_1_mem(int n){
    int *ans=new int[n+1];
    for(int i=0; i<=n; i++){
        ans[i]=-1;
    }
    return helper_mem(n, ans);
}



int min_to_1(int n){                                            //Brute force method
    if(n<=1){
        return 0;
    }
    int a=min_to_1(n-1);
    int b=INT_MAX, c=INT_MAX;
    if(n%2==0){
        b=min_to_1(n/2);
    }
    if(n%3==0){
        c=min_to_1(n/3);
    }

    return 1+ min(a, min(b, c));
}


int main(){
    cout<<"enter a number ";
    int n; cin>>n;
    cout<<min_to_1(n)<<endl;
    cout<<min_to_1_mem(n)<<endl;
    cout<<min_to_1_dy(n)<<endl;
}