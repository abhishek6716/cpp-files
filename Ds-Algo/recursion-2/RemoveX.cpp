#include<iostream>
#include<cstring>
using namespace std;

void helper_2(char input[], int start){                              // Doing work after recursive call
    if(input[start]=='\0'){
        return;
    }
    helper_2(input, start+1);
    if(input[start]=='x'){
        int len=strlen(input);
        int i;
        for(i=start+1; i<len; i++){
            input[i-1]=input[i];
        }
        input[i-1]='\0';
    }
}
void RemoveX_2(char input[]){
    helper_2(input, 0);
}

char helper(char input[],char key){                                  // Doing work before recursive call
    if(input[0]=='\0'){
        return 0;
    }
    if(input[0]==key){
        int i=1;
        for(; input[i]!='\0'; i++){
            input[i-1]=input[i];
        }
        input[i-1]=input[i];
        return helper(input, key);
    }else{
        return helper(input+1, key);
    }
}
void RemoveX(char input[]){
    helper(input, 'x');
}

int main(){
    char input[100];
    cin>>input;
    RemoveX_2(input);
    cout<<input;
}