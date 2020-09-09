#include<iostream>
using namespace std;

void RemoveConsecutiveDuplicates(char input[]){
    int nextIndex=1; 
    char lastChar=input[0];

    for(int i=0; input[i]!='\0';){
        if(input[i]==lastChar){
            i++;
        }
        else{
            input[nextIndex]=input[i];
            nextIndex++;
            lastChar=input[i];
            i++;
        }
    }
    input[nextIndex]='\0';
}