#include<iostream>
#include<string.h>
using namespace std;


void PrintAllPossibleCodes_helper(string input, string output){
    if(input[0]=='\0'){
        cout<<output<<endl;
        return;
    }
    int num=input[0]-48;
    char ch=num-1+'a';
    PrintAllPossibleCodes_helper(input.substr(1), output+ch);
    if(input[1]!='\0'){
        num=num*10+input[1]-48;
        ch=num-1+'a';
        if(num>=10 && num<=26){
            PrintAllPossibleCodes_helper(input.substr(2), output+ch);
        }
    }
}
void PrintAllPossibleCodes(string input){
    PrintAllPossibleCodes_helper(input, "");
}