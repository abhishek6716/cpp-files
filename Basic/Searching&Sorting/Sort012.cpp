#include<iostream>
using namespace std;

void Sort012(int arr[], int n){
    int cnt1,cnt2,cnt3;
    cnt1=cnt2=cnt3=0;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            cnt1++;
        }
        if(arr[i]==1){
            cnt2++;
        }
        if(arr[i]==2){
            cnt3++;
        }

    }
    int i=0;
    for(; i<cnt1; i++){
        arr[i]=0;
    }
    for(; i<cnt2+cnt1; i++){
        arr[i]=1;
    }
    for(; i<cnt3+cnt1+cnt2; i++){
        arr[i]=2;
    }
}

void Sort012(int *arr, int n){
    int i=0; 
    int nextZero=0;
    int nextTwo=n-1;
    while(i<=nextTwo){
        if(arr[i]==0){
            int temp=arr[i];
            arr[i]=arr[nextZero];
            arr[nextZero]=temp;
            i++;
            nextZero++;
        }
        else if(arr[i]==2){
            int temp=arr[i];
            arr[i]=arr[nextTwo];
            arr[nextTwo]=temp;
            nextTwo--;
        }
        else{
            i++;
        }
    }
}