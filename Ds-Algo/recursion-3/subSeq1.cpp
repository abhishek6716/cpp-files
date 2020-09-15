#include<iostream>
using namespace std;

int SubSequence(string input, string output[]){
    if(input.empty()){
        output[0]="";
        return 1;
    }
    string smallString=input.substr(1);
    int smallOutputSize=SubSequence(smallString, output);
    for(int i=0; i<smallOutputSize; i++){
        output[i+smallOutputSize]=input[0]+output[i];
    }
    return 2*smallOutputSize;
}
int main(){
    string input;
    cin>>input;
    string* output=new string[100];
    int cnt=SubSequence(input, output);
    for(int i=0; i<cnt; i++){
        cout<<output[i]<<endl;
    }
}