#include<iostream>
#include<climits>
using namespace std;

class StackUsingArray{
    private:
    int *data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArray(){                                                         // constructor for dynamic stack
        data=new int[5];
        nextIndex=0;
        capacity=5;
    }
    /*
    StackUsingArray(int totalSize){                                            // constructor for static stack
        data=new int[totalSize];
        nextIndex=0;
        capacity=totalSize;
    }
    */

    int size(){                                                                // size of stack
        return nextIndex;
    }

    bool IsEmpty(){                                                            // is empty
        return nextIndex==0;
    }

    void push(int element){                                                    // push element dynamic
        if(nextIndex==capacity){
            int *newData=new int[2*capacity];
            for(int i=0; i<capacity; i++){
                newData[i]=data[i];
            }
            capacity=capacity*2;
            delete[] data;
            data=newData;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    /*
    void push(int element){                                                    // push element static
        if(nextIndex==capacity){
            cout<<"stack is full"<<endl;
            return;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    */

    int pop(){                                                                 // pop element
        if(IsEmpty()){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){                                                                 // top element
        if(IsEmpty()){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};
 int main(){
     StackUsingArray s;
     s.push(100);
     s.push(200);
     s.push(300);
     s.push(400);
     s.push(500);
     s.push(600);

     cout<<s.top()<<endl;
     cout<<s.pop()<<endl;
     cout<<s.pop()<<endl;
     cout<<s.pop()<<endl;
     cout<<s.pop()<<endl;

     cout<<s.size()<<endl;
     cout<<s.IsEmpty()<<endl;
 }