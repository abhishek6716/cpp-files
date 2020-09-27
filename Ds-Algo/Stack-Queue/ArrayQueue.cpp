#include<iostream>
using namespace std;

template<typename T>
class QueueUsingArray{
    private:
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    QueueUsingArray(int s){                                                    // constructor
        data=new T[s];
        nextIndex=0;
        firstIndex=-1;
        size=0;
        capacity=s;
    }

    int getSize(){                                                             // size of queue
        return size;
    }

    bool isEmpty(){                                                            // is empty
        return size==0;
    }

    void enqueue(T element){                                                   // enqueue dynamic
        if(size==capacity){
            T *newdata=new T[2*capacity];
            int j=0;
            for(int i=firstIndex; i<capacity; i++){
                newdata[j]=data[i];
                j++;
            }
            for(int i=0; i<nextIndex-1; i++){
                newdata[j]=data[i];
                j++;
            }
            delete data[];
            data=newdata;
            firstIndex=0;
            nextIndex=capacity;
            capacity=capacity*2;
        }
        data[nextIndex]=element;
        nextIndex=(nextIndex+1)%capacity;
        if(firstIndex==-1){
            firstIndex=0;
        }
        size++;
    }
    /*
    void enqueue(T element){                                                   // enqueue
        if(size==capacity){
            cout<<"queue is full"<<endl;
            return; 
        }
        data[nextIndex]=element;
        nextIndex=(nextIndex+1)%capacity;
        if(firstIndex==-1){
            firstIndex=0;
        }
        size++;
    }
    */

    T front(){                                                                 // front
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue(){                                                               // dequeue
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        T ans=data[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        size--;
        if(size==0){
            firstIndex=-1;
            nextIndex=0;
        }
        return ans;
    }
};

int main(){
    QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
}