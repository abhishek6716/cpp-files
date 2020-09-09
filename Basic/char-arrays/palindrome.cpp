#include<iostream>
using namespace std;

bool CheckPalindrome(char a[]){
    int cnt=0;
    for(int i=0; a[i]!='\0'; i++){
        cnt++;
    }
    for(int i=0, j=cnt-1; i<j; i++, j--){
        if(a[i]!=a[j]){
            return false;
        }
    }
    return true;
}