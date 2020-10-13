#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int *input, int n){
    unordered_map<int, bool> map;
    vector<int> output;
    for(int i=0; i<n; i++){
        if(map.count(input[i])>0){
            continue;
        }
        else{
            map[input[i]]==true;
            output.push_back(input[i]);
        }
    }
    return output;
}

int main(){
    int input[]={1,2,3,4,5,6,7,4,3,2,8,7,9,12};
    vector<int> output=removeDuplicates(input, 14);
    for(int i=0; i<output.size(); i++){
        cout<<output[i]<<" ";
    }
}