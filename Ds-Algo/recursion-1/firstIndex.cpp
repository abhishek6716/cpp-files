#include<iostream>
using namespace std;

int firstIndex(int arr[], int n, int x){
    if(n==1){
        if(arr[0]==x){
            return 0;
        } else{
            return -1;
        }
    }
    int ans=firstIndex(arr+1, n-1, x);
    if(ans==-1){
        if(arr[0]==x){
            return 0;
        } else{
            return -1;
        }
    } else{
        if(arr[0]==x){
            return 0;
        } else{
            return ans+1;
        }
    }
}
int main(){
    int arr[100];
    int n, x;
    cin>>n>>x;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"ans : "<<firstIndex(arr, n, x);
}