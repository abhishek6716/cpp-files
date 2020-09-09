#include<iostream>
using namespace std;

int charlength(char a[]){
    int cnt=0;
    for(int i=0; a[i]!='\0'; i++){
        cnt++;
    }
    return cnt;
}

int main(){
    char a[100];
    cin>>a;
    cout<<charlength(a);
}