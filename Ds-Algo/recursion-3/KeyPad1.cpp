#include<iostream>
#include<string>
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
int keypad(int num, string output[])
{
    if(num==0){
        output[0]="";
        return 1;
    }
    int lastno=num%10;
    int smallno=num/10;
    int smalloutputsize=keypad(smallno,output);

    string option=getstring(lastno);

    for(int i=0;i<option.length()-1;i++)
    {
        for(int j=0;j<smalloutputsize;j++)
        {
            output[j+(i+1)*smalloutputsize]=output[j];
        }
    }
    int k=0;
    for(int i=0;i<option.length();i++){
        for(int j=0;j<smalloutputsize;j++)
        {
            output[k]=output[k]+option[i];
            k++;
        }
    }
    return smalloutputsize*option.length();
}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

/*
int keypad_helper(int num, string output[], string options[]){
    if(num==0){
        output[0]="";
        return 1;
    }
    int lastDigit=num%10;
    int smallNumber=num/10;
    string smallOutput[500];

    int smallCount=keypad_helper(smallNumber, smallOutput, options);
    string op=options[lastDigit];

    int k=0;
    for(int i=0; i<op.length(); i++){
        for(int j=0; j<smallCount; j++){
            output[k]=smallOutput[j]+op[i];
            k++;
        }
    }
    return k;
}
int Keypad(int num, string output[]){
    string options[]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return keypad_helper(num, output, options);
}
*/