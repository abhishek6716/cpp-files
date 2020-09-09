#include<iostream>
using namespace std;

void TrimSpaces(char input[]){
    int i=0, j=0;
    while(input[i]!='\n'){
        if(input[i]!=' '){
            input[j]=input[i];
            j++;
            i++;
        }
        else{
            i++;
        }
    }
}