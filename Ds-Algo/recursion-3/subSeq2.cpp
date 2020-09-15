#include<iostream>
#include<string>
using namespace std;

void printSubSeq(string input, string output){
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }
    printSubSeq(input.substr(1), output);
    printSubSeq(input.substr(1), output+input[0]);
}
int main(){
    string input;
    cin>>input;
    string output="";
    printSubSeq(input, output);
}