#include<iostream>
using namespace std;

bool checkAB_helper(char input[], int startIndex){
    if(input[startIndex]=='\0'){
        return true;
    }
    if(input[startIndex]!='a'){
        return false;
    }
    if(input[startIndex+1]!='\0' && input[startIndex+2]!='\0'){
        if(input[startIndex+1]=='b' && input[startIndex+2]=='\b'){
            return checkAB_helper(input, startIndex+3);
        }
    }
    return checkAB_helper(input, startIndex+1);
}
bool checkAB(char input[]){
    bool ans;
    ans=checkAB_helper(input, ans);
    return ans;
}