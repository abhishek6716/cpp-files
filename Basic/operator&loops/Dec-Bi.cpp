#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int bin=0, i=0, rem;
    while(n!=0){
        rem=n%2;
        bin=bin+rem*i;
        i=i*10;
        n=n/2;
    }
    cout<<bin;
}