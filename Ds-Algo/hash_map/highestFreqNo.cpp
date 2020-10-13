#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int highestFreqNo(int *input, int n){
    vector<int> v;
    unordered_map<int, int> map;
    for(int i=0; i<n; i++){
        if(map.count(input[i])>0){
            map[input[i]]++;
        }
        else{
            map[input[i]]=1;
        }
    }
    int max=map[input[0]];
    int ans=input[0];
    int j=1;
    while(j<n){
        if(map[input[j]]>max){
            max=map[input[j]];
            ans=input[j];
        }
        j++;
    }
    return ans;
}