#include<iostream>
using namespace std;

void PrintPermutations_helper(string input, string output){
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }
    for(int i=0; i<=output.length(); i++){
        PrintPermutations_helper(input.substr(1), output.substr(0, i)+input[0]+output.substr(i));
    }
}
void PrintPermutations(string input){
    PrintPermutations_helper(input, "");
}