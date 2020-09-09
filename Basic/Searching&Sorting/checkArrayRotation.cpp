#include<iostream>
using namespace std;

// 5 6 1 2 3 4
//output->2
int FindSortedArrayRotation(int arr[], int n){
    for(int i=0; i<n+1; i++){
        if(arr[i]>arr[i+1]){
            return i+1;
        }
    }
}