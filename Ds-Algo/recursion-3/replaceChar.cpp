#include<iostream>
using namespace std;

void ReplaceChar(char input[], char c1, char c2){
    if(input[0]=='\0'){
        return;
    }
    if(input[0]==c1){
        input[0]=c2;
        ReplaceChar(input+1, c1, c2);
    } else{
        ReplaceChar(input+1, c1, c2);
    }
}
int main(){
    char str[100];
    char c1, c2;
    cin>>c1>>c2;
    cin>>str;
    ReplaceChar(str, c1, c2);
    cout<<str<<endl;
}