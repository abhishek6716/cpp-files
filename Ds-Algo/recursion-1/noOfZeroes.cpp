#include<iostream>
using namespace std;

int noOfZeroes(int n){
    if(n>=1 && n<=9){
        return 0;
    }
    int ans=noOfZeroes(n/10);
    if(n%10==0){
        return ans+1;
    }else{
        return ans;
    } 
}
int main(){
    int n; cin>>n;
    cout<<noOfZeroes(n)<<endl;
}