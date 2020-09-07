#include<iostream>
using namespace std;

int main(){
    char ch;
    ch=cin.get();
    int cnt=0, i=0, j=0;
    while(ch!='$'){
        if('a'<=ch && ch<='z'){
            i++;
        }
        if('0'<=ch && ch<='9'){
            j++;
        }
        ch=cin.get();
        cnt++;
    }
    cout<<i<<" "<<j<<" "<<cnt-(i+j);
}