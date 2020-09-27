// not using any expicit stack or queue

#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q){
    if(q.size()<=1){
        return;
    }
    int front=q.front();
    q.pop();
    reverseQueue(q);
    q.push(front);
}