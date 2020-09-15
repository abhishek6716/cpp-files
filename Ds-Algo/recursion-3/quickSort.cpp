#include<iostream>
using namespace std;
int partitionArray(int input[], int start, int end){
    int pivot=input[start];
    int count=0;
    for(int i=start+1; i<=end; i++){
        if(input[i]<=pivot){
            count++;
        }
    }
    int pivotIndex=start+count;
    int temp=input[start];
    input[start]=input[pivotIndex];
    input[pivotIndex]=temp;

    int i=start, j=end;
    while(i<=pivotIndex && j>=pivotIndex){
        while(input[i]<=pivot){
            i++;
        }
        while(input[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            int temp=input[i];
            input[i]=input[j];
            input[j]=temp;
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void quickSort(int input[], int start, int end){
    if(start>=end){
        return;
    }
    int pivotIndex=partitionArray(input, start, end);
    quickSort(input, start, pivotIndex-1);
    quickSort(input, pivotIndex+1, end);
}
void quickSort(int input[], int n){
    quickSort(input, 0, n-1);
}
/*
void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}

int partition( int input[],int s,int e)
{
    int x=input[e];
    int i=s-1;
    for(int j=s;j<=e-1;j++) 
    {
        if(input[j]<=x){
            i++;
            swap(&input[i],&input[j]);
        } }
    swap(&input[i+1],&input[e]);
        return(i+1);
}

void quicksorting(int input[],int s,int e)
{
    if(s<e)
    {
    int q=partition(input,s,e);
    quicksorting(input,s,q-1);
    quicksorting(input,q+1,e);
}
}

void quickSort(int input[], int size) {
  quicksorting(input,0,size-1); 
}
*/