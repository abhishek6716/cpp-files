#include<iostream>
using namespace std;

int charlength(char a[]){
    int cnt=0;
    for(int i=0; a[i]!='\0'; i++){
        cnt++;
    }
    return cnt;
}
void reverseString(char input[]){
    int len=charlength(input);
    int i=0, j=len-1;
    while(i<j){
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i++;
        j--;
    }
}
int main(){
    char input[100];
    cin.getline(input, 100);
    reverseString(input);
    cout<<input<<endl;
}