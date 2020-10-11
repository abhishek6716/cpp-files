#include<iostream>
#include<queue>
using namespace std;

void KsortedArray(int arr[], int n, int k){                // klog(k)
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    int j=0;
    for(int i=k; i<n; i++){                                // (n-k)log(k)    
        arr[j]=pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }
    while(!pq.empty()){                                    // klog(k)
        arr[j]=pq.top();
        pq.pop();
        j++;
    }
}

int main(){
    int arr[]={10,12,15,6,9};
    int k=3;
    KsortedArray(arr, 10, k);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
/*
 overall complexity (n+k)log(k)
 if n>>k
 complexity becomes o(n)
*/
