#include<iostream>
using namespace std;

// recursion first method in strings
void RemoveDuplicate(char input[]){
    if(input[0]=='\0'){
        return;
    }
    RemoveDuplicate(input+1);
    if(input[0]==input[1]){
        int i=1;
        for(; input[i]!='\0'; i++){
            input[i-1]=input[i];
        }
        input[i-1]='\0';
    }
}
int main(){
    char str[100];
    cin>>str;
    RemoveDuplicate(str);
    cout<<str;
}