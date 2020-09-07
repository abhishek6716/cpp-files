#include<iostream>
using namespace std;

//printing first x terms of AP 3N+2 which are not multiple of 4

int main(){
    int n, AP, cnt=0;
    cin>>n;
    for(int i=1; cnt<n; i++){
        AP=(3*i)+2;
        if(AP%4!=0){
            cout<<AP<<" ";                     
            cnt++;
        }
    }
}