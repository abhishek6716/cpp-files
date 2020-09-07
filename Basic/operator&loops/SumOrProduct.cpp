#include<iostream>
using namespace std;

int main(){
    int n, i=0, sum=0, choice, mul=1;
    cin>>n;
    cin>>choice;
    if(choice==1){
        while(i<=n){
            sum=sum+1;
            i++;
        }
        cout<<sum;
    }
    else if(choice==2){
        while(i<=n){
            mul=mul*1;
            i++;
        }
        cout<<mul;
    }
    else{
        cout<<"-1";
    }
}