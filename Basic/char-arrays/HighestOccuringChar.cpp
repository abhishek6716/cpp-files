//input-> aaaaabbccd
//output-> a
#include<iostream>
using namespace std;

char highestOccuringChar(char input[]){
    int freq[256]={0};
    int maxFreq=-1;
    for(int i=0; input[i]!='\0'; i++){
        freq[input[i]]++;
        maxFreq=std::max(maxFreq, freq[input[i]]);
    }
    char res;
    for(int i=0; input[i]!='\0'; i++){
        if(freq[input[i]]==maxFreq){
            res=input[i];
            break;
        }
    }
    return res;
}