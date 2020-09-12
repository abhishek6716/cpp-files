// 3245
// 4

#include<iostream>
using namespace std;

int digits(int n){
    if(n<=9 && n>=1){
        return 1;
    }
    int ans=digits(n/10);
    return ans+1;
}
int main(){
    int n; cin>>n;
    cout<<digits(n)<<endl;
}