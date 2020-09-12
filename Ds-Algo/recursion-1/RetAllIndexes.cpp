#include<iostream>
using namespace std;
// backward
int RetAllIndexes2(int arr[], int n, int x, int output[]){
    if(n==0){
        return 0;
    }
    int ans=RetAllIndexes2(arr, n-1, x, output);
    if(arr[n-1]==x){
        int res=ans+1;
        output[res-1]=n-1;
        return res;
    } else{
        return ans;
    }
}
// forward
int RetAllIndexes(int arr[], int n, int x, int output[]){
    if(n==0){
        return 0;
    }
    int ans=RetAllIndexes(arr+1, n-1, x, output);
    for(int i=0; i<ans; i++){
        output[i]=output[i]+1;
    }
    if(arr[0]==x){
        int res=ans+1;
        for(int i=res-1; i>=1; i--){
            output[i]=output[i-1];
        }
        output[0]=0;
        return res;
    } else{
        return ans;
    }
}
int main(){
    int arr[100], output[100];
    int n, x;
    cin>>n>>x;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int a=RetAllIndexes(arr, n, x, output);
    cout<<"no of repetition: "<<a<<endl;
    for(int i=0; i<a; i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
    int b=RetAllIndexes2(arr, n, x, output);
    cout<<"no of repetition: "<<a<<endl;
    for(int i=0; i<b; i++){
        cout<<output[i]<<" ";
    }
    
}