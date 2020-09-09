#include<iostream>
using namespace std;

void MergeTwoArrays(int arr1[], int size1, int arr2[], int size2, int ans[]){
    int i=0; int j=0; int k=0;
    while(i<size1 && j<size2){
        if(arr1[i]>arr2[j]){
            ans[k]=arr2[j];
            j++;
            k++;
        }
        else{
            ans[k]=arr1[i];
            i++;
            k++;
        }
        
    } 
    if(i<size1){
        for(; i<size1; i++){
            ans[k]=arr1[i];
            k++;
        }
    }
    if(j<size2){
        for(; j<size2; j++){
            ans[k]=arr2[j];
            k++;
        }
    }
}