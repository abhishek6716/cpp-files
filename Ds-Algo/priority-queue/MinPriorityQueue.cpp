#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class minPriorityQueue{
    private:
    vector<int> pq;

    public:
    minPriorityQueue(){

    }

    bool isEmpty(){                                                            // Is empty
        return pq.size()==0;
    }

    int getSize(){                                                             // get size
        return pq.size();
    }

    int getMin(){                                                              // get min
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }

    void insert(int element){                                                  // insert
        pq.push_back(element);
        int childIndex=pq.size()-1;
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;
            if(pq[parentIndex]>pq[childIndex]){
                int temp=pq[childIndex];
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=temp;
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
    }

    int removeMin(){                                                           // remove
        if(pq.size()==0){
            return INT_MAX;
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int PI=0;
        int LCI=2*PI+1;
        int RCI=2*PI+2;
        while(LCI<pq.size()){
            int minI=PI;
            if(pq[minI]>pq[LCI]){
                minI=LCI;
            }
            if(RCI<pq.size() && pq[minI]>pq[RCI]){
                minI=RCI;
            }
            if(minI==PI){
                break;
            }
            int temp=pq[minI];
            pq[minI]=pq[PI];
            pq[PI]=temp;

            PI=minI;
            LCI=2*PI+1;
            RCI=2*PI+2;
        }
        return ans;
    }
};

int main(){
    minPriorityQueue pq;
    pq.insert(10);
    pq.insert(100);
    pq.insert(37);
    pq.insert(29);
    pq.insert(99);
    pq.insert(68);

    cout<<pq.getSize()<<endl;
    cout<<pq.getMin()<<endl;
    while(!pq.isEmpty()){
        cout<<pq.removeMin()<<" ";
    }
    cout<<endl;
    cout<<pq.getSize();
}
