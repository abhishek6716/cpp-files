#include<iostream>
#include<unordered_map>
using namespace std;

void pairSum1(int *input, int n){
    unordered_map<int, int> map;
    // initialising map with 1
    for(int i=0; i<n; i++){
        map[input[i]]++;
    }
    for(int i=0; i<n; i++){
        int f1=map[input[i]];
        int f2=map[-input[i]];
        for(int j=0; j<f1*f2; j++){
            if(input[i] < -input[i]){
                cout<<input[i]<<" "<<-input[i]<<endl;
            } else{
                cout<<-input[i]<<" "<<input[i]<<endl;
            }
        }
        map.erase(input[i]);
    }
}

void pairSum2(int *input, int n){
    unordered_map<int, int> map;
    for(int i=0; i<n; i++){
        int comp=-input[i];
        if(map.find(comp)!=map.end()){
            int cnt=map[comp];
            while(cnt--){
                cout<<min(input[i], comp)<<" "<<max(input[i], comp)<<endl;
            }
        }
        ++map[input[i]];
    }
}