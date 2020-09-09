#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
        if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
      }
    }
}
int main(){
    int input[]={2,5,1,9,3,8};
    BubbleSort(input, 6);
    for(int i=0; i<6; i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
}