#include<iostream>
using namespace std;

int arraySum(int arr[], int n){
    if(n==1){
        return arr[0];
    }
    int ans=arraySum(arr+1, n-1);
    return arr[0]+ans;
}
int main(){
    int n; cin>>n;
    int arr[100];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"sum : "<<arraySum(arr, n);
}