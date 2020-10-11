#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq;                           // by default it is max priority queue
    pq.push(99);
    pq.push(100);
    pq.push(56);
    pq.push(31);
    pq.push(88);
    cout<<"size: "<<pq.size()<<endl;
    cout<<"top: "<<pq.top()<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}