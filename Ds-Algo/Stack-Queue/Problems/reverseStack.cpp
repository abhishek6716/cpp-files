#include<iostream>
#include<stack>
using namespace std;

/*
using two stacks (A) & (B)
input  stack(A) 1 2 3 4 5        5 is at top
output stack(A) 5 4 3 2 1        1 is at top
*/
// HINT: use implicit stack means recursion

void reverseStack(stack<int> &input, stack<int> &extra){
    if(input.size()<=1){
        return;
    }
    
    int lastElement=input.top();
    input.pop();

    reverseStack(input, extra);

    while(!input.empty()){
        int top=input.top();
        input.pop();
        extra.push(top);
    }
    
    input.push(lastElement);

    while(!extra.empty()){
        int top=extra.top();
        extra.pop();
        input.push(top);
    }
}
