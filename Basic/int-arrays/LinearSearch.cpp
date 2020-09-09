#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int val){
    int i=0; 
    while(i<n){
        if(arr[i]==val){
            return i;
        }
        i++;
    }
    return -1;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0; i<n; ++i){
            cin>>arr[i];
        }
        int val;
        cin>>val;
        cout<<linearSearch(arr, n, val)<<endl;
    }
    return 0;
}