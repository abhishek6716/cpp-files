#include<iostream>
#include<climits>
using namespace std;

template<typename T>
class StackUsingArray{                                                         // generic stack class
    private:
    T *data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArray(){                                                         // constructor for dynamic stack
        data=new T[5];
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

    void push(T element){                                                    // push element dynamic
        if(nextIndex==capacity){
            T *newData=new T[2*capacity];
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

    T pop(){                                                                 // pop element
        if(IsEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top(){                                                                 // top element
        if(IsEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};


template<typename P, typename Q>                                               // pair class
class Pair{
    private:
    P x;
    Q y;

    public:

    void setX(P x){
        this->x=x;
    }

    P getX(){
        return x;
    }

    void setY(Q y){
        this->y=y;
    }

    Q getY(){
        return y;
    }
};

int main(){
    StackUsingArray<char> s;
     s.push(100);
     s.push(101);
     s.push(102);
     s.push(103);
     s.push(104);
     s.push(105);

     cout<<s.top()<<endl;
     cout<<s.pop()<<endl;
     cout<<s.pop()<<endl;
     cout<<s.pop()<<endl;
     cout<<s.pop()<<endl;

     cout<<s.size()<<endl;
     cout<<s.IsEmpty()<<endl;
     
    /*
    Pair<Pair<int, int>, int> p;
    Pair<int, int> p0;
    p0.setX(31);
    p0.setX(32);
    p.setX(p0);
    p.setY(201);
    cout<<p.getX().getX()<<" "<<p.getX().getY()<<" "<<p.getY()<<endl;
    */

    /*
    Pair<int, double> p;
    p.setX(100.01);
    p.setY(200);
    cout<<p.getX()<<" "<<p.getY()<<endl;
    */

}