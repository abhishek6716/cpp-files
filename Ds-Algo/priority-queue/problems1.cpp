#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> kSmallest(int *input, int n, int k){                     // k smallest elements
    priority_queue<int> pq;
    vector<int> output;
    int i;
    for(i=0; i<k; i++){
        pq.push(input[i]);
    }
    for(; i<n; i++){
        if(input[i]<pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }
    while(!pq.empty()){
        output.push_back(pq.top());
        pq.pop();
    }
    return output;
}

vector<int> kLargest(int *input, int n, int k){                      // k largest elements
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> output;
    int i;
    for(i=0; i<k; i++){
        pq.push(input[i]);
    }
    for(; i<n; i++){
        if(input[i]>pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }
    while(!pq.empty()){
        output.push_back(pq.top());
        pq.pop();
    }
    return output;
}

int main(){
    int input[]={2,4,5,1,3,9,8,7,6,10};
    int k=3;
    vector<int> output1=kSmallest(input, 10, k);
    for(int i=0; i<output1.size(); i++){
        cout<<output1[i]<<" ";
    }
    cout<<endl;
    vector<int> output2=kLargest(input, 10, k);
    for(int i=0; i<output2.size(); i++){
        cout<<output2[i]<<" ";
    }
    cout<<endl;
}