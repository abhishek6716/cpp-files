#include<iostream>
using namespace std;

// using XOR(^) gate
// 1^0=1
// 0^1=1
// 0^0=0
// 1^1=0

// time complexity   o(n)
// space complexity  o(1) 

int FindUnique(int arr[], int size){
    int ans=arr[0];
    for(int i=1; i<size; i++){
        ans=ans^arr[i];
    }
    return ans;
}
int main(){
    int arr[1000];
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<FindUnique(arr, n);
}