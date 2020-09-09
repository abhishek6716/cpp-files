//array must be sorted
#include<iostream>
using namespace std;

int BinarySearch(int input[], int n, int x){
    int s=0, e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(input[mid]==x){
            return mid;
        }
        else if(input[mid]>x){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}

int main(){
    int n; cin>>n;
    int input[100];
    for(int i=0; i<n; i++){
        cin>>input[i];
    }
    int x; cin>>x;
    cout<<BinarySearch(input, n, x)<<endl;
}