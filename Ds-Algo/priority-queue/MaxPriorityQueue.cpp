#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class maxPriorityQueue{
    private:
    vector<int> pq;

    public:
    maxPriorityQueue(){

    }

    bool isEmpty(){                                                            // Is empty
        return pq.size()==0;
    }

    int getsize(){                                                             // get size
        return pq.size();
    }

    int getMax(){                                                              // get max
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }

    void insert(int element){                                                  // insert
        pq.push_back(element);
        int CI=pq.size()-1;
        while(CI>0){
            int PI=(CI-1)/2;
            if(pq[PI]<pq[CI]){
               int temp=pq[CI];
               pq[CI]=pq[PI];
               pq[PI]=temp;
            }
            else{
                break;
            }
            CI=PI;
        }
    }

    int removeMax(){                                                           // remove max
        if(isEmpty()){
            return INT_MIN;
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int PI=0;
        int LCI=2*PI+1;
        int RCI=2*PI+2;
        while(LCI<pq.size()){
            int maxI=PI;
            if(pq[maxI]<pq[LCI]){
                maxI=LCI;
            }
            if(RCI<pq.size() && pq[maxI]<pq[RCI]){
                maxI=RCI;
            }
            if(maxI==PI){
                break;
            }
            int temp=pq[maxI];
            pq[maxI]=pq[PI];
            pq[PI]=temp;

            PI=maxI;
            LCI=2*PI+1;
            RCI=2*PI+2;
        }
        return ans;
    }
};

int main(){
    maxPriorityQueue pq;
    pq.insert(10);
    pq.insert(100);
    pq.insert(37);
    pq.insert(29);
    pq.insert(99);
    pq.insert(68);

    cout<<pq.getsize()<<endl;
    cout<<pq.getMax()<<endl;
    while(!pq.isEmpty()){
        cout<<pq.removeMax()<<" ";
    }
    cout<<endl;
    cout<<pq.getsize();
}