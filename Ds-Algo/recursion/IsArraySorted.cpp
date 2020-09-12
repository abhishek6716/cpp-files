#include<iostream>
using namespace std;

bool IsArraySorted2(int arr[], int n){
    if(n==0 || n==1){
        return true;
    }
    bool ans=IsArraySorted2(arr+1, n-1);
    if(!ans){
        return false;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else
    {
        return true;
    }
    
}

bool IsArraySorted(int arr[], int n){
    if(n==0 || n==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    bool ans=IsArraySorted(arr+1, n-1);
    return ans;
}