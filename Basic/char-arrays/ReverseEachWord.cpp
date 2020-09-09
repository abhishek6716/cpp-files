#include<iostream>
using namespace std;

// input-> hi abhishek
// output-> kehsihba ih
void reverse(char input[], int start, int end){
    int i=start, j=end;
    while(i<j){
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i++;
        j--;
    }
}

void ReverseEachWord(char input[]){
    int previousSpaceIndex=-1;
    int i=0; 
    for(; input[i]!='\0'; i++){
        if(input[i]==' '){
            reverse(input, previousSpaceIndex+1, i-1);
            previousSpaceIndex=i;
        }
    }
    reverse(input, previousSpaceIndex+1, i-1);
}