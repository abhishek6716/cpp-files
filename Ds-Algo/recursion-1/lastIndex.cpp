#include<iostream>
using namespace std;
// forward
int lastIndex2(int arr[], int n, int x){
    if(n==0){
        return -1;
    }
    int ans=lastIndex2(arr+1, n-1, x);
    if(ans!=-1){
        return ans+1;
    } else{
        if(arr[0]!=x){
            return -1;
        } else{
            return 0;
        }
    }
}
// backward
int lastIndex(int arr[], int n , int x){
    if(n==0){
        return -1;
    }
    if(arr[n-1]==x){
        return n-1;
    }
    int ans=lastIndex(arr, n-1, x);
    if(ans==-1){
        return-1;
    } else{
        return ans;
    } 
}
int main(){
    int arr[100];
    int n, x;
    cin>>n>>x;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"ans : "<<lastIndex(arr, n, x)<<endl;
    cout<<"ans : "<<lastIndex(arr, n, x)<<endl;
}