#include<iostream>
using namespace std;

int Duplicate2(int arr[], int n){
    int duplicate=0;
    for(int i=1; i<=n-2; ++i){
        duplicate=duplicate^i;
    }
    for(int i=0; i<n; ++i){
        duplicate=duplicate^arr[i];
    }
    return duplicate;
}

int Duplicate1(int arr[], int n){
    int sum1=0;
    for(int i=0; i<n; i++){
        sum1=sum1+arr[i];
    }
    n=n-1;
    int sum2=(n*(n-1))/2;
    int duplicate=sum1-sum2;
    return duplicate;
}
int main(){
    int arr[1000];
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<Duplicate1(arr, n)<<endl;
    cout<<Duplicate2(arr, n);
}