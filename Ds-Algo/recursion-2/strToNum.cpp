#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int helper(char input[], int last){
    if(last==0){
        return input[last]-'0';
    }
    int smallAns=helper(input, last-1);
    int a=input[last]-'0';
    return smallAns*10+a;
}
int StringToNum_2(char input[]){
    int len=strlen(input);
    return helper(input, len-1);
}



int StringToNumber(char input[]){
    int n=strlen(input);
    if(n==1){
        int a=input[0]-'0';
        return a;
    }
    int y=StringToNumber(input+1);
    int x=input[0]-'0';
    x=x*pow(10, n-1)+y;
    return x;
}