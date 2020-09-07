#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<j<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl;

    int k=1;
    i=1;
    while(i<=n){                                      
        int j=1;                                      
        while(j<=i){
            cout<<k<<" ";
            k++;
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl;

    i=1;
    while(i<=n){
        int j=0;
        while(j<i){
            cout<<j+i<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl;

    i=1;
    while(i<=n){
        int j=0;
        int k=1;
        while(k<=n-i){
            cout<<" ";
            k++;
        }
        while(j<i){
            cout<<j+i;
            j++;
        }
        cout<<endl;
        i++;
    }

}