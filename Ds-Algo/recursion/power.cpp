#include<iostream>
using namespace std;

int pow(int x, int n){
    if(n==0){
        return 1;
    }
    int ans=pow(x, n-1);
    return x*ans;
}
int main(){
    int x, n;
    cin>>x>>n;
    cout<<pow(x, n)<<endl;
}