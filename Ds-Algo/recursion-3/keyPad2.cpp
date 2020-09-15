#include<iostream>
using namespace std;

string getstring(int d){
    if(d==2){
        return "abc";
    }
    if(d==3){
        return "def";
    }
    if(d==4){
        return "ghi";
    }
    if(d==5){
        return "jkl";
    }
    if(d==6){
        return "mno";
    }
    if(d==7){
        return "pqrs";
    }
    if(d==8){
        return "tuv";
    }
    if(d==9){
        return "wxyz";
    }
    return " ";
}
void PrintKeypad(int n, string outputSoFar){
    if(n==0){
        cout<<outputSoFar<<endl;
        return;
    }
    int lastDigit=n%10;
    int smallNo=n/10;
    string options=getstring(lastDigit);
    for(int i=0; i<options.size(); i++){
        PrintKeypad(smallNo, options[i]+outputSoFar);
    }
}
int main(){
    int n;
    cin >> n;
    PrintKeypad(n, "");
}