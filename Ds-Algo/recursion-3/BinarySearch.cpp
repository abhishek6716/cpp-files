#include<iostream>
using namespace std;

int helper(int arr[], int st, int en, int x){
    if(st>en){
        return -1;
    }
    int mid=(st+en)/2;
    if(arr[mid]==x){
        return mid;
    }
    else if(arr[mid]>x){
        return helper(arr, st, mid-1, x);
    }
    else{
        return helper(arr, mid+1, en, x);
    }
}
int BinarySearch(int arr[], int size, int x){
    return helper(arr, 0, size-1, x);
}
int main(){
    int arr[100];
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int x; cin>>x;
    cout<<BinarySearch(arr, n, x);
}