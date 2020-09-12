#include<iostream>
using namespace std;

int sumOfDigits(int n){
    if(n==0){
        return 0;
    }
    int a=n%10;
    int ans=sumOfDigits(n/10);
    return ans+a;
}
int main(){
    int n; cin>>n;
    cout<<sumOfDigits(n)<<endl;
}