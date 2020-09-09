// input-> hi abhishek
// remove all occurences of character i
// output-> h abhshek

#include<iostream>
using namespace std;

void RemoveAllOccurencesOfChar(char input[], char c){
    int nextIndex=0; 
    for(int i=0; input[i]!='\0'; i++){
        if(input[i]!=c){
            input[nextIndex++]=input[i];
        }
    }
    input[nextIndex]='\0';
}
