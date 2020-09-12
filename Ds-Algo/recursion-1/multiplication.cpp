#include<iostream>
using namespace std;

int multiply(int m, int n){
    if(m==0 || n==0){
        return 0;
    }
    int ans=multiply(m-1, n);
    return ans+n;
}
int main(){
    int m, n;
    cin>>m>>n;
    cout<<multiply(m,n)<<endl;
}