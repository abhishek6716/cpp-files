#include<iostream>
using namespace std;

int duplicateNo(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(i!=j){
                if(arr[i]==arr[j]){
                    return arr[i];
                    break;
                }
            }
        }
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int size; cin>>size;
        int* input=new int[size];
        for(int i=0; i<size; ++i){
            cin>>input[i];
        }
        cout<<duplicateNo(input, size)<<endl;
    }
    return 0;
}