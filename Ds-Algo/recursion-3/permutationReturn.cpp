#include<iostream>
#include<string.h>
using namespace std;

int ReturnPermutation(string input, string output[]){
    if(input[0]=='\0'){
        output[0]="";
        return 1;
    }
    string smallOutput[10000];
    int smallSize=ReturnPermutation(input.substr(1), smallOutput);
    int k=0;
    for(int i=0; i<smallSize; i++){
        for(int j=0; j<=smallOutput[i].length(); j++){
            output[k++]=smallOutput[i].substr(0, j)+input[0]+smallOutput[i].substr(j);
        }
    }
    return k;
}