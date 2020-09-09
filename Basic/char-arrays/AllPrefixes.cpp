#include<iostream>
using namespace std;

void AllPrefixes(char input[]){
    // i represents ending index
    for(int i=0; input[i]!='\0'; i++){
        // j represents starting index
        for(int j=0; j<=i; j++){
            cout<<input[j];
        }
        cout<<endl;
    }
}
