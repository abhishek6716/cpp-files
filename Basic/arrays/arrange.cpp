#include<iostream>
using namespace std;

void arrange(int *arr, int n){
    int left=0;
    int right=n-1;
    int cnt=1;
    while(left<=right){
        if(cnt%2==1){
            arr[left]=cnt;
            cnt++;
            left++;
        }
        else{
            arr[right]=cnt;
            cnt++;
            right--;
        }
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int* arr=new int[n];
        arrange(arr, n);
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        delete [] arr;
    }
}