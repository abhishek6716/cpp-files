#include<iostream>
using namespace std;


void printSubsetOfArrayHelper(int input[], int size, int output[], int oSize, int startIndex){
    if(startIndex==size){
        for(int i=0; i<oSize; i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    int smallOutput[40], smallOutputSize=0;
    printSubsetOfArrayHelper(input, size, output, oSize, startIndex+1);

    int i;
    for(int i=0; i<oSize; i++){
        smallOutput[i]=output[i];
    }
    smallOutput[i]=input[startIndex];
    printSubsetOfArrayHelper(input, size, output, oSize+1, startIndex+1);
}
void printSubsetOfArray(int input[], int size){
    int output[1000];
    return printSubsetOfArrayHelper(input, size, output, 0, 0);
}