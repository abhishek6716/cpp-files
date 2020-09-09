#include<iostream>
using namespace std;

void ReplaceCharacter(char a[], char c1, char c2){
    for(int i=0; a[i]!='\0'; i++){
        if(a[i]==c1){
            a[i]=c2;
        }
    }
}