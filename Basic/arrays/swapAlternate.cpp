#include<iostream>
using namespace std;

void swapAlternate(int arr[], int size){
    for(int i=0; i<size-1; i=i+2){
        int temp;
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        int size; cin>>size;
        int* arr= new int[size];
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        swapAlternate(arr, size);
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        delete [] arr;
    }
}