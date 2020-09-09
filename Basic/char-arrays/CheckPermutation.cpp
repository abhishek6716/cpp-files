#include<iostream>
using namespace std;

int length(char a[]){
    int cnt=0;
    for(int i=0; a[i]!='\0'; i++){
        cnt++;
    }
    return cnt;
}
bool isPermutation(char input1[], char input2[]){
    int len1=length(input1);
    int len2=length(input2);

    if(len1!=len2){
        return false;
    }
    int frequency[256];
    for(int i=0; i<256; i++){
        frequency[i]=0;
    }
    for(int i=0; i<len1; i++){
        frequency[input1[i]]++;
        frequency[input2[i]]--;
    }
    for(int i=0; i<256; i++){
        if(frequency[i]!=0){
            return false;
        }
    }
    return true;
}
