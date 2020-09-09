#include<iostream>
using namespace std;

void PushZeroesToEnd(int arr[], int size){
    int k=0;
    for(int i=0; i<size; i++){
        if(arr[i]!=0){
            arr[k]=arr[i];
            k++;
        }
    }
    for(int i=k; i<size; i++){
        arr[i]=0;
    }
}