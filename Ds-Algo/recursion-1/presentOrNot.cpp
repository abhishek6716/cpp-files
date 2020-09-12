#include<iostream>
using namespace std;

bool IsPresent(int arr[], int n, int x){
    if(n==1){
        if(arr[0]==x){
            return true;
        } else{
            return false;
        }
    }
    bool ans=IsPresent(arr+1, n-1, x);
    if(ans){
        return true;
    }
    if(ans!=true){
        if(arr[0]==x){
            return true;
        } else{
            return false;
        }
    }
}
int main(){
    int n; cin>>n;
    int x; cin>>x;
    int arr[100];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"ans: "<<IsPresent(arr, n, x);
}