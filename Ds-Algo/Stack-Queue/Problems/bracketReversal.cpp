#include<iostream>
#include<stack>
using namespace std;

int countBracketReversal(string input){
    int len=input.length();
    if(len==0){
        return 0;
    }
    if(len%2!=0){
        return -1;
    }
    stack<int> stack;
    for(int i=0; i<len; i++){
        char currentChar=input[i];
        if(currentChar='{'){
            stack.push(currentChar);
        }
        else{
            // pop if their is balanced pair
            if(!stack.empty() && stack.top()=='{'){
                stack.pop();
            }
            else{
                stack.push(currentChar);
            }
        }
    }
    int cnt=0;
    // only balanced brackets are their in stack now
    while(!stack.empty()){
        char ch1=stack.top();
        stack.pop();
        char ch2=stack.top();
        stack.pop();
        // when ch1=} and ch2={, then we need to reverse both of them
        // so cnt will increase by 2
        if(ch1!=ch2){
            cnt=cnt+2;
        }
        else{
            cnt=cnt+1;
        }
    }
    return cnt;
}