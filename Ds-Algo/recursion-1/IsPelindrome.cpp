#include<iostream>
#include<string>
using namespace std;

bool helper(char input[],int start,int end){
    if(end<=1){
        return true;
    }
    if(input[start]!=input[end]){
        return false;
    }
    bool ans=helper(input, start+1, end-1);
    if(ans){
        return true;
    } else{
        return false;
    }
}
bool Ispelindrome(char input[]){
    int len=0;
    for(int i=0; input[i]!='\0'; i++){
        len++;
    }
    cout<<len<<endl;
    return helper(input, 0, len-1);
}

int main(){
    char input[100];
    cin>>input;
    cout<<Ispelindrome(input);
}