#include<iostream>
using namespace std;

int fibo_1(int n){                                           //Brute force method        
    if(n<=1){
        return n;
    }
    int a=fibo_1(n-1);
    int b=fibo_1(n-2);
    return a+b;
}


int fibo_2_helper(int n, int *ans){
    if(n<=1){
        return n;
    }

    //check if output is already exist
    if(ans[n]!=-1){
        return ans[n];
    }

    //recursive calls
    int a=fibo_2_helper(n-1, ans);
    int b=fibo_2_helper(n-2, ans);

    //saving output for future use
    ans[n]=a+b;

    //return final output
    return ans[n];
}
int fibo_2(int n){                                           //Memoisation method(recursive)
    int *ans=new int[n+1];
    for(int i=0; i<n+1; i++){
        ans[i]=-1;
    }
    return fibo_2_helper(n, ans);
}

int fibo_3(int n){                                           //Dynamic method(Iterative)
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=1;
    for(int i=2; i<n+1; i++){
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
}


int main(){
    int n;
    cin>>n;
    cout<<fibo_1(n)<<endl;
    cout<<fibo_2(n)<<endl;
    cout<<fibo_3(n)<<endl;
}