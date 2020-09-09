// "xxxxx" -> "x5"
// "aaabbcccdd" -> "a3b2c3d2"

#include<iostream>
using namespace std;

string stringCompression(string inputString){
    if(inputString.length()==0){
        return "";
    }
    string output="";
    output=output+inputString[0];
    int cnt=1;
    for(int i=1; i<inputString.length(); i++){
        if(inputString[i]==inputString[i-1]){
            cnt++;
            if(i==inputString.length()-1){
                output=output+to_string(cnt);
            }
        }
        else{
            if(cnt>1){
                output=output+to_string(cnt);
                output=output+inputString[i];
            }
            else{
                output=output+inputString[i];
            }
            cnt=1;
        }
    }
    return output;
}