#include<iostream>
#include<cmath>
using namespace std;

int balancedBTs3(int n){                                        //By DP
    int *ans=new int[n+1];
    ans[0]=1;
    ans[1]=1;
    for(int i=2; i<n+1; i++){
        ans[i]=(ans[i-1]*ans[i-1])+(2*ans[i-1]*ans[i-2]);
    }
    return ans[n];
}

int helper(int n, int *ans){                                    //Memoisation method
    if(n<=1){
        return 1;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int mod=(int)(pow(10,9))+7;

    int x=helper(n-1, ans);
    int y=helper(n-2, ans);

    int temp1=(int)(((long)(x)*x)%mod);
    int temp2=(int)((2*(long)(x)*y)%mod);
    ans[n]=(temp1+temp2)%mod;
    return ans[n];
}
int balancedBTs2(int n){
    int *ans=new int[n+1];
    for(int i=0; i<n+1; i++){
        ans[i]=-1;
    }
    return helper(n, ans);
}

int balancedBTs1(int n){                                        //Brute force method
    if(n<=1){
        return 1;
    }
    
    int mod=(int)(pow(10,9))+7;

    int x=balancedBTs1(n-1);
    int y=balancedBTs1(n-2);
    /*
    return (x*x)+(x*y)+(y*x);
    */
     int temp1=(int)(((long)(x)*x)%mod);
     int temp2=(int)((2*(long)(x)*y)%mod);
     int ans=(temp1+temp2)%mod;
     return ans;
}
int main(){
    cout<<"enter the height of BT ";
    int n; cin>>n;
    cout<<balancedBTs1(n)<<endl;
    cout<<balancedBTs2(n)<<endl;
    cout<<balancedBTs3(n)<<endl;
}