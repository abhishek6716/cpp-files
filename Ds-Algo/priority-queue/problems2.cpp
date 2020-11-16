#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;

bool isMaxHeap(int arr[], int n){                                              // is heap
    for(int i=0; i<n; i++){
        int LCI=2*i+1;
        int RCI=2*i+2;
        if(LCI<n && arr[i]<arr[LCI]){
            return false;
        }
        if(RCI<n && arr[i]<arr[RCI]){
            return false;
        }
    }
    return true;
}

int kthLargest(vector<int> arr, int n, int k){                                 // kth largest
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    for(int i=k; i<n; i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

vector<int> mergeKsortedArrays(vector<vector<int>*> input){                    // merge k sorted arrays
    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<input.size(); i++){
        for(int j=0; j<input[i]->size(); j++){
            pq.push(input[i]->at(j));
        }
    }
    while(!pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }
    return v; 
}

void findMedian(int arr[], int n){                                             // find median
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    for(int i=0; i<n; i++){
        if(maxHeap.size() && arr[i]>maxHeap.top()){
            minHeap.push(arr[i]);
        }
        else{
            maxHeap.push(arr[i]);
        }
        if(abs((int)maxHeap.size()-(int)minHeap.size())>1){
            if(maxHeap.size()>minHeap.size()){
                int temp=maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
            }
            else{
                int temp=minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
            }
        }
        int median;
        int totalSize=maxHeap.size()+minHeap.size();
        if(totalSize%2==1){
            if(maxHeap.size()>minHeap.size()){
                median=maxHeap.top();
            }
            else{
                median=minHeap.top();
            }
        }
        else{
            median=0;
            if(maxHeap.empty()==false){
                median=median+maxHeap.top();
            }
            if(minHeap.empty()==false){
                median=median+minHeap.top();
            }
            median=median/2;
        }
        cout<<median<<endl;
    }
}

int buyTicket(int *input, int n, int k){                                       // buy ticket
    queue<int> q;
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        q.push(input[i]);
        pq.push(input[i]);
    }
    int cnt=0;
    while(!pq.empty()){
        if(q.front()==pq.top()){
            if(k==0){
                return cnt+1;
            }
            else{
                cnt++;
                q.pop();
                pq.pop();
                k--;
            }
        }
        else{
            q.push(q.front());
            q.pop();
            if(k==0){
                k=q.size()-1;
            }
            else{
                k--;
            }
        }
    }
    return cnt;
}
