#include<iostream>
using namespace std;

void merge(int input[], int si, int m, int ei){
    int i=si, j=m+1, k=0;
    int arr[ei-si+1];
    while(i<=m && j<=ei){
        if(input[i]>input[j]){
            arr[k]=input[j];
            j++;
            k++;
        }
        else{
            arr[k]=input[i];
            i++;
            k++;
        }
    }
    if(i<=m){
        for(; i<=m; i++){
            arr[k]=input[i];
            k++;
        }
    }
    if(j<=ei){
        for(; j<=ei; j++){
            arr[k]=input[j];
            k++;
        }
    }
    // copying back to real array
   int l=0;
    for(int i=si; i<=ei; i++ ){
        input[i]=arr[l];
        l++;
    }
    
}
void sorting(int input[], int si, int ei){
    if(si>=ei){
        return;
    }
    int m=(si+ei)/2;
    sorting(input, si, m);
    sorting(input, m+1, ei);
    merge(input, si, m, ei);
}
void mergeSort(int input[], int size){
	sorting(input, 0, size-1);    
}

int main(){
    int arr[100];
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergeSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}